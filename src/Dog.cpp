// Copyright (C) 2024 Yuriy Magus

#include <iostream>
#include "../include/Utilities.h"
#include "../include/Dog.h"

Dog::Dog() : Animal() {
    this->name = nullptr;
}

Dog::Dog(
    const char* name,
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
    delete [] this->name;
    this->name = ref.name;

    ref.name = nullptr;
}

Dog::~Dog() {
    delete[] this->name;
}

const char* Dog::getName() const {
    if (this->name == nullptr) {
        return "None";
    }
    return const_cast<const char*>(this->name);
}

const char* Dog::getRace() const {
    switch (this->race) {
        case (Breed::UNINITIALIZED):
            return "None";
        case (Breed::LABRADOR):
            return "Labrador";
        case (Breed::SHEPHERD):
            return "Shepherd";
        case (Breed::BULLDOG):
            return "Bulldog";
        case (Breed::POODLE):
            return "Poodle";
        case (Breed::BEAGLE):
            return "Beagle";
        case (Breed::ROTTWEILER):
            return "Rottweiler";
        case (Breed::BOXER):
            return "Boxer";
        case (Breed::DALMATIAN):
            return "Dalmatian";
        case (Breed::HUSKY):
            return "Husky";
        case (Breed::CHIHUAHUA):
            return "Chihuahua";
        case (Breed::YORKIE):
            return "Yorkie";
        default:
            return "None";
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
