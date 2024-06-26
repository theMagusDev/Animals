// Copyright (C) 2024 Yuriy Magus

#include <iostream>
#include "../include/Utilities.h"
#include "../include/Fox.h"

Fox::Fox() : Animal() {
    this->name = nullptr;
    this->type = TypeFox::UNINITIALIZED;
    this->numberRabbitsEaten = 0;
}

Fox::Fox(
    const char* name,
    TypeFox type,
    Sex sex,
    Color color,
    int age,
    float mass
) : Animal(sex, color, age, mass) {
    this->name = nullptr;
    setName(name);
    setType(type);
    this->numberRabbitsEaten = 0;
}

Fox::Fox(const Fox &ref) {
    this->numberRabbitsEaten = ref.numberRabbitsEaten;
    setType(ref.type);
    setName(nullptr);
    setName(ref.name);
    setSex(ref.getSexEnum());
    setColor(ref.getColorEnum());
    setAge(ref.getAge());
    setMass(ref.getMass());
}

Fox::Fox(Fox &&ref) {
    setType(ref.type);
    this->numberRabbitsEaten = ref.numberRabbitsEaten;
    delete [] this->name;
    this->name = ref.name;

    ref.name = nullptr;
    ref.numberRabbitsEaten = 0;
}

Fox::~Fox() {
    this->numberRabbitsEaten = 0;
    this->type = TypeFox::UNINITIALIZED;
    delete [] this->name;
}

char* Fox::getName() const {
    if (this->name == nullptr) {
        return const_cast<char *>("None");
    }
    return this->name;
}

char* Fox::getType() const {
    switch (this->type) {
        case (TypeFox::UNINITIALIZED):
            return const_cast<char *>("None");
        case (TypeFox::ARCTIC):
            return const_cast<char *>("Arctic");
        case (TypeFox::FENNEC):
            return const_cast<char *>("Fennec");
        case (TypeFox::CORSAC):
            return const_cast<char *>("Corsac");
        case (TypeFox::BENGAL):
            return const_cast<char *>("Bengal");
        case (TypeFox::SWIFT):
            return const_cast<char *>("Swift");
        case (TypeFox::KIT):
            return const_cast<char *>("Kit");
        default:
            return const_cast<char *>("None");
    }
}

int Fox::getNumberRabbitsEaten() const {
    return this->numberRabbitsEaten;
}

void Fox::setName(const char* newName) {
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

void Fox::setType(TypeFox newType) {
    this->type = newType;
}

void Fox::eat() {
    std::cout << "Fox " << this->name << " has eaten a rabbit." << std::endl;
    this->numberRabbitsEaten += 1;
}

void Fox::whatDoesSay() {
    switch (this->type) {
        case (TypeFox::ARCTIC):
            std::cout << "Jacha-chacha-chacha-chow!" << std::endl;
            break;
        case (TypeFox::FENNEC):
            std::cout << "Ring-ding-ding-ding-dingeringeding!" << std::endl;
            break;
        case (TypeFox::CORSAC):
            std::cout << "Hatee-hatee-hatee-ho!" << std::endl;
            break;
        case (TypeFox::BENGAL):
            std::cout << "Joff-tchoff-tchoffo-tchoffo-tchoff!" << std::endl;
            break;
        case (TypeFox::SWIFT):
            std::cout << "Fraka-kaka-kaka-kaka-kow!" << std::endl;
            break;
        case (TypeFox::KIT):
            std::cout << "A-hee-ahee ha-hee!" << std::endl;
            break;
        default:
            std::cout << "Yip" << std::endl;
            break;
    }
}

Fox& Fox::operator=(const Fox& other) {
    if (this != &other) {
        this->numberRabbitsEaten = other.numberRabbitsEaten;
        setAge(other.getAge());
        setMass(other.getMass());
        setSex(other.getSexEnum());
        setColor(other.getColorEnum());
        setType(other.type);
        setName(other.name);
    }
    return *this;
}

Fox& Fox::operator=(Fox&& other) {
    if (this != &other) {
        delete[] this->name;
        this->name = other.name;
        setAge(other.getAge());
        setMass(other.getMass());
        setSex(other.getSexEnum());
        setColor(other.getColorEnum());
        this->numberRabbitsEaten = other.numberRabbitsEaten;
        this->type = other.type;

        other.name = nullptr;
        other.setAnyAge(0);
        other.setAnyMass(0);
        other.setSex(Sex::UNINITIALIZED);
        other.setColor(Color::UNINITIALIZED);
        other.setType(TypeFox::UNINITIALIZED);
        this->numberRabbitsEaten = 0;
    }

    return *this;
}
