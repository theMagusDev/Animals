// Copyright (C) 2024 Yuriy Magus

#include <iostream>
#include "../include/Utilities.h"
#include "../include/Dog.h"

Dog::Dog() : Animal() {
    this->name = nullptr;
}

Dog::Dog(
    char* name,
    Breed race,
    Sex sex,
    Color color,
    int age,
    float mass
) : Animal(sex, color, age, mass) {
    this->race = race;
    this->name = nullptr;
    setName(name);
}

Dog::Dog(const Dog &ref) : race(ref.race) {
    setName(nullptr);
    setName(ref.name);
    setSex(ref.getSexEnum());
    setColor(ref.getColorEnum());
    setMass(ref.getMass());
    setAge(ref.getAge());
}

Dog::Dog(Dog &&ref) : race(ref.race) {
    if (this->name == reinterpret_cast<char*>(0x10)) {
        this->name = nullptr;
    }
    std::cout << "Move constructor called from " << std::endl;
    delete [] this->name;
    this->name = ref.name;

    ref.name = nullptr;
}

Dog::~Dog() {
    delete[] this->name;
}

char* Dog::getName() const {
    if (this->name == nullptr) {
        return const_cast<char *>("None");
    }
    return this->name;
}

char* Dog::getRace() const {
    switch (this->race) {
        case (Breed::UNINITIALIZED):
            return const_cast<char *>("None");
        case (Breed::LABRADOR):
            return const_cast<char *>("Labrador");
        case (Breed::SHEPHERD):
            return const_cast<char *>("Shepherd");
        case (Breed::BULLDOG):
            return const_cast<char *>("Bulldog");
        case (Breed::POODLE):
            return const_cast<char *>("Poodle");
        case (Breed::BEAGLE):
            return const_cast<char *>("Beagle");
        case (Breed::ROTTWEILER):
            return const_cast<char *>("Rottweiler");
        case (Breed::BOXER):
            return const_cast<char *>("Boxer");
        case (Breed::DALMATIAN):
            return const_cast<char *>("Dalmatian");
        case (Breed::HUSKY):
            return const_cast<char *>("Husky");
        case (Breed::CHIHUAHUA):
            return const_cast<char *>("Chihuahua");
        case (Breed::YORKIE):
            return const_cast<char *>("Yorkie");
        default:
            return const_cast<char *>("None");
    }
}

void Dog::setName(const char* newName) {
    if (newName == nullptr) {
        this->name = nullptr;
        return;
    }

    size_t newNameLength = getStrLength(newName);
    delete [] this->name;
    this->name = new char[newNameLength + 1];
    for (int i = 0; i < newNameLength + 1; i++) {
        this->name[i] = newName[i];
    }
}

void Dog::setRace(Breed newRace) {
    this->race = newRace;
}

void Dog::whatDoesSay() {
    switch (this->race) {
        case (Breed::UNINITIALIZED):
            std::cout << "Woof!" << std::endl;
            break;
        case Breed::CHIHUAHUA: case Breed::YORKIE:
            std::cout << "Arf!" << std::endl;
            break;
        case Breed::SHEPHERD: case Breed::HUSKY:
            std::cout << "Ruff!" << std::endl;
            break;
        case Breed::DALMATIAN: case Breed::ROTTWEILER:
            std::cout << "Bow-wow!" << std::endl;
            break;
        case Breed::BEAGLE: case Breed::BULLDOG:
            std::cout << "Bark!" << std::endl;
            break;
        case Breed::POODLE: case Breed::BOXER: case Breed::LABRADOR:
            std::cout << "Howl!" << std::endl;
            break;
        default:
            std::cout << "Woof!" << std::endl;
            break;
    }
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        setAge(other.getAge());
        setMass(other.getMass());
        setSex(other.getSexEnum());
        setColor(other.getColorEnum());
        setRace(other.race);
        setName(other.name);
    }
    return *this;
}

Dog& Dog::operator=(Dog&& other) {
    if (this != &other) {
        delete[] this->name;
        this->name = other.name;
        setAge(other.getAge());
        setMass(other.getMass());
        setSex(other.getSexEnum());
        setColor(other.getColorEnum());
        setRace(other.race);

        other.name = nullptr;
        other.setAnyAge(0);
        other.setAnyMass(0.0);
        other.setSex(Sex::UNINITIALIZED);
        other.setColor(Color::UNINITIALIZED);
        other.setRace(Breed::UNINITIALIZED);
    }

    return *this;
}
