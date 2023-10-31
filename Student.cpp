//
// Created by rodri on 24/10/23.
//

#include "Student.h"

using namespace std;
namespace uni {
    Student::Student(string StudentCode, string StudentName) {
        StudentCode_ = StudentCode;
        StudentName_ = StudentName;
    }

    const string &Student::getStudentCode() const {
        return StudentCode_;
    }
    const string &Student::getStudentName() const {
        return StudentName_;
    }

    void Student::addCourseUnit(UC c) {
        UCList_.push_back(c);
    }
} //uni

