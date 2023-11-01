//
// Created by rodri on 01/11/23.
//

#ifndef AED1G135_CONTROLLER_H
#define AED1G135_CONTROLLER_H

#include <string>
#include <vector>
#include "Student.h"
#include "Class.h"
#include "UC.h"
#include "Schedule.h"

using namespace std;

namespace uni {
    class Controller {
    private:

    public:
        void parseDataStudent(const string& file, vector<Student> &students);
        vector<Student> lerEstudantes();
        void parseDataClasses(const string& file, vector<Class> &classes);
        void generateStudentSchedules(vector<Student>& students, const vector<Class>& classes);

        //parseDataTurmas();
    };
}

#endif //AED1G135_CONTROLLER_H
