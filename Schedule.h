//
// Created by rodri on 01/11/23.
//

#ifndef AED1G135_SCHEDULE_H
#define AED1G135_SCHEDULE_H

#include <vector>
#include "Class.h" // Include the Class class header

using namespace std;
namespace uni {
    class Schedule {
    public:
        Schedule(); // Constructor
        void addClass(const Class &classInfo); // Add a class to the schedule
        const vector<Class> &getClasses() const; // Get the list of classes in the schedule
        void sortSchedule();
        bool isUCOverlapping(const UC& uc) const;
        void displaySchedule() const;

    private:
        vector<Class> classes_; // List of classes in the schedule
    };
}

#endif //AED1G135_SCHEDULE_H
