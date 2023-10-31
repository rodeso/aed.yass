#include "Class.h"

namespace uni {

    // Constructor implementation
    Class::Class(UC ClassUnit, string Weekday, hour_value StartHour, hour_value Duration, string Type) {
        ClassUnit_ = ClassUnit;
        Weekday_ = Weekday;
        StartHour_ = StartHour;
        Duration_ = Duration;
        Type_ = Type;
    }

    // Destructor implementation
    Class::~Class() {
    }

    // Getter methods
    UC Class::getUC() const {
        return ClassUnit_;
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
