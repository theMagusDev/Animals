// Copyright (C) 2024 Yuriy Magus

#ifndef ANIMALS_DOG_H
#define ANIMALS_DOG_H

#include "Animal.h"

enum class Breed {
    LABRADOR,
    SHEPHERD,
    BULLDOG,
    POODLE,
    BEAGLE,
    ROTTWEILER,
    BOXER,
    DALMATIAN,
    HUSKY,
    CHIHUAHUA,
    YORKIE
};

class Dog : public Animal {
 public:
    Dog();
    Dog(char* name, Breed race, Sex sex, Color color, int age, float mass);
    Dog(const Dog& ref);
    Dog(Dog&& ref);
    ~Dog();

    char* getName();
    char* getRace();
    void setName(char* newName);
    void setRace(Breed newRace);
    void whatDoesSay() override;

    Dog& operator=(const Dog& other);
    Dog& operator=(Dog&& other);
 private:
    char* name;
    Breed race;
};


#endif //ANIMALS_DOG_H
