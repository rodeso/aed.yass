#include "Class.h"

namespace uni {

    // Constructor implementation
    Class::Class(string UcCode, string ClassCode, string Weekday, hour_value StartHour, hour_value Duration, string Type) {
        UcCode_ = UcCode;
        ClassCode_ = ClassCode;
        Weekday_ = Weekday;
        StartHour_ = StartHour;
        Duration_ = Duration;
        Type_ = Type;
    }

    // Destructor implementation
    Class::~Class() {
    }

    // Getter methods
    string Class::getUcCode() const {
        return UcCode_;
    }

    string Class::getClass() const {
        return ClassCode_;
    }

    string Class::getWeekday() const {
        return Weekday_;
    }

    hour_value Class::getStart() const {
        return StartHour_;
    }

    hour_value Class::getDuration() const {
        return Duration_;
    }

    string Class::getType() const {
        return Type_;
    }

} // namespace uni
