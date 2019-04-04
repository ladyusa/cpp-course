#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal DEFAULT constructor" << endl;
    }
    Animal(string n) {
        cout << "Animal constructor" << endl;
    }
    ~Animal() {
        cout << "  Animal DESTRUCTOR" << endl;
    }
};

class LandAnimal : public Animal {
public:
    LandAnimal() {
        cout << "LandAnimal DEFAULT constructor" << endl;
    }
    LandAnimal(string n) {
        cout << "LandAnimal constructor" << endl;
    } 
    ~LandAnimal() {
        cout << "  LandAnimal DESTRUCTOR" << endl;
    }
 
};

class Dog : public LandAnimal {
public:
    Dog(string n) {
        cout << "Dog constructor" << endl;
    } 
    ~Dog() {
        cout << "  Dog DESTRUCTOR" << endl;
    }
};

int main() {
    Dog toob("toob");
}

