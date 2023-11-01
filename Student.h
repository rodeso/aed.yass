//
// Created by rodri on 01/11/23.
//

#ifndef AED1G135_STUDENT_H
#define AED1G135_STUDENT_H

#include <string>
#include <vector>
#include "UC.h"
#include "Schedule.h"

using namespace std;
namespace uni {

    class Student {
    private:
        string StudentCode_;        //code of student           (ID)
        string StudentName_;        //name of student           (Nome)
        vector<UC> UCList_;           //UCS que tem TIPO ARRAY ou uma lista
        Schedule studentSchedule_;  //Horário MATRIX (?)
    public:
        //CONSTRUCTOR
        Student();
        Student(string StudentCode, string StudentName, vector<UC> UCList);
        //GETTERS
        const string &getStudentCode() const;
        const string &getStudentName() const;
        const vector<UC>& getUCList() const;
        const Schedule& getSchedule() const;
        //SETTERS
        void addCourseUnit(const UC& c);
        void setSchedule(const Schedule& schedule);

        void displaySchedule() const;

    };


} // uni

#endif //AED1G135_STUDENT_H
