//
// Created by rodri on 24/10/23.
//

#ifndef PROJECT1_CLASS_H
#define PROJECT1_CLASS_H

#include <String>

namespace uni {
    typedef double hour_value;

    class Class {
    private:
        std::string ClassCode_;   //code of the class         (Turma)
        std::string UcCode_;      //code of course unit       (UC)
        int Weekday_;             //day of the week           (Dia)
        hour_value StartHour_;    //start time of the class   (Horário)
        hour_value Duration_;     //duration of the class     (Duração)
        std::string Type_;        //type of class: T, TP, PL  (Tipo)

    };

} // uni

#endif //PROJECT1_CLASS_H
