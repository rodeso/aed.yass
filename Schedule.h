//
// Created by rodri on 27/10/23.
//

#ifndef SCHEDULE_H
#define SCHEDULE_H

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
        bool isClassOverlapping(const Class& newClass) const;
        void displaySchedule() const;

    private:
        vector<Class> classes; // List of classes in the schedule
    };
}
#endif
