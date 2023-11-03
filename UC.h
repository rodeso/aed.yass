//
// Created by rodri on 01/11/23.
//

#ifndef AED1G135_UC_H
#define AED1G135_UC_H

#include <string>

using namespace std;

namespace uni {

    class UC {
    private:
        string UcCode_;      //code of course unit       (UC)
        string ClassCode_;   //code of the class         (Turma)

    public:
        // Overload the equality (==) operator
        bool operator==(const UC& other) const;
        bool operator<(const UC& other) const;
        //CONSTRUCTORS
        UC();
        UC(string UcCode, string ClassCode);
        //GETTERS
        string getUcCode() const;
        string getClass() const;
        void print() const;
    };

} // uni

#endif //AED1G135_UC_H
