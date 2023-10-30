//
// Created by rodri on 24/10/23.
//

#include "Class.h"

namespace uni {
    //constructors
   /* Class::Class() {
        UcCode_     =   "L.EIC000";
        ClassCode_  =   "0LEIC00";
        Weekday_    =   0;
        StartHour_  =   0.0;
        Duration_   =   0.0;
        Type_       =   "";
    }
*/
    Class::Class(std::string UcCode, std::string ClassCode, int Weekday, hour_value StartHour, hour_value Duration, std::string Type) {
        UcCode_     =   UcCode;
        ClassCode_  =   ClassCode;
        Weekday_    =   Weekday;
        StartHour_  =   StartHour;
        Duration_   =   Duration;
        Type_       =   Type;
    }

    //getters
    std::string Class::getUC() {                return UcCode_;
    }
    std::string Class::getClass() {             return ClassCode_;
    }
    std::string Class::getWeekday(){
        std::string day;
        switch (Weekday_) {
            case 0:day = "Weekend";
                break;
            case 1:day = "Monday";
                break;
            case 2:day = "Tuesday";
                break;
            case 3:day = "Wednesday";
                break;
            case 4:day = "Thursday";
                break;
            case 5:day = "Friday";
                break;
            default:day= "Weekend";
        }
        return day;
    }
    int Class::getWeeknumber(std::string day) {
        if (day[0] == 'M') {
                                                return 1;
        }
        if (day[0] == 'T') {
            if (day[1] == 'u') {
                                                return 2;
            }
            else                                return 4;
        }
        if (day[0] == 'W') {
                                                return 3;
        }
        if (day[0] == 'F') {
                                                return 5;
        }
        else                                    return 0;
    }
    hour_value Class::getStart() {
                                                return StartHour_;
    }
    hour_value Class::getDuration() {
                                                return Duration_;
    }
    std::string Class::getType() {
                                                return Type_;
    }

    Class::~Class() {
        delete this;
    }
} // uni