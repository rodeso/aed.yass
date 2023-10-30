//
// Created by rodri on 24/10/23.
//

#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H

#include <string>

namespace uni {

    class Student {
    private:
        std::string StudentCode_;   //code of student           (ID)
        std::string StudentName_;   //name of student           (Nome)
        std::string UcCode_;        //code of course unit       (UC)
        std::string ClassCode_      //code of class             (Turma)
        //UCS que tem TIPO ARRAY
        //Horário MATRIX (?)
    public:
        Student();
        Student(std::string StudentCode, std::string StudentName);
        void addCourse(std::string UcCode, std::string ClassCode);
        void addClass(Class c);
    };

} // uni


#endif //PROJECT1_STUDENT_H
