//
// Created by Lap on 11/12/2025.
//

#ifndef UNTITLED_ANIMAL_H
#define UNTITLED_ANIMAL_H
#include <iostream>
using namespace std


class animal {
private:
    string name ;
    int age ;
    bool isHungry;
public:
    void display();
    void feed();
    void isHungry();
};


#endif //UNTITLED_ANIMAL_H
