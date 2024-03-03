// Copyright (C) 2024 Yuriy Magus

#include "../include/Fox.h"
#include "../include/Utilities.h"

#define INITIAL_FOX_NAME_LENGTH 100

Fox::Fox() : Animal() {
    this->numberRabbitsEaten = 0;
}

Fox::Fox(char* name, TypeFox type, Sex sex, Color color, int age, float mass) : Animal(sex, color, age, mass) {
    setName(name);
    setType(type);
    this->numberRabbitsEaten = 0;
}

Fox::Fox(const Fox &ref) : type(ref.type), numberRabbitsEaten(ref.numberRabbitsEaten) {
    if (ref.name == nullptr) {
        this->name = nullptr;
    } else {
        for (int i = 0; i < getStrLength(ref.name); i++) {
            this->name[i] = ref.name[i];
        }
    }
}

Fox::Fox(Fox &&ref) : type(ref.type), numberRabbitsEaten(ref.numberRabbitsEaten) {
    delete [] this->name;
    this->name = ref.name;

    ref.name = nullptr;
    ref.numberRabbitsEaten = 0;
}

Fox::~Fox() {
    this->numberRabbitsEaten = 0;
    delete [] this->name;
}

char* Fox::getName() {
    return this->name;
}

char* Fox::getType() {
    switch (this->type) {
        case (TypeFox::ARCTIC):
            return (char*) "Arctic";
        case (TypeFox::FENNEC):
            return (char*) "Fennec";
        case (TypeFox::CORSAC):
            return (char*) "Corsac";
        case (TypeFox::BENGAL):
            return (char*) "Bengal";
        case (TypeFox::SWIFT):
            return (char*) "Swift";
        case (TypeFox::KIT):
            return (char*) "Kit";
        default:
            return (char*) "Not initialized";
    }
}

int Fox::getNumberRabbitsEaten() {
    return this->numberRabbitsEaten;
}

void Fox::setName(char* newName) {
    size_t newNameLength = getStrLength(newName);
    delete this->name;
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
        case (TypeFox::FENNEC):
            std::cout << "Ring-ding-ding-ding-dingeringeding!" << std::endl;
        case (TypeFox::CORSAC):
            std::cout << "Hatee-hatee-hatee-ho!" << std::endl;
        case (TypeFox::BENGAL):
            std::cout << "Joff-tchoff-tchoffo-tchoffo-tchoff!" << std::endl;
        case (TypeFox::SWIFT):
            std::cout << "Fraka-kaka-kaka-kaka-kow!" << std::endl;
        case (TypeFox::KIT):
            std::cout << "A-hee-ahee ha-hee!" << std::endl;
        default:
            std::cout << "Yip" << std::endl;
    }
}

Fox& Fox::operator=(const Fox& other) {
    if (this != &other) {
        this->numberRabbitsEaten = other.numberRabbitsEaten;
        this->type = other.type;

        delete this->name;
        size_t otherStrLen = getStrLength(other.name) + 1;
        this->name = new char[otherStrLen];
        for (int i = 0; i < otherStrLen; i++) {
            this->name[i] = other.name[i];
        }
    }
    return *this;
}

Fox& Fox::operator=(Fox&& other) {
    if (this != &other) {
        this->numberRabbitsEaten = other.numberRabbitsEaten;
        this->type = other.type;
        delete[] this->name;
        this->name = other.name;

        other.name = nullptr;
        other.numberRabbitsEaten = 0;
    }

    return *this;
}
