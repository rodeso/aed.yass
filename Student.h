//
// Created by rodri on 01/11/23.
//

#ifndef AED1G135_STUDENT_H
#define AED1G135_STUDENT_H

#include <string>
#include <list>
#include "UC.h"
#include "Schedule.h"

using namespace std;
namespace uni {

    class Student {
    private:
        string StudentCode_;        //code of student           (ID)
        string StudentName_;        //name of student           (Nome)
        list<UC> UCList_;           //UCS que tem TIPO ARRAY ou uma lista
        Schedule studentSchedule_;  //Horário MATRIX (?)
    public:
        //CONSTRUCTOR
        Student();
        Student(string StudentCode, string StudentName, list<UC> UCList);
        //GETTERS
        const string &getStudentCode() const;
        const string &getStudentName() const;
        const list<UC>& getUCList() const;
        const Schedule& getSchedule() const;
        //SETTERS
        void addCourseUnit(const UC& c);
        void removeCourseUnit(const UC& c);
        void setSchedule(const Schedule& schedule);

    };


} // uni

#endif //AED1G135_STUDENT_H
