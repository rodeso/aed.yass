//
// Created by rodri on 01/11/23.
//

#include <iostream>
#include "UC.h"

namespace uni {
    bool UC::operator==(const UC& other) const {
        string Code1 = this->getUcCode();
        string Code2 = other.getUcCode();
        string Class1 = this->getClass();
        string Class2 = other.getClass();
        return (Code1 == Code2) && (Class1 == Class2);
    }
    bool UC::operator<(const UC& other) const {
        // Call the getters to compare attributes
        if (getUcCode() == other.getUcCode()) {
            return getClass() < other.getClass();
        }
        return getUcCode() < other.getUcCode();
    }

    UC::UC() {
        UcCode_ = "WHAT";
        ClassCode_ = "WHAT";
    }
    UC::UC(string UcCode, string ClassCode){
        UcCode_ = UcCode;
        ClassCode_ = ClassCode;
    }
    string UC::getUcCode() const {
        return UcCode_;
    }
    string normalizeString(const std::string& str) {
        string result = str;
        while (!result.empty() && (result.back() == '\r' || result.back() == '\n')) {
            result.pop_back();
        }
        return result;
    }

    string UC::getClass() const {
        return normalizeString(ClassCode_);
    }
    int UC::getCapacity() const {
        return MAX;
    }
    void UC::print() const {
        cout << UcCode_ <<  ' ' << ClassCode_ << endl;
    }
    void UC::setCapacity(int x) {
        MAX = x;
    }

} // uni