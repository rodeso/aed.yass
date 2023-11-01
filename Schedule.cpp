//
// Created by rodri on 01/11/23.
//

#include <algorithm>
#include <iostream>
#include "Schedule.h"

using namespace std;

namespace uni {
    Schedule::Schedule() {
        // Initialize the schedule as needed
    }

    void Schedule::addClass(const uni::Class &classInfo) {
        // Add a class to the schedule
        classes_.push_back(classInfo);
    }

    const std::vector<Class> &Schedule::getClasses() const {
        return classes_;
    }
    void Schedule::sortSchedule() {
        // Define a custom comparison function for sorting
        auto compareClasses = [](const Class& class1, const Class& class2) {
            // First, compare by day of the week (e.g., Monday, Tuesday, etc.)
            if (class1.getWeekday() < class2.getWeekday()) {
                return true;
            }
            if (class1.getWeekday() > class2.getWeekday()) {
                return false;
            }

            // If the days are the same, compare by start time
            if (class1.getStart() < class2.getStart()) {
                return true;
            }
            if (class1.getStart() > class2.getStart()) {
                return false;
            }

            // Handle overlapping classes of specific types
            if (
                    (class1.getType() == "T" && class2.getType() == "TP") ||
                    (class1.getType() == "TP" && class2.getType() == "T") ||
                    (class1.getType() == "T" && class2.getType() == "T") ||
                    (class1.getType() == "T" && class2.getType() == "PL")
                    ) {
                // Handle overlapping of non-allowed types
                return false;
            }

            // By default, consider the classes as equal
            return false;
        };

        // Sort the classes in the schedule using the custom comparison function
        sort(classes_.begin(), classes_.end(), compareClasses);
    }

    bool Schedule::isClassOverlapping(const Class& newClass) const {
        for (const Class& classInfo : classes_) {
            // Check if the new class overlaps with an existing class
            if (classInfo.getWeekday() == newClass.getWeekday() &&
                classInfo.getStart() + classInfo.getDuration() > newClass.getStart() &&
                newClass.getStart() + newClass.getDuration() > classInfo.getStart() &&
                !(
                        (classInfo.getType() == "T" && newClass.getType() == "TP") ||
                        (classInfo.getType() == "TP" && newClass.getType() == "T") ||
                        (classInfo.getType() == "T" && newClass.getType() == "T") ||
                        (classInfo.getType() == "T" && newClass.getType() == "PL")
                )) {
                // Classes overlap, and their types do not allow overlap
                return true;
            }
        }
        return false;
    }
    void Schedule::displaySchedule() const {
        cout << "Student's Schedule:\n";

        for (const Class& classInfo : classes_) {
            cout << "Class Code: " << classInfo.getUC().getClass() << endl;
            cout << "UC Code: " << classInfo.getUC().getUcCode() << endl;
            cout << "Weekday: " << classInfo.getWeekday() << endl;
            cout << "Start Hour: " << classInfo.getStart() << endl;
            cout << "Duration: " << classInfo.getDuration() << " hours" << endl;
            cout << "Type: " << classInfo.getType() << endl;
            cout << "---------------------\n";
        }
    }
}