#ifndef MAMMAL_H
#define MAMMAL_H
#include "Animal.h"

class Mammal : public Animal {
private:
    string furColor;
public:
    Mammal();
    Mammal(string n, int a, bool h, string f);
    ~Mammal();
    void display() const override;
};
#endif
