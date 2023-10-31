//
// Created by rodri on 24/10/23.
//

#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H

#include <string>
#include "Class.h"

using namespace std;
namespace uni {

    class Student {
    private:
        string StudentName_;   //name of student           (Nome)
        string StudentCode_;   //code of student           (ID)

        //UCS que tem TIPO ARRAY
        //Horário MATRIX (?)
    public:
        Student(string StudentCode, string StudentName);
        void addCourseUnit(string UcCode, string ClassCode);

        const string &getStudentCode() const;
        const string &getStudentName() const;

        void addClass(Class c);
    };

} // uni


#endif //PROJECT1_STUDENT_H
