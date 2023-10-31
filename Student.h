//
// Created by rodri on 24/10/23.
//

#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H

#include <string>
#include <list>
#include "Class.h"
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



    };

} // uni


#endif //PROJECT1_STUDENT_H
