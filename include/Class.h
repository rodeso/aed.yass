//
// Created by rodri on 01/11/23.
//

#ifndef AED1G135_CLASS_H
#define AED1G135_CLASS_H

#include <string>
#include "UC.h"

using namespace std;

namespace uni {
    typedef double hour_value;

    class Class {
    private:
        UC ClassUnit_;             //code of course unit and class   (UC e turma)
        string Weekday_;          //day of the week                 (Dia)
        hour_value StartHour_;    //start time of the class         (Horário)
        hour_value Duration_;     //duration of the class           (Duração)
        string Type_;             //type of class: T, TP, PL        (Tipo)

    public:
        //Constructor
        Class(const UC &ClassUnit, string Weekday, hour_value StartHour, hour_value Duration, string Type);

        //Getters
        UC getUC() const;
        string getWeekday() const;
        hour_value getStart() const;
        string getStartTimeString() const;
        hour_value getDuration() const;
        string getType() const;

        //Translator
        string translateWeekday() const;
    };
}
#endif //AED1G135_CLASS_H