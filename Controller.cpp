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
#include <queue>
#include "Student.h"
#include "UC.h"
#include "Controller.h"
#include "Schedule.h"

using namespace std;
namespace uni {

    //Parsers
    void Controller::parseDataStudent(const string &file) {
        ifstream fileStream(file);

        if (!fileStream.is_open()) {
            throw runtime_error("O ficheiro não abriu!");
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
                throw runtime_error("Erro na linha!");
            }
        }
    }
    void Controller::parseDataClasses(const string &file) {
        ifstream fileStream(file);

        if (!fileStream.is_open()) {
            throw std::runtime_error("O ficheiro não abriu!");
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
                throw runtime_error("Erro na linha!");
            }
        }
    }
    void Controller::parseDataUCs(const string& file) {
        ifstream fileStream(file);

        if (!fileStream.is_open()) {
            throw runtime_error("O ficheiro não abriu!");
        }

        string line;
        getline(fileStream, line);

        while (getline(fileStream, line)) {
            istringstream iss(line);
            string UcCode, ClassCode;

            if (getline(iss, UcCode, ',') &&
                getline(iss, ClassCode, ',')) {

                UC newUC(UcCode, ClassCode);
                UNIUCs_.push_back(newUC);
            } else {
                throw runtime_error("Erro na linha!");
            }
        }
    }

    //Generators
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

    //Changing/Adding Class
    bool Controller::changeStudentClass(Student& selectedStudent, const string& ucCode, const string& newClassCode, int max) {
        const UC* selectedUC = nullptr;
        for (auto& uc : selectedStudent.getUCList()) {
            if (uc.getUcCode() == ucCode) {
                selectedUC = &uc;
                break;
            }
        }

        if (selectedUC == nullptr) {
            cout << "Estudante não inscrito nesta UC!\n";
            return false;
        }

        UC* enrollingClass = nullptr;
        for (auto& uc : UNIUCs_) {
            if (uc.getUcCode() == ucCode && uc.getClass() == newClassCode) {
                enrollingClass = &uc;
                break;
            }
        }

        if (enrollingClass == nullptr) {
            cout << "Turma não existe!\n";
            return false;
        }

        string oldClassCode = selectedUC->getClass();
        if (selectedUC->getClass() == newClassCode) {
            cout << "Estudante já está inscrito nesta turma!\n";
            return false;
        }

        int currentClassCount = 0;
        for (const auto& student : UNIStudents_) {
            for (const UC& uz : student.getUCList()) {
                if (uz.getUcCode() == ucCode && uz.getClass() == newClassCode) {
                    currentClassCount++;
                }
            }
        }
        enrollingClass->setCapacity(max);
        if (currentClassCount >= enrollingClass->getCapacity()) {
            cout << "Capacidade da turma excedida!\n";
            return false;
        }
        if (selectedStudent.getSchedule().isUCOverlapping(*enrollingClass)) {
            cout << "Conflito de horário!\n";
            return false;
        }

        UC newUC(ucCode, newClassCode);
        UC oldUC(ucCode, oldClassCode);
        selectedStudent.addCourseUnit(newUC);
        selectedStudent.removeCourseUnit(oldUC);
        cout << "Turma alterada com sucesso!\n";
        return true;
    }
    bool Controller::addStudentClass(Student& selectedStudent, const string& ucCode, const string& newClassCode, int max) {
        if (selectedStudent.getUCList().size() >= 7) {
            cout << "O estudante já está inscrito em 7 UCs!\n";
            return false;
        }

        UC* newUC = nullptr;
        for (auto& uc : UNIUCs_) {
            if (uc.getUcCode() == ucCode && uc.getClass() == newClassCode) {
                newUC = &uc;
                break;
            }
        }

        if (newUC == nullptr) {
            cout << "Turma não existe!\n";
            return false;
        }
        int currentClassCount = 0;
        for (const auto& student : UNIStudents_) {
            for (const UC& uz : student.getUCList()) {
                if (uz.getUcCode() == ucCode && uz.getClass() == newClassCode) {
                    currentClassCount++;
                }
            }
        }

        newUC->setCapacity(max);
        if (currentClassCount >= newUC->getCapacity()) {
            cout << "Capacidade da turma excedida!\n";
            return false;
        }
        if (selectedStudent.getSchedule().isUCOverlapping(*newUC)) {
            cout << "Conflito de horário!\n";
            return false;
        }

        selectedStudent.addCourseUnit(*newUC);
        cout << "UC adicionada com sucesso!\n";
        return true;
    }

    //The Process that makes it all possible / "main"
    int Controller::command() {
        stack<string> commandHistory;
        int input;
        string estudante, turma, uc;

        parseDataStudent("../students_classes.csv");
        parseDataClasses("../classes.csv");
        parseDataUCs("../classes_per_uc.csv");

        while(true) {
            cout << "\n ";
            cout << "1. Consultar Estudante\n ";
            cout << "2. Consultar Turma\n ";
            cout << "3. Consultar UC\n ";
            cout << "4. Ver Lista Ordenada de Estudantes\n ";
            cout << "5. Ver Lista Ordenada de UCs\n ";
            cout << "8. Ver Ação mais recente\n ";
            cout << "9. Créditos\n ";
            cout << "0. Sair\n";
            cout << "\n";
            cin >> input;
            switch (input) {
                case 1: {   //Estudante
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
                        cout << "1. Ver UCs inscritas\n ";
                        cout << "2. Ver Horário\n ";
                        cout << "3. Inscrever numa UC\n ";
                        cout << "4. Remover uma UC\n ";
                        cout << "5. Trocar de Turma\n ";
                        cout << "0. Voltar atrás\n ";
                        cin >> input;
                        if (input == 0) {
                            break;
                        }
                        switch (input) {
                            case 1: { //Lista UCs
                                list<UC> lista = Estudante.getUCList();
                                for (UC uu: lista) {
                                    cout << uu.getUcCode() << " Turma: " << uu.getClass() << endl;
                                }
                                commandHistory.push("1. Ver UCs inscritas.");
                                break;
                            }
                            case 2: { //Horário
                                generateStudentSchedule(Estudante);
                                cout << "Horário do estudante n.º " << Estudante.getStudentCode() << ":\n";
                                Schedule schedule = Estudante.getSchedule();
                                schedule.sortSchedule();
                                schedule.displaySchedule();
                                commandHistory.push("2. Ver Horário.");
                                break;
                            }
                            case 3: { //Inscrever UC
                                int z;
                                cout << "Insira a UC que pretende ingressar:\n";
                                cin >> uc;
                                cout << "Insira o limite de Estudantes dessa UC:\n";
                                cin >> z;
                                cout << "Insira a Turma que pretende ingressar:\n";
                                cin >> turma;
                                addStudentClass(Estudante, uc, turma, z);
                                commandHistory.push("3. Inscrever numa UC.");
                                break;
                            }
                            case 4: { //Remover UC
                                cout << "Insira a UC que pretende cancelar:\n";
                                cin >> uc;
                                bool ucFound = false;
                                UC target;
                                for (UC uu : Estudante.getUCList()) {
                                    if (uu.getUcCode() == uc) {
                                        ucFound = true;
                                        target = uu;
                                        break;
                                    }
                                }
                                if (ucFound) {
                                    Estudante.removeCourseUnit(target);
                                    cout << "UC Removida com sucesso!\n";
                                } else {
                                    cout << "UC não encontrada!\n";
                                }
                                commandHistory.push("4. Remover uma UC.");
                                break;
                            }
                            case 5: { //Trocar Turma
                                int z;
                                cout << "Insira a UC de que pretende alterar a turma:\n";
                                cin >> uc;
                                cout << "Insira o limite de Estudantes dessa UC:\n";
                                cin >> z;
                                cout << "Insira a turma para a qual quer mudar:\n";
                                cin >> turma;

                                changeStudentClass(Estudante, uc, turma, z);
                                commandHistory.push("5. Trocar de Turma.");
                                break;
                            }
                            default:
                                cout << "Opção inválida!\n ";
                        }
                    }
                    break;
                }
                case 2: { //Turma
                    cout << "Insira a UC da Turma que pretende consultar:\n";
                    cin >> uc;
                    cout << "Insira a Turma que pretende consultar:\n";
                    cin >> turma;
                    UC Turma(uc, turma);
                    bool turmaFound = false;
                    for (UC uu : UNIUCs_) {
                        if (uu == Turma) {
                            turmaFound = true;
                            break;
                        }
                    }
                    if (!turmaFound) {
                        cout << "Turma não encontrada!\n" << endl;
                    }
                    while (true) {
                        cout << "\n ";
                        cout << "1. Ver UCs da Turma\n ";
                        cout << "2. Ver Horário\n ";
                        cout << "3. Ver Estudantes\n ";
                        cout << "0. Voltar atrás\n ";
                        cout << "\n ";
                        cin >> input;
                        if (input == 0) {
                            break;
                        }
                        switch (input) {
                            case 1: { //Lista UCs
                                queue<UC> fila;
                                for (UC uu : UNIUCs_) {
                                    if (uu.getClass() == turma)
                                        fila.push(uu);
                                }
                                while (!fila.empty()) {
                                    UC uz = fila.front();
                                    fila.pop();
                                    cout << uz.getUcCode() << endl;
                                }
                                commandHistory.push("1. Ver UCs da Turma.");
                                break;
                            }
                            case 2: { //Horário
                                generateClassSchedule(turma);
                                commandHistory.push("2. Ver Horário da Turma.");
                                break;
                            }
                            case 3: { //Estudantes
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
                case 3: { //UC
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
                        cout << "1. Ver Estudantes Inscritos\n ";
                        cout << "2. Ver Número de Estudantes Inscritos\n ";
                        cout << "3. Ver Turmas com esta UC\n ";
                        cout << "0. Voltar atrás\n ";
                        cout << "\n ";
                        cin >> input;
                        if (input == 0) {
                            break;
                        }
                        switch (input) {
                            case 1: { //Estudantes
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
                            case 2: { //Número
                                cout << ucStudentCount_[uc];
                                commandHistory.push("2. Ver Número de Estudantes Inscritos.");
                                break;
                            }
                            case 3: { //Turmas
                                queue<UC> fila;
                                for (UC uu : UNIUCs_) {
                                    if (uu.getUcCode() == uc)
                                        fila.push(uu);
                                }
                                while (!fila.empty()) {
                                    UC uz = fila.front();
                                    fila.pop();
                                    cout << uz.getClass() << endl;
                                }
                                commandHistory.push("3. Ver Turmas com esta UC.");
                                break;
                            }
                            default:
                                cout << "Opção inválida!\n ";
                        }
                    }
                    break;
                }
                case 4: { //Lista Estudantes
                    multimap<int, std::string> sortedStudents;
                    for (const Student &student : UNIStudents_) {
                        sortedStudents.insert({std::stoi(student.getStudentCode()), student.getStudentName()});
                    }
                    cout << "Estudantes por ordem ascendente do seu número:\n";
                    for (const auto &pair : sortedStudents) {
                        cout << pair.first << ' ' << pair.second << endl;
                    }
                    commandHistory.push("4. Ver Lista Ordenada de Estudantes.");
                    break;
                }
                case 5: { //Lista UCs
                    multimap<int, std::string, greater<int>> sortedUcs;
                    for (const auto &entry : ucStudentCount_) {
                        sortedUcs.insert({entry.second, entry.first});
                    }
                    cout << "UCs por ordem decrescente:\n";
                    for (const auto &pair : sortedUcs) {
                        cout << pair.second << " - Estudantes: " << pair.first << endl;
                    }
                    commandHistory.push("5. Ver Lista Ordenada de UCs.");
                    break;
                }
                //Implementações futuras se for necessário
                //case 6:
                //case 7:
                case 8: { //Histórico
                    if (!commandHistory.empty()) {
                        cout << commandHistory.top() << endl;
                        commandHistory.pop();
                    } else {
                        cout << "Não há ações recentes para mostrar!\n";
                    }
                    break;
                }
                case 9: { //Créditos
                    cout << "Feito por André de Sousa, Álvaro Pacheco e Rodrigo de Sousa;\n";
                    cout << "Grupo 135.\n";
                    break;
                }
                case 0: { //Terminar
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

