//
// Created by rodri on 31/10/23.
//

#include "UC.h"

namespace uni {
    bool UC::operator==(const UC& other) const {
        return (UcCode_ == other.UcCode_) && (ClassCode_ == other.ClassCode_);
    }

    UC::UC() {
        UcCode_ = "";
        ClassCode_ = "";
    }
    UC::UC(string UcCode, string ClassCode){
        UcCode_ = UcCode;
        ClassCode_ = ClassCode;
    }
    string UC::getUcCode() const {
        return UcCode_;
    }

    string UC::getClass() const {
        return ClassCode_;
    }
} // uni