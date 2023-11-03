//
// Created by rodri on 01/11/23.
//

#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <stdexcept>
#include <stack>
#include <map>
#include "Student.h"
#include "UC.h"
#include "Controller.h"
#include "Schedule.h"

using namespace std;
namespace uni {
    void Controller::parseDataStudent(const string &file) {
        ifstream fileStream(file);

        if (!fileStream.is_open()) {
            throw runtime_error("O ficheiro não abriu");
        }

        string line;
        getline(fileStream, line);

        while (getline(fileStream, line)) {
            istringstream iss(line);
            string StudentCode, StudentName, UcCode, ClassCode;

            if (getline(iss, StudentCode, ',') &&
                getline(iss, StudentName, ',') &&
                getline(iss, UcCode, ',') &&
                getline(iss, ClassCode, '\n')) {
                bool studentExists = false;
                for (auto &student : UNIStudents_) {
                    if (student.getStudentCode() == StudentCode) {
                        studentExists = true;
                        UC newUC(UcCode, ClassCode);
                        student.addCourseUnit(newUC);
                        ucStudentCount_[UcCode]++;
                        break;
                    }
                }
                if (!studentExists) {
                    UC newUC(UcCode, ClassCode);
                    list<UC> UCList;
                    UCList.push_back(newUC);
                    Student newStudent(StudentCode, StudentName, UCList);
                    UNIStudents_.push_back(newStudent);
                    ucStudentCount_[UcCode]=1;
                }
            } else {
                throw runtime_error("Erro na linha");
            }
        }
    }

