//
// Created by rodri on 24/10/23.
//

#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H

#include <string>
#include <list>
#include "Class.h"

using namespace std;
namespace uni {

    class Student {
    private:
        string StudentCode_;   //code of student           (ID)
        string StudentName_;   //name of student           (Nome)
        list<UC> UCList_;
        //UCS que tem TIPO ARRAY ou uma lista
        //Horário MATRIX (?)
    public:
        Student(string StudentCode, string StudentName);
        void addCourseUnit(UC c);

        const string &getStudentCode() const;
        const string &getStudentName() const;

        void addClass(Class bloco);  //adicionar bloco no horário
    };

} // uni


#endif //PROJECT1_STUDENT_H
