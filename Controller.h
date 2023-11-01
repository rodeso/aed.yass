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
        vector<Student> UNIStudents_;
        vector<Class> UNIClasses_;
    public:
        void parseDataStudent(const string& file);
        void parseDataClasses(const string& file);
        void generateStudentSchedule(Student& student);
        void generateClassSchedule(const string& classCode);
        int command();

        vector<Student> lerEstudantes();
        //parseDataTurmas();
    };
}

#endif //AED1G135_CONTROLLER_H
