#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "Enclosure.h"
#include "Visitor.h"
using namespace std;

Animal::Animal() : name(""), age(0), isHungry(false) {}
Animal::Animal(string n, int a, bool h) : name(n), age(a), isHungry(h) {}
Animal::~Animal() {}
string Animal::getName() const { return name; }
int Animal::getAge() const { return age; }
bool Animal::getIsHungry() const { return isHungry; }
void Animal::setName(string n) { name = n; }
void Animal::setAge(int a) { age = a; }
void Animal::setIsHungry(bool h) { isHungry = h; }
void Animal::display() const {
    cout << name << " (Age: " << age << ", " << (isHungry ? "Hungry" : "Not Hungry") << ")" << endl;
}
void Animal::feed() { isHungry = false; }

Mammal::Mammal() : Animal(), furColor("") {}
Mammal::Mammal(string n, int a, bool h, string f) : Animal(n, a, h), furColor(f) {}
Mammal::~Mammal() {}
void Mammal::display() const {
    cout << getName() << " (Age: " << getAge() << ", " << (getIsHungry() ? "Hungry" : "Not Hungry") << ")" << endl;
}

Bird::Bird() : Animal(), wingSpan(0.0f) {}
Bird::Bird(string n, int a, bool h, float w) : Animal(n, a, h), wingSpan(w) {}
Bird::~Bird() {}
void Bird::display() const {
    cout << getName() << " (Age: " << getAge() << ", " << (getIsHungry() ? "Hungry" : "Not Hungry") << ")" << endl;
}

Reptile::Reptile() : Animal(), isVenomous(false) {}
Reptile::Reptile(string n, int a, bool h, bool v) : Animal(n, a, h), isVenomous(v) {}
Reptile::~Reptile() {}
void Reptile::display() const {
    cout << getName() << " (Age: " << getAge() << ", " << (isVenomous ? "Venomous, " : "") << (getIsHungry() ? "Hungry" : "Not Hungry") << ")" << endl;
}

Enclosure::Enclosure(int c) : capacity(c), currentCount(0) {
    animals = new Animal*[capacity];
}
Enclosure::~Enclosure() {
    for (int i = 0; i < currentCount; i++) delete animals[i];
    delete[] animals;
}
void Enclosure::addAnimal(Animal* a) {
    if (currentCount < capacity) animals[currentCount++] = a;
}
void Enclosure::displayAnimals() const {
    cout << "Enclosure 1 Animals:" << endl;
    for (int i = 0; i < currentCount; i++) animals[i]->display();
}

Visitor::Visitor() : visitorName(""), ticketsBought(0) {}
Visitor::Visitor(string n, int t) : visitorName(n), ticketsBought(t) {}
Visitor::~Visitor() {}
void Visitor::displayInfo() const {
    cout << "Visitor Info:" << endl;
    cout << "Name: " << visitorName << endl;
    cout << "Tickets Bought: " << ticketsBought << endl;
}

int main() {
    Enclosure e(5);
    e.addAnimal(new Mammal("Lion", 5, true, "Golden"));
    e.addAnimal(new Bird("Parrot", 2, false, 0.25f));
    e.addAnimal(new Reptile("Snake", 3, true, true));
    Visitor v("Sarah Ali", 3);
    e.displayAnimals();
    cout << endl;
    v.displayInfo();
    return 0;
}
