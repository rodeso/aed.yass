//
// Created by rodri on 24/10/23.
//
#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Student.h"
#include "UC.h"
#include "Controller.h"

using namespace std;
namespace uni {
    void Controller::parseDataStudent(const std::string &file, vector <Student> &students) {
        ifstream fileStream(file); // Load file

        if (!fileStream.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        std::string line;
        getline(fileStream, line);

        while (getline(fileStream, line)) {
            std::istringstream iss(line);
            std::string StudentCode, StudentName, UcCode, ClassCode;

            if (getline(iss, StudentCode, ',') &&
                getline(iss, StudentName, ',') &&
                getline(iss, UcCode, ',') &&
                getline(iss, ClassCode)) {

                // Check if a student with this StudentCode already exists
                bool studentExists = false;
                for (auto &student: students) {
                    if (student.getStudentCode() == StudentCode) {
                        studentExists = true;
                        UC newUC(UcCode, ClassCode);
                        student.addCourseUnit(newUC);
                        break;
                    }
                }

                // If the student does not exist, create a new Student object
                if (!studentExists) {
                    Student newStudent(StudentCode, StudentName);
                    UC newUC(UcCode, ClassCode);
                    newStudent.addCourseUnit(newUC);
                    students.push_back(newStudent);
                }
            } else {
                throw std::runtime_error("Error parsing line");
            }
        }
    }


    int command() {
        int input;
        string estudante, turma, uc;
        do {
            cout << "\n 0. Ver Horário de estudante \n 1. Ver horário de Turma \n 2. Alterar Turma de estudante\n 3. Creditos\n 4. Exit\n\n";
            cin >> input;
            switch (input) {
                case 0: {
                    /*
                    cout << "Insira o numero de estudante \n";
                    cin>>estudante;
                    Gestor gestor;
                    set<EstudanteTurma> horarioestudante =gestor.HorarioEstudante(estudante);
                    printhorarioestudante(horarioestudante,estudante);
                    break;
                    */
                }
                case 1: {
                    /*
                    string turma;
                    Gestor gestor;
                    cout<<"Insira a turma de que quer ver horario \n";
                    cin>>turma;
                    printhorarioturma(gestor.HorarioTurma(),turma);
                     */
                    break;
                }
                case 2: {
                    /*
                    cout << "Insira o numero de estudante\n";
                    cin >> estudante;
                    cout << "Insira a UC de que pretende alterar a turma\n";
                    cin >> uc;
                    cout << "Insira a turma para a qual quer mudar \n";
                    cin >> turma;
                     ##TODO
                    */
                    break;
                }
                case 3:
                    cout << "Done by André de Sousa, Rodrigo de Sousa and Álvaro Pacheco\n";
                    cout << "Group 1305\n";
                    break;
                case 4:
                    cout << "Thank you for using our service. Goodbye!\n";
                    return 0;
                default:
                    return 0;
            }
        } while (input);
        return 0;
    }
}

//LEGACY DO NOT USE UNLESS TESTING
//DUPLICATED CODE -> SEE ParseDataStudent
/*
vector<Student> Controller::lerEstudantes() {
    string filename = "/home/andre/Desktop/Andre/Trabalho/Faculdade/2ºAno/1ºS/AED/projeto/AED1G135/students_classes.csv";
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;

    vector<Student> estudantes;
    string dummy;

    ifstream input(filename);
    if (input.is_open()) {
        getline(input, dummy);  // Skip header line
        while(input.good()) {
            getline(input, StudentCode, ',');
            getline(input, StudentName, ',');
            getline(input, UcCode, ',');
            getline(input, ClassCode, '\n');

            Student estudante(StudentCode, StudentName);
            estudante.addCourseUnit(UcCode, ClassCode);
            // If there's a function like `addClass` you want to use, call it here.
            // estudante.addClass(...);

            estudantes.push_back(estudante);
        }
        input.close();
    } else {
        cout << "ERROR: File Not Open" << '\n';
    }
    return estudantes;
}
*/


int main() {
    uni::Controller controller;
    std::vector<uni::Student> students;
    controller.parseDataStudent("/home/rodri/L.EIC/2.1/AED/AED1G135/students_classes.csv", students);
    for (uni::Student student : students) {
        cout << student.getStudentCode() << ' ' << student.getStudentName();
        cout << '\n';
    }
    uni::command();
    return 0;
}
