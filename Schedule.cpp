//
// Created by rodri on 01/11/23.
//

#include <algorithm>
#include <iostream>
#include <list>
#include "Schedule.h"

using namespace std;

namespace uni {

    //Constructor
    Schedule::Schedule() = default;

    //MISC
    void Schedule::addClass(const uni::Class &classInfo) {
        classes_.push_back(classInfo);
    }
    void Schedule::sortSchedule() {
        const vector<string> customWeekdayOrder = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

        auto compareClasses = [&customWeekdayOrder](const Class& class1, const Class& class2) {
            auto pos1 = find(customWeekdayOrder.begin(), customWeekdayOrder.end(), class1.getWeekday());
            auto pos2 = find(customWeekdayOrder.begin(), customWeekdayOrder.end(), class2.getWeekday());

            if (pos1 == customWeekdayOrder.end() || pos2 == customWeekdayOrder.end()) {
                return false;
            }
            if (pos1 < pos2) {
                return true;
            }
            if (pos1 > pos2) {
                return false;
            }
            if (class1.getStart() < class2.getStart()) {
                return true;
            }
            if (class1.getStart() > class2.getStart()) {
                return false;
            }
            if (    (class1.getType() == "T" && class2.getType() == "TP") ||
                    (class1.getType() == "TP" && class2.getType() == "T") ||
                    (class1.getType() == "T" && class2.getType() == "T")  ||
                    (class1.getType() == "T" && class2.getType() == "PL")) {
                return false;
            }
            return false;
        };
        sort(classes_.begin(), classes_.end(), compareClasses);
    }
    bool Schedule::isUCOverlapping(const UC& uc) const {
        std::list<Class> ucClasses;
        for (const Class& classInfo : classes_) {
            if (classInfo.getUC().getUcCode() == uc.getUcCode()) {
                ucClasses.push_back(classInfo);
            }
        }
        for (const Class& newClass : ucClasses) {
            for (const Class& classInfo : ucClasses) {
                if (&newClass != &classInfo) {
                    if (newClass.getWeekday() == classInfo.getWeekday() &&
                        newClass.getStart() + newClass.getDuration() > classInfo.getStart() &&
                        classInfo.getStart() + classInfo.getDuration() > newClass.getStart() &&
                        !(
                                (newClass.getType() == "T" && classInfo.getType() == "TP") ||
                                (newClass.getType() == "TP" && classInfo.getType() == "T") ||
                                (newClass.getType() == "T" && classInfo.getType() == "T") ||
                                (newClass.getType() == "T" && classInfo.getType() == "PL")
                        )) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void Schedule::displaySchedule() const {
        cout << "\n";
        for (const Class& classInfo : classes_) {
            cout << "Código da UC: " << classInfo.getUC().getUcCode() << endl;
            cout << "Código da Turma: " << classInfo.getUC().getClass() << endl;
            cout << "Dia da Semana: " << classInfo.translateWeekday() << endl;
            cout << "Começo: " << classInfo.getStartTimeString() << endl;
            cout << "Duração: " << classInfo.getDuration() << " h" << endl;
            cout << "Tipo: " << classInfo.getType() << endl;
            cout << "---------------------\n";
        }
    }
}