//
// Created by rodri on 24/10/23.
//

#ifndef PROJECT1_CLASS_H
#define PROJECT1_CLASS_H

#include <string>

namespace uni {
    typedef double hour_value;

    class Class {
    private:
        std::string UcCode_;      //code of course unit       (UC)
        std::string ClassCode_;   //code of the class         (Turma)
        int Weekday_;             //day of the week           (Dia)
        hour_value StartHour_;    //start time of the class   (Horário)
        hour_value Duration_;     //duration of the class     (Duração)
        std::string Type_;        //type of class: T, TP, PL  (Tipo)
    public:
        //constructors
        Class();
        Class(std::string UcCode, std::string ClassCode, int Weekday, hour_value StartHour, hour_value Duration, std::string Type);
        //getters
        std::string getUC();
        std::string getClass();
        std::string getWeekday();
        int getWeeknumber(std::string day);
        hour_value getStart();
        hour_value getDuration();
        std::string getType();

    };

} // uni

#endif //PROJECT1_CLASS_H