    void Controller::parseDataClasses(const string &file) {
        ifstream fileStream(file);

        if (!fileStream.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        std::string line;
        getline(fileStream, line);

        while (getline(fileStream, line)) {
            std::istringstream iss(line);
            std::string ClassCode, UcCode, Weekday, StartHour, Duration, Type;

            if (getline(iss, ClassCode, ',') &&
                getline(iss, UcCode, ',') &&
                getline(iss, Weekday, ',') &&
                getline(iss, StartHour, ',') &&
                getline(iss, Duration, ',') &&
                getline(iss, Type)) {

                hour_value startHourValue = stod(StartHour);
                hour_value durationValue = stod(Duration);
                UC newUC(UcCode, ClassCode);
                Class newClass(newUC, Weekday, startHourValue, durationValue, Type);
                UNIClasses_.push_back(newClass);
            } else {
                throw runtime_error("Erro na linha");
            }
        }
    }

    void Controller::parseDataUCs(const string& file) {
        ifstream fileStream(file);

        if (!fileStream.is_open()) {
            throw runtime_error("Failed to open file");
        }

        string line;
        getline(fileStream, line);

        while (getline(fileStream, line)) {
            istringstream iss(line);
            string UcCode, ClassCode;

            if (getline(iss, UcCode, ',') &&
                getline(iss, ClassCode, ',')) {

                UC newUC(UcCode, ClassCode);
                UNIUCs_.insert(newUC);
            } else {
                throw runtime_error("Error parsing line");
            }
        }
    }
    void Controller::generateStudentSchedule(Student& student) {

        Schedule studentSchedule;

        for (const UC& studentUC : student.getUCList()) {
            for (const Class& currentClass : UNIClasses_) {
                if (studentUC == currentClass.getUC()) {
                    studentSchedule.addClass(currentClass);
                }
            }
        }
        student.setSchedule(studentSchedule);
    }

    void Controller::generateClassSchedule(const string& classCode) {

        Schedule classSchedule;

        for (const Class& currentClass : UNIClasses_) {
            if (currentClass.getUC().getClass() == classCode) {
                classSchedule.addClass(currentClass);
            }
        }
        classSchedule.sortSchedule();
        classSchedule.displaySchedule();
    }

    int Controller::command() {
        stack<string> commandHistory;
        int input;
        string estudante, turma, uc;

        parseDataStudent("../students_classes.csv");
        parseDataClasses("../classes.csv");
        parseDataUCs("../classes_per_uc.csv");

        while(true) {
            cout << "\n ";
            cout << "1. Consultar Estudante \n ";
            cout << "2. Consultar Turma \n ";
            cout << "3. Consultar UC\n ";
            cout << "4. Ver Lista Ordenada de Estudantes\n ";
            cout << "5. Ver Lista Ordenada de UCs\n ";
            cout << "8. Ver Ação mais recente\n ";
            cout << "9. Créditos\n ";
            cout << "0. Sair\n";
            cout << "\n";
            cin >> input;
            switch (input) {
                case 1: {
                    cout << "Insira o número de estudante:\n";
                    cin >> estudante;
                    bool studentFound1 = false;
                    Student Estudante;
                    for (const Student &student : UNIStudents_) {
                        if (student.getStudentCode() == estudante) {
                            studentFound1 = true;
                            Estudante = student;
                            break;
                        }
                    }

                    if (!studentFound1) {
                        cout << "Estudante não encontrado!\n" << endl;
                        break;
                    }
                    while (true) {
                        cout << "\n ";
                        cout << "1. Ver UCs inscritas.\n ";
                        cout << "2. Ver Horário.\n ";
                        cout << "3. Inscrever numa UC.\n ";
                        cout << "4. Trocar de Turma.(#TODO)\n ";
                        cout << "0. Voltar atrás.\n ";
                        cout << "\n ";
                        cin >> input;
                        if (input == 0) {
                            break;
                        }
                        switch (input) {
                            case 1: {
                                list<UC> lista = Estudante.getUCList();
                                for (UC uu: lista) {
                                    cout << uu.getUcCode() << endl;
                                }
                                commandHistory.push("1. Ver UCs inscritas.");
                                break;
                            }
                            case 2: {
                                generateStudentSchedule(Estudante);
                                cout << "Horário do estudante n.º " << Estudante.getStudentCode() << ":\n";
                                Schedule schedule = Estudante.getSchedule();
                                schedule.sortSchedule();
                                schedule.displaySchedule();
                                commandHistory.push("2. Ver Horário.");
                                break;
                            }
                            case 3: {
                                list<UC> lista = Estudante.getUCList();
                                int i = 0;
                                for (UC uu : lista)
                                    i++;
                                if (i<7) {
                                    cout << "Insira a UC que pretende ingressar:\n";
                                    cin >> uc;
                                    cout << "Insira a Turma que pretende ingressar:\n";
                                    cin >> turma;
                                    UC newUC(uc, turma);
                                    Estudante.addCourseUnit(newUC);
                                }
                                commandHistory.push("3. Inscrever numa UC.");
                                break;
                            }
                            case 4: { /*
                                cout << "Insira a UC de que pretende alterar a turma:\n";
                                cin >> uc;
                                cout << "Insira a turma para a qual quer mudar:\n";
                                cin >> turma;

                                const UC *selectedUC = nullptr;
                                for (auto &uu: Estudante.getUCList()) {
                                    if (uu.getUcCode() == uc) {
                                       selectedUC = &uu;
                                       break;
                                    }
                                }

                                    if (selectedUC) {
                                        // Find the enrolling class
                                        UC enrollingClass;
                                        bool classFound = false;
                                        for (const UC &nu: UNIUCs_) {
                                            if (nu.getClass() == turma) {
                                                enrollingClass = nu;
                                                classFound = true;
                                                break;
                                            }
                                        }

                                        if (classFound) {
                                            bool compatibleSchedule = true;
                                            // Modify the student's UC list
                                            for (const Class &currentClass: UNIClasses_) {
                                                if (enrollingClass == currentClass.getUC()) {
                                                    if (Estudante.getSchedule().isClassOverlapping(
                                                            currentClass)) {
                                                        compatibleSchedule = false;
                                                        break;

                                                    }
                                                }
                                            }
                                            if (!compatibleSchedule) {
                                                cout << "Horário não funciona!\n";
                                            } else {
                                                Estudante.addCourseUnit(enrollingClass);
                                                Estudante.removeCourseUnit(*selectedUC);
                                            }

                                        } else {
                                            cout << "Turma não existe!\n";
                                        }
                                    } else {
                                        cout << "Estudante não se encontra inscrito nessa UC!\n";
                                    } */
                                commandHistory.push("4. Trocar de Turma");
                                break;
                            }
                            default:
                                cout << "Opção inválida!\n ";
                        }
                    }
                    break;
                }
                case 2: {
                    cout << "Insira a UC da Turma que pretende consultar: \n";
                    cin >> uc;
                    cout << "Insira a Turma que pretende consultar: \n";
                    cin >> turma;
                    bool classFound1 = false;
                    UC Turma(uc, turma);
                    auto it = UNIUCs_.find(Turma);

                    if (it != UNIUCs_.end()) {
                        classFound1 = true;
                    } else {
                        cout << "Turma não encontrada!\n" << endl;
                    }
                    while (true) {
                        cout << "\n ";
                        cout << "1. Ver UCs da Turma.\n ";
                        cout << "2. Ver Horário.\n ";
                        cout << "3. Ver Estudantes.\n ";
                        cout << "0. Voltar atrás.\n ";
                        cout << "\n ";
                        cin >> input;
                        if (input == 0) {
                            break;
                        }
                        switch (input) {
                            case 1: {


                                break;
                            }
                            case 2: {
                                generateClassSchedule(turma);
                                commandHistory.push("2. Ver Horário da Turma.");
                                break;
                            }
                            case 3: {
                                vector<Student> returnable;
                                for (Student student : UNIStudents_) {
                                    list<UC> lista = student.getUCList();
                                    for (UC uu : lista) {
                                        if (uu == Turma) {
                                            returnable.push_back(student);
                                        }
                                    }
                                }
                                cout << endl;
                                for (Student student : returnable) {
                                    cout << student.getStudentCode() << ' ' << student.getStudentName() << endl;
                                }
                                commandHistory.push("3. Ver Estudantes da Turma.");
                                break;
                            }
                            default:
                                cout << "Opção inválida!\n ";
                        }
                    }
                    break;
                }
                case 3: {
                    cout << "Insira a UC pretende consultar: \n";
                    cin >> uc;
                    bool ucFound1 = false;
                    for (UC uu : UNIUCs_) {
                        if (uu.getUcCode() == uc) {
                            ucFound1 = true;
                            break;
                        }
                    }

                    if (!ucFound1) {
                        cout << "UC não encontrada!\n" << endl;
                        break;
                    }
                    while (true) {
                        cout << "\n ";
                        cout << "1. Ver Estudantes Inscritos.\n ";
                        cout << "2. Ver Número de Estudantes Inscritos.\n ";
                        cout << "0. Voltar atrás.\n ";
                        cout << "\n ";
                        cin >> input;
                        if (input == 0) {
                            break;
                        }
                        switch (input) {
                            case 1: {
                                vector<Student> returnable;
                                for (Student student : UNIStudents_) {
                                    list<UC> lista = student.getUCList();
                                    for (UC uu : lista) {
                                        if (uu.getUcCode() == uc) {
                                            returnable.push_back(student);
                                        }
                                    }
                                }
                                cout << endl;
                                for (Student student : returnable) {
                                    cout << student.getStudentCode() << ' ' << student.getStudentName() << endl;
                                }
                                commandHistory.push("1. Ver Estudantes Inscritos.");
                                break;
                            }
                            case 2: {
                                cout << ucStudentCount_[uc];
                                commandHistory.push("2. Ver Número de Estudantes Inscritos.");
                                break;
                            }
                            case 3: {
                                break;
                            }
                            default:
                                cout << "Opção inválida!\n ";
                        }
                    }
                    break;
                }
                case 4: {
                    multimap<int, std::string> sortedStudents;
                    for (const Student &student : UNIStudents_) {
                        sortedStudents.insert({std::stoi(student.getStudentCode()), student.getStudentName()});
                    }
                    cout << "Estudantes por ordem ascendente do seu número" << endl;
                    for (const auto &pair : sortedStudents) {
                        cout << pair.first << ' ' << pair.second << endl;
                    }
                    commandHistory.push("4. Ver Lista Ordenada de Estudantes");
                    break;
                }
                case 5: {
                    multimap<int, std::string, greater<int>> sortedUcs;
                    for (const auto &entry : ucStudentCount_) {
                        sortedUcs.insert({entry.second, entry.first});
                    }

                    cout << "UCs por ordem decrescente:\n";
                    for (const auto &pair : sortedUcs) {
                        cout << pair.second << " - Estudantes: " << pair.first << endl;
                    }
                    commandHistory.push("5. Ver Lista Ordenada de UCs");
                    break;
                }
                case 8: {
                    cout << commandHistory.top() << endl;
                    commandHistory.pop();
                    break;
                }
                case 9: {
                    cout << "Feito por André de Sousa, Álvaro Pacheco e Rodrigo de Sousa\n";
                    cout << "Grupo 135\n";
                    break;
                }
                case 0: {
                    cout << "Obrigado por usar os nossos serviços. Adeus!\n";
                    return 0;
                }
                default:
                    cout << "Opção inválida!\n ";
                    break;
            }
        }
    }
}

