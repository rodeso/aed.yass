//
// Created by rodri on 24/10/23.
// Aula
//
#ifndef CLASS_H
#define CLASS_H


#include <string>

using namespace std;

namespace uni {
    typedef double hour_value;
    class Class {
    private:
        string ClassCode_;   //code of the class         (Turma)
        string UcCode_;      //code of course unit       (UC)
        string Weekday_;             //day of the week           (Dia)
        hour_value StartHour_;    //start time of the class   (Horário)
        hour_value Duration_;     //duration of the class     (Duração)
        string Type_;        //type of class: T, TP, PL  (Tipo)
    public:
        //constructors
        Class(string UcCode, string ClassCode, string Weekday, hour_value StartHour, hour_value Duration, string Type);

        virtual ~Class();

        //getters
        string getUcCode() const;
        string getClass() const;
        string getWeekday() const;
        hour_value getStart() const;
        hour_value getDuration() const;
        string getType() const;
    };

} // uni

#endif // CLASS_H
