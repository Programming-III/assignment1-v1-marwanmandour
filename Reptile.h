#ifndef REPTILE_H
#define REPTILE_H
#include "Animal.h"

class Reptile : public Animal {
private:
    bool isVenomous;
public:
    Reptile();
    Reptile(string n, int a, bool h, bool v);
    ~Reptile();
    void display() const override;
};
#endif
