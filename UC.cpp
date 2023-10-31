//
// Created by rodri on 31/10/23.
//

#include "UC.h"

namespace uni {
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