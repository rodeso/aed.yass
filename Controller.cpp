//
// Created by rodri on 01/11/23.
//

#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <stack>
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
                for (auto &student: UNIStudents_) {
                    if (student.getStudentCode() == StudentCode) {
                        studentExists = true;
                        UC newUC(UcCode, ClassCode);
                        student.addCourseUnit(newUC);
                        break;
                    }
                }
                if (!studentExists) {
                    UC newUC(UcCode, ClassCode);
                    vector<UC> UCList;
                    UCList.push_back(newUC);
                    Student newStudent(StudentCode, StudentName, UCList);
                    UNIStudents_.push_back(newStudent);
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
        stack<int> commandHistory;
        int input;
        string estudante, turma, uc;

        parseDataStudent("../students_classes.csv");
        parseDataClasses("../classes.csv");

        while(true) {
            cout << "\n ";
            cout << "1. Ver Horário de Estudante \n ";
            cout << "2. Ver Horário de Turma \n ";
            cout << "3. Alterar Turma de Estudante\n ";
            cout << "4. Créditos\n ";
            cout << "0. Sair\n";
            cout << "\n";
            cin >> input;
            commandHistory.push(input);
            switch (input) {
                case 1: {

                    cout << "Insira o número de estudante \n";
                    cin>>estudante;
                    Student selectedStudent;
                    bool studentFound = false;

                    for (const Student& student : UNIStudents_) {
                        if (student.getStudentCode() == estudante) {
                            selectedStudent = student;
                            studentFound = true;
                            break;
                        }
                    }

                    if (studentFound) {
                        generateStudentSchedule(selectedStudent);

                        // Display the schedule
                        cout << "Horário do estudante n.º " << selectedStudent.getStudentCode() << ":\n";
                        Schedule schedule = selectedStudent.getSchedule();
                        schedule.sortSchedule();
                        schedule.displaySchedule();

                    } else {
                        cout << "Estudante não encontrado" << endl;
                    }
                    break;

                }
                case 2: {

                    cout<<"Insira a turma que pretende consultar \n";
                    cin>>turma;
                    generateClassSchedule(turma);

                    break;
                }
                case 3: {
                    cout << "Insira o número de estudante\n";
                    cin >> estudante;
                    cout << "Insira a UC de que pretende alterar a turma\n";
                    cin >> uc;
                    cout << "Insira a turma para a qual quer mudar \n";
                    cin >> turma;
                     ##TODO
                    break;
                }
                case 4:
                    cout << "Feito por André de Sousa, Álvaro Pacheco e Rodrigo de Sousa\n";
                    cout << "Grupo 135\n";
                    break;
                case 5:
                    cout << "Obrigado por usar os nossos serviços. Adeus!\n";
                    return 0;
                default:
                    return 0;
            }
        }
    }
}

