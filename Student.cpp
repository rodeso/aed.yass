//
// Created by rodri on 24/10/23.
//

#include "Student.h"

namespace uni {
    Student::Student(std::string StudentCode, std::string StudentName) {
        StudentCode_ = StudentCode;
        StudentName_ = StudentName;
    }

    const std::string &Student::getStudentCode() const {
        return StudentCode_;
    }

    void Student::addCourseUnit(std::string UcCode, std::string ClassCode) {

    }
} //uni