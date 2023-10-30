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
                        student.addCourseUnit(UcCode, ClassCode);
                        break;
                    }
                }

                // If the student does not exist, create a new Student object
                if (!studentExists) {
                    Student newStudent(StudentCode, StudentName);
                    newStudent.addCourseUnit(UcCode, ClassCode);
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
int main() {
    uni::Controller controller;
    std::vector<uni::Student> students;
    controller.parseDataStudent("/home/rodri/L.EIC/2.1/AED/AED1G135/students_classes.csv", students);
    for (uni::Student student : students) {
        cout << student.getStudentCode();
        cout << '\n';
    }
    //command();
    return 0;
}
