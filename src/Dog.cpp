// Copyright (C) 2024 Yuriy Magus

#include "../include/Dog.h"
#include "../include/Utilities.h"
#include <iostream>

#define INITIAL_DOG_NAME_LENGTH 100

Dog::Dog() : Animal() {}

Dog::Dog(char* name, Breed race, Sex sex, Color color, int age, float mass) : Animal(sex, color, age, mass) {
    setName(name);
    this->race = race;
}

Dog::Dog(const Dog &ref) : race(ref.race) {
    if (ref.name == nullptr) {
        this->name = nullptr;
    } else {
        for (int i = 0; i < getStrLength(ref.name); i++) {
            this->name[i] = ref.name[i];
        }
    }
}

Dog::Dog(Dog &&ref) : race(ref.race) {
    delete [] this->name;
    this->name = ref.name;

    ref.name = nullptr;
}

Dog::~Dog() {
    delete [] this->name;
}

char* Dog::getName() {
    return this->name;
}

char* Dog::getRace() {
    switch (this->race) {
        case (Breed::LABRADOR):
            return (char*) "Labrador";
        case (Breed::SHEPHERD):
            return (char*) "Shepherd";
        case (Breed::BULLDOG):
            return (char*) "Bulldog";
        case (Breed::POODLE):
            return (char*) "Poodle";
        case (Breed::BEAGLE):
            return (char*) "Beagle";
        case (Breed::ROTTWEILER):
            return (char*) "Rottweiler";
        case (Breed::BOXER):
            return (char*) "Boxer";
        case (Breed::DALMATIAN):
            return (char*) "Dalmatian";
        case (Breed::HUSKY):
            return (char*) "Husky";
        case (Breed::CHIHUAHUA):
            return (char*) "Chihuahua";
        case (Breed::YORKIE):
            return (char*) "Yorkie";
        default:
            return (char*) "Uninitialized";
    }
}

void Dog::setName(char* newName) {
    size_t newNameLength = getStrLength(newName);
    if (newNameLength + 1 > INITIAL_DOG_NAME_LENGTH) {
        delete this->name;
        this->name = new char[newNameLength + 1];
        for (int i = 0; i < newNameLength + 1; i++) {
            this->name[i] = newName[i];
        }
    } else {
        for (int i = 0; i < newNameLength + 1; i++) {
            this->name[i] = newName[i];
        }
    }
}

void Dog::setRace(Breed newRace) {
    this->race = newRace;
}

void Dog::whatDoesSay() {
    std::cout << "Woof!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->race = other.race;

        delete this->name;
        size_t otherStrLen = getStrLength(other.name) + 1;
        this->name = new char[otherStrLen];
        for (int i = 0; i < otherStrLen; i++) {
            this->name[i] = other.name[i];
        }
    }
    return *this;
}

Dog& Dog::operator=(Dog&& other) {
    if (this != &other) {
        delete[] this->name;

        this->race = other.race;
        this->name = other.name;
        other.name = nullptr;
    }

    return *this;
}
