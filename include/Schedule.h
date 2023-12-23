//
// Created by rodri on 01/11/23.
//

#ifndef AED1G135_SCHEDULE_H
#define AED1G135_SCHEDULE_H

#include <vector>
#include "Class.h"

using namespace std;

namespace uni {
    class Schedule {
    private:
        vector<Class> classes_;

    public:
        //Constructor
        Schedule();

        //MISC
        void addClass(const Class &classInfo);
        void sortSchedule();
        bool isUCOverlapping(const UC& uc) const;
        void displaySchedule() const;
    };
}

#endif //AED1G135_SCHEDULE_H
