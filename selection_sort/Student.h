//
// Created by daniel on 2019-03-10.
//

#ifndef SELECTION_SORT_STUDENT_H
#define SELECTION_SORT_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student{

    string name;
    int score;

    bool operator<(const Student &otherStudent) {

        return score != otherStudent.score ? score > otherStudent.score : name < otherStudent.name;
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};

#endif //SELECTION_SORT_STUDENT_H
