//
// Created by rodri on 31/10/23.
//

#ifndef PROJECT1_UC_H
#define PROJECT1_UC_H

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
        //CONSTRUCTORS
        UC();
        UC(string UcCode, string ClassCode);
        //GETTERS
        string getUcCode() const;
        string getClass() const;
    };

} // uni

#endif //PROJECT1_UC_H
