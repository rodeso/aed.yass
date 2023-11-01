//
// Created by rodri on 01/11/23.
//
#include <iostream>
#include "Student.h"

using namespace std;
namespace uni {
    //CONSTRUCTOR
    Student::Student() {
        StudentName_ = "";
        StudentName_ = "";
        vector<UC> UCList;
        UCList_ = UCList;
    }
    Student::Student(string StudentCode, string StudentName, vector<UC> UCList) {
        StudentCode_ = StudentCode;
        StudentName_ = StudentName;
        UCList_ = UCList;
    }
    //GETTERS
    const string &Student::getStudentCode() const {
        return StudentCode_;
    }
    const string &Student::getStudentName() const {
        return StudentName_;
    }

    const vector<UC>& Student::getUCList() const{
        return UCList_;
    }

    const Schedule& Student::getSchedule() const {
        return studentSchedule_;
    }
    //SETTERS
    void Student::addCourseUnit(const UC& c) {
        UCList_.push_back(c);
    }
    void Student::setSchedule(const Schedule& schedule) {
        studentSchedule_ = schedule;
    }
/*
    void Student::displaySchedule() const {
        cout << "Student's Schedule:\n";

        for (const Class& classInfo : studentSchedule_) {
            cout << "Class Code: " << classInfo.getUC().getClass() << endl;
            cout << "UC Code: " << classInfo.getUC().getUcCode() << endl;
            cout << "Weekday: " << classInfo.getWeekday() << endl;
            cout << "Start Hour: " << classInfo.getStart() << endl;
            cout << "Duration: " << classInfo.getDuration() << " hours" << endl;
            cout << "Type: " << classInfo.getType() << endl;
            cout << "---------------------\n";
        }
    } */

} //uni
