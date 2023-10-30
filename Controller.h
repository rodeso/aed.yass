//
// Created by rodri on 30/10/23.
//
#include <vector>
#include <string>
#include "Student.h"

#ifndef PROJECT1_CONTROLLER_H
#define PROJECT1_CONTROLLER_H

namespace uni {
    class Controller {
    private:
        //attributes idk
    public:
        void parseDataStudent(const std::string& file, vector<Student> &students);
        //parseDataClasses();
        //parseDataTurmas();
    };
}

#endif //PROJECT1_CONTROLLER_H
