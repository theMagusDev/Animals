#include <iostream>

#include "../include/Animal.h"
#include "../include/Dog.h"
#include "../include/Fox.h"

using namespace std;

int main() {
    Dog blankDog;
    blankDog.whatDoesSay(); // Woof!

    cout << blankDog.getName() << endl; // Uninitialized
    blankDog.setName("Sharik");
    cout << blankDog.getName() << endl; // Sharik
    blankDog.setName("Mike");
    cout << blankDog.getName() << endl; // Mike

    cout << blankDog.getRace() << endl; // Uninitialized
    blankDog.setRace(Breed::HUSKY);
    cout << blankDog.getRace() << endl; // Husky
    blankDog.setRace(Breed::YORKIE);
    cout << blankDog.getRace() << endl; // Yorkie

    cout << blankDog.getColor() << endl; // Uninitialized
    blankDog.setColor(Color::WHITE);
    cout << blankDog.getColor() << endl; // White

    cout << blankDog.getSex() << endl; // Uninitialized
    blankDog.setSex(Sex::MALE);
    cout << blankDog.getSex() << endl; // Male

    cout << blankDog.getAge() << endl; // 0
    blankDog.setAge(4);
    cout << blankDog.getAge() << endl; // 4

    cout << blankDog.getMass() << endl; // 0
    blankDog.setMass(5.3);
    cout << blankDog.getMass() << endl; // 5.3

    Dog muhtar("Muhtar", Breed::SHEPHERD, Sex::MALE, Color::GREY, 6, 4.5);
    cout << muhtar.getName() << endl; // Muhtar
    cout << muhtar.getRace() << endl; // Shepherd
    cout << muhtar.getSex() << endl; // Male
    cout << muhtar.getColor() << endl; // Grey
    cout << muhtar.getAge() << endl; // 6
    cout << muhtar.getMass() << endl; // 4.5

    return 0;
}
