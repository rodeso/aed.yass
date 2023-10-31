//
// Created by rodri on 30/10/23.
//
#include <vector>
#include <string>
#include "Student.h"

#ifndef PROJECT1_CONTROLLER_H
#define PROJECT1_CONTROLLER_H

using namespace std;
namespace uni {
    class Controller {
    private:
        //attributes idk
    public:
        void parseDataStudent(const string& file, vector<Student> &students);
        vector<Student> lerEstudantes();
        void parseDataClasses(const string& file, vector<Class> &classes);
        void generateStudentSchedules(vector<Student>& students, const vector<Class>& classes);
        //parseDataTurmas();
    };
}

#endif //PROJECT1_CONTROLLER_H
