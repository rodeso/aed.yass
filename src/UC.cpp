//
// Created by rodri on 01/11/23.
//

#include <iostream>
#include "../include/UC.h"

namespace uni {

    //To make sets
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

    //Constructors
    UC::UC() {
        UcCode_ = "Lorem";
        ClassCode_ = "Ipsum";
    }
    UC::UC(string UcCode, string ClassCode){
        UcCode_ = UcCode;
        ClassCode_ = ClassCode;
    }

    //Getters
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
    void UC::setCapacity(int x) {
        MAX = x;
    }

} // uni