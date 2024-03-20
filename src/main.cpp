#include <iostream>

#include "../include/Animal.h"
#include "../include/Dog.h"
#include "../include/Fox.h"

using namespace std;

void testDogConstructors();
void testDogGettersAndSetters();
void testDogOperators();
void testFoxConstructors();
void testFoxGettersAndSetters();
void testFoxOperators();
void testFoxEating();
void testWhatDoesSay();

int main() {
    testDogConstructors();
    testFoxConstructors();

    testDogGettersAndSetters();
    testFoxGettersAndSetters();

    testDogOperators();
    testFoxOperators();

    testFoxEating();
    testWhatDoesSay();

    return 0;
}

void testDogConstructors() {
    cout << "testDogConstructors()" << endl;

    Dog blankDog;
    cout << blankDog.getName() << endl; // None
    cout << blankDog.getRace() << endl; // None
    cout << blankDog.getColor() << endl; // None
    cout << blankDog.getSex() << endl; // None
    cout << blankDog.getAge() << endl; // 0
    cout << blankDog.getMass() << endl; // 0

    // Initialization constructor
    Dog muhtar("Muhtar", Breed::SHEPHERD, Sex::MALE, Color::GREY, 6, 4.5);
    cout << muhtar.getName() << endl; // Muhtar
    cout << muhtar.getRace() << endl; // Shepherd
    cout << muhtar.getSex() << endl; // Male
    cout << muhtar.getColor() << endl; // Grey
    cout << muhtar.getAge() << endl; // 6
    cout << muhtar.getMass() << endl; // 4.5

    // Copy constructor
    Dog muhtarCopy(muhtar);
    cout << muhtarCopy.getName() << endl; // Muhtar
    cout << muhtarCopy.getRace() << endl; // Shepherd
    cout << muhtarCopy.getSex() << endl; // Male
    cout << muhtarCopy.getColor() << endl; // Grey
    cout << muhtarCopy.getAge() << endl; // 6
    cout << muhtarCopy.getMass() << endl; // 4.5

    // Destructor will be called at the end of
    // function and all objects will be destroyed.
}

void testFoxConstructors() {
    cout << "testFoxConstructors()" << endl;

    Fox blankFox;
    cout << blankFox.getName() << endl; // None
    cout << blankFox.getType() << endl; // None
    cout << blankFox.getColor() << endl; // None
    cout << blankFox.getSex() << endl; // None
    cout << blankFox.getAge() << endl; // 0
    cout << blankFox.getMass() << endl; // 0

    // Initialization constructor
    Fox megan("Megan", TypeFox::BENGAL, Sex::MALE, Color::ORANGE, 3, 1.5);
    cout << megan.getName() << endl; // Megan
    cout << megan.getType() << endl; // Bengal
    cout << megan.getSex() << endl; // Male
    cout << megan.getColor() << endl; // Orange
    cout << megan.getAge() << endl; // 3
    cout << megan.getMass() << endl; // 1.5

    // Copy constructor
    Fox meganCopy(megan);
    cout << meganCopy.getName() << endl; // Megan
    cout << meganCopy.getType() << endl; // Bengal
    cout << meganCopy.getSex() << endl; // Male
    cout << meganCopy.getColor() << endl; // Orange
    cout << meganCopy.getAge() << endl; // 3
    cout << meganCopy.getMass() << endl; // 1.5

    // Destructor will be called at the end of
    // function and all objects will be destroyed.
}

void testDogGettersAndSetters() {
    cout << "testDogGettersAndSetters()" << endl;
    Dog blankDog;

    cout << blankDog.getName() << endl; // None
    blankDog.setName("Sharik");
    cout << blankDog.getName() << endl; // Sharik
    blankDog.setName("Mike");
    cout << blankDog.getName() << endl; // Mike

    cout << blankDog.getRace() << endl; // None
    blankDog.setRace(Breed::HUSKY);
    cout << blankDog.getRace() << endl; // Husky
    blankDog.setRace(Breed::YORKIE);
    cout << blankDog.getRace() << endl; // Yorkie

    cout << blankDog.getColor() << endl; // None
    blankDog.setColor(Color::WHITE);
    cout << blankDog.getColor() << endl; // White

    cout << blankDog.getSex() << endl; // None
    blankDog.setSex(Sex::MALE);
    cout << blankDog.getSex() << endl; // Male

    cout << blankDog.getAge() << endl; // 0
    blankDog.setAge(4);
    cout << blankDog.getAge() << endl; // 4

    cout << blankDog.getMass() << endl; // 0
    blankDog.setMass(5.3);
    cout << blankDog.getMass() << endl; // 5.3
}

void testFoxGettersAndSetters() {
    cout << "testFoxGettersAndSetters()" << endl;
    Fox blankFox;

    cout << blankFox.getName() << endl; // None
    blankFox.setName("Megan");
    cout << blankFox.getName() << endl; // Megan
    blankFox.setName("Akari");
    cout << blankFox.getName() << endl; // Akari

    cout << blankFox.getType() << endl; // None
    blankFox.setType(TypeFox::CORSAC);
    cout << blankFox.getType() << endl; // Corsac
    blankFox.setType(TypeFox::ARCTIC);
    cout << blankFox.getType() << endl; // Arctic

    cout << blankFox.getColor() << endl; // None
    blankFox.setColor(Color::YELLOW);
    cout << blankFox.getColor() << endl; // Yellow

    cout << blankFox.getSex() << endl; // None
    blankFox.setSex(Sex::FEMALE);
    cout << blankFox.getSex() << endl; // Female

    cout << blankFox.getAge() << endl; // 0
    blankFox.setAge(3);
    cout << blankFox.getAge() << endl; // 3

    cout << blankFox.getMass() << endl; // 0
    blankFox.setMass(2.7);
    cout << blankFox.getMass() << endl; // 2.7
}

