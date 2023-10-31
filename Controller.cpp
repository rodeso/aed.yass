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
#include "Class.h"

using namespace std;
using namespace uni;

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



//ler class

#include <fstream>
#include <vector>
#include <iostream>

vector<Class> Controller::readClasses() {
    string filename = "../classes.csv";
    string ClassCode;
    string UcCode;
    string Weekday;
    string StartHour;
    string Duration;
    string Type;

    vector<Class> classes;
    string dummy;

    ifstream input(filename);
    if (input.is_open()) {
        getline(input, dummy);
        while(input.good()) {
            getline(input, ClassCode, ',');
            getline(input, UcCode, ',');
            getline(input, Weekday, ',');
            getline(input, StartHour, ',');
            getline(input, Duration, ',');
            getline(input, Type, '\n');

            hour_value startHourValue = stod(StartHour);
            hour_value durationValue = stod(Duration);
            Class currentClass(UcCode, ClassCode, Weekday, startHourValue, durationValue, Type);
            classes.push_back(currentClass);
        }

    } else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    return classes;
}



vector<Student> Controller::readStudents() {
    string filename = "../students_classes.csv";
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;

    vector<Student> students;
    string dummy;

    ifstream input(filename);
    if (input.is_open()) {
        getline(input, dummy);  // Skip header line
        while(input.good()) {
            getline(input, StudentCode, ',');
            getline(input, StudentName, ',');
            getline(input, UcCode, ',');
            getline(input, ClassCode, '\n');

            Student student(StudentCode, StudentName);
            student.addCourseUnit(UcCode, ClassCode);
            students.push_back(student);
        }
        input.close();
    } else {
        cout << "ERROR: File Not Open" << '\n';
    }
    return students;
}

/*

set<StudentClass> Controller::ClassSchedule() {
    vector<Student> students = readStudents();
    
}
*/


int main() {
    //get the data from the return estudantes
    Controller controller;
    vector<Student> estudantes = controller.readStudents();
    for(const Student &estudante : estudantes){
        cout << estudante.getStudentName() << endl;
    };
    vector<Class> classes = controller.readClasses();
    for(const Class &classe : classes){
        cout << classe.getClass() << endl;
    }
}
