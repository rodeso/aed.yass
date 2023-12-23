//
// Created by rodri on 01/11/23.
//

#include "../include/Class.h"
#include <iomanip>
#include <map>

using namespace std;

namespace uni {

    //Constructor
    Class::Class(const UC& ClassUnit, string Weekday, hour_value StartHour, hour_value Duration, string Type) {
        ClassUnit_ = ClassUnit;
        Weekday_ = Weekday;
        StartHour_ = StartHour;
        Duration_ = Duration;
        Type_ = Type;
    }

    //Getters
    UC Class::getUC() const {
        return ClassUnit_;
    }
    string Class::getWeekday() const {
        return Weekday_;
    }
    hour_value Class::getStart() const {
        return StartHour_;
    }
    string Class::getStartTimeString() const {
        int hours = static_cast<int>(StartHour_);
        int minutes = static_cast<int>((StartHour_ - hours) * 60);
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << hours << ":" << std::setfill('0') << std::setw(2) << minutes;
        return oss.str();
    }
    hour_value Class::getDuration() const {
        return Duration_;
    }
    string Class::getType() const {
        return Type_;
    }
    //Translator
    string Class::translateWeekday() const {
        map<string, string> translationMap = {
                {"Monday", "Segunda-feira"},
                {"Tuesday", "Terça-feira"},
                {"Wednesday", "Quarta-feira"},
                {"Thursday", "Quinta-feira"},
                {"Friday", "Sexta-feira"},
                {"Saturday", "Sábado"},
                {"Sunday", "Domingo"}
        };

        string englishWeekday = Weekday_;

        auto translation = translationMap.find(englishWeekday);
        if (translation != translationMap.end()) {
            return translation->second;
        } else {
            return englishWeekday;
        }
    }



} // namespace uni