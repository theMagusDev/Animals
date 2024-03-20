// Copyright (C) 2024 Yuriy Magus

#ifndef INCLUDE_DOG_H_
#define INCLUDE_DOG_H_

#include "Animal.h"

enum class Breed {
    UNINITIALIZED,
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

    char* getName() const;
    char* getRace() const;
    void setName(const char* newName);
    void setRace(Breed newRace);
    void whatDoesSay() override;

    Dog& operator=(const Dog& other);
    Dog& operator=(Dog&& other);
 private:
    char* name;
    Breed race;
};


#endif  // INCLUDE_DOG_H_
