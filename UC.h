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
        UC();
        UC(string UcCode, string ClassCode);
        string getUcCode() const;
        string getClass() const;
    };

} // uni

#endif //PROJECT1_UC_H
