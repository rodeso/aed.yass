//
// Created by rodri on 30/10/23.
//
#include <vector>
#include <string>
#include "Student.h"
#include <set>

#ifndef PROJECT1_CONTROLLER_H
#define PROJECT1_CONTROLLER_H

struct StudentClass
{
    string StudentName;
    string StudentCode;
    string UcCode;
    string ClassCode;
    string WeekDay;
    string StartHour;
    string Duration;
    string Type;
};


namespace uni {
    class Controller {
    private:
        //attributes idk
    public:
        void parseDataStudent(const std::string& file, vector<Student> &students);
        vector<Student> readStudents();
        set<StudentClass> ClassSchedule();
        vector<Class> readClasses();
        //parseDataClasses();
        //parseDataTurmas();
    };
}

#endif //PROJECT1_CONTROLLER_H