void testDogOperators() {
    cout << "testDogOperators()" << endl;

    Dog mike("Mike", Breed::YORKIE, Sex::MALE, Color::BROWN, 5, 3.5);
    Dog bosia("Bosia", Breed::CHIHUAHUA, Sex::FEMALE, Color::YELLOW, 3, 1.5);
    Dog blankDog;

    // Copy operator
    blankDog = mike;
    cout << blankDog.getName() << endl; // Mike
    cout << blankDog.getRace() << endl; // Yorkie
    cout << blankDog.getColor() << endl; // Brown
    cout << blankDog.getAge() << endl; // 5
    cout << blankDog.getSex() << endl; // Male
    cout << blankDog.getMass() << endl; // 3.5

    // Move operator
    blankDog = std::move(bosia);
    cout << blankDog.getName() << endl; // Bosia
    cout << blankDog.getRace() << endl; // Chihuahua
    cout << blankDog.getColor() << endl; // Yellow
    cout << blankDog.getAge() << endl; // 3
    cout << blankDog.getSex() << endl; // Female
    cout << blankDog.getMass() << endl; // 1.5

    cout << bosia.getName() << endl; // None
    cout << bosia.getRace() << endl; // None
    cout << bosia.getColor() << endl; // None
    cout << bosia.getAge() << endl; // 0
    cout << bosia.getSex() << endl; // None
    cout << bosia.getMass() << endl; // 0
}

void testFoxOperators() {
    cout << "testFoxOperators()" << endl;

    Fox megan("Megan", TypeFox::FENNEC, Sex::MALE, Color::BROWN, 4, 2.1);
    Fox akari("Akari", TypeFox::ARCTIC, Sex::FEMALE, Color::WHITE, 3, 1.4);
    Fox blankFox;

    // Copy operator
    blankFox = megan;
    cout << blankFox.getName() << endl; // Megan
    cout << blankFox.getType() << endl; // Fennec
    cout << blankFox.getColor() << endl; // Brown
    cout << blankFox.getAge() << endl; // 4
    cout << blankFox.getSex() << endl; // Male
    cout << blankFox.getMass() << endl; // 2.1

    // Move operator
    blankFox = std::move(akari);
    cout << blankFox.getName() << endl; // Akari
    cout << blankFox.getType() << endl; // Arctic
    cout << blankFox.getColor() << endl; // White
    cout << blankFox.getAge() << endl; // 3
    cout << blankFox.getSex() << endl; // Female
    cout << blankFox.getMass() << endl; // 1.4

    cout << akari.getName() << endl; // None
    cout << akari.getType() << endl; // None
    cout << akari.getColor() << endl; // None
    cout << akari.getAge() << endl; // 0
    cout << akari.getSex() << endl; // None
    cout << akari.getMass() << endl; // 0
}

void testFoxEating() {
    Fox pepper("Pepper", TypeFox::SWIFT, Sex::MALE, Color::BLACK, 7, 3.2);
    Fox scarlet("Scarlet", TypeFox::KIT, Sex::FEMALE, Color::YELLOW, 5, 1.9);

    cout << pepper.getName() << " has eaten " << pepper.getNumberRabbitsEaten() << " rabbit(s)." << endl;
    cout << scarlet.getName() << " has eaten " << scarlet.getNumberRabbitsEaten() << " rabbit(s)." << endl;
    /*
     * Pepper has eaten 0 rabbit(s).
     * Scarlet has eaten 0 rabbit(s).
     */

    pepper.eat();
    cout << pepper.getName() << " has eaten " << pepper.getNumberRabbitsEaten() << " rabbit(s)." << endl;
    cout << scarlet.getName() << " has eaten " << scarlet.getNumberRabbitsEaten() << " rabbit(s)." << endl;
    /*
     * Fox Pepper has eaten a rabbit.
     * Pepper has eaten 1 rabbit(s).
     * Scarlet has eaten 0 rabbit(s).
     */

    for (int i = 0; i < 5; i++) {
        scarlet.eat();
    }
    /*
     * Fox Scarlet has eaten a rabbit.
     * ...
     * Fox Scarlet has eaten a rabbit.
     */
    for (int i = 0; i < 7; i++) {
        pepper.eat();
    }
    /*
     * Fox Pepper has eaten a rabbit.
     * ...
     * Fox Pepper has eaten a rabbit.
     */
    cout << pepper.getName() << " has eaten " << pepper.getNumberRabbitsEaten() << " rabbit(s)." << endl;
    cout << scarlet.getName() << " has eaten " << scarlet.getNumberRabbitsEaten() << " rabbit(s)." << endl;
    /*
     * Pepper has eaten 8 rabbit(s).
     * Scarlet has eaten 5 rabbit(s).
     */
}

void testWhatDoesSay() {
    Fox megan("Megan", TypeFox::FENNEC, Sex::MALE, Color::BROWN, 4, 2.1);
    Fox akari("Akari", TypeFox::ARCTIC, Sex::FEMALE, Color::WHITE, 3, 1.4);
    Fox blankFox;

    Dog mike("Mike", Breed::YORKIE, Sex::MALE, Color::BROWN, 5, 3.5);
    Dog bosia("Bosia", Breed::HUSKY, Sex::FEMALE, Color::YELLOW, 3, 1.5);
    Dog blankDog;

    megan.whatDoesSay(); // Ring-ding-ding-ding-dingeringeding!
    akari.whatDoesSay(); // Jacha-chacha-chacha-chow!
    blankFox.whatDoesSay(); // Yip

    mike.whatDoesSay(); // Arf!
    bosia.whatDoesSay(); // Ruff!
    blankDog.whatDoesSay(); // Woof!
}
