//
// Created by Yuriy on 02.03.2024.
//

#include "../include/Animal.h"

#define MAX_COLOR_LENGTH 7
#define MAX_SEX_LENGTH 7

using enum SEX;
using enum COLOR;

Animal::Animal() : mass(0.0), age(0) {
    this->sex = nullptr;
    this->color = nullptr;
}

Animal::Animal(SEX sex, COLOR color, int age, float mass) {
    this->mass = mass;
    this->age = age;
    this->sex = new char[MAX_SEX_LENGTH];
    switch (sex) {
        case (SEX::MALE):
            this->sex = (char*) "Male";
            break;
        case (SEX::FEMALE):
            this->sex = (char*) "Female";
            break;
    }
    this->color = new char[MAX_COLOR_LENGTH];
    switch (color) {
        case (COLOR::BLACK):
            this->color = (char*) "Black";
            break;
        case (COLOR::WHITE):
            this->color = (char*) "White";
            break;
        case (COLOR::BROWN):
            this->color = (char*) "Brown";
            break;
        case (COLOR::GREY):
            this->color = (char*) "Grey";
            break;
        case (COLOR::RED):
            this->color = (char*) "Red";
            break;
        case (COLOR::ORANGE):
            this->color = (char*) "Orange";
            break;
        case (COLOR::YELLOW):
            this->color = (char*) "Yellow";
            break;
    }
}

Animal::Animal(const Animal& ref) : mass(ref.mass), age(ref.age) {
    if (ref.color == nullptr) {
        this->color = nullptr;
    } else {
        for (int i = 0; i < MAX_COLOR_LENGTH; i++) {
            this->color[i] = ref.color[i];
        }
    }

    if (ref.sex == nullptr) {
        this->sex = nullptr;
    } else {
        for (int i = 0; i < MAX_SEX_LENGTH; i++) {
            this->sex[i] = ref.sex[i];
        }
    }
}

Animal::Animal(Animal &&ref) : age(ref.age), mass(ref.mass) {
    delete [] this->color;
    delete [] this->sex;
    this->color = ref.color;
    this->sex = ref.sex;

    ref.color = nullptr;
    ref.sex = nullptr;
    ref.age = 0;
    ref.mass = 0;
}

Animal::~Animal() {
    delete[] sex;
    delete[] color;
}

float Animal::getMass() const {
    return this->mass;
}

int Animal::getAge() const {
    return this->age;
}

const char* Animal::getSex() const {
    if (this->sex == nullptr) {
        return (char*) "Not yet initialized";
    }

    return this->sex;
}

const char* Animal::getColor() const {
    if (this->color == nullptr) {
        return (char*) "Not yet initialized";
    }

    return this->color;
}

void Animal::setMass(float newMass) {
    if (newMass <= 0) {
        return;
    }

    this->mass = newMass;
}

void Animal::setAge(int newAge) {
    if (newAge <= 0) {
        return;
    }

    this->age = newAge;
}

void Animal::setSex(SEX newSex) {
    switch (newSex) {
        case (SEX::MALE):
            this->sex = (char*) "Male";
            break;
        case (SEX::FEMALE):
            this->sex = (char*) "Female";
    }
}

void Animal::setColor(COLOR newColor) {
    switch (newColor) {
        case (COLOR::BLACK):
            this->color = (char*) "Black";
            break;
        case (COLOR::WHITE):
            this->color = (char*) "White";
            break;
        case (COLOR::BROWN):
            this->color = (char*) "Brown";
            break;
        case (COLOR::GREY):
            this->color = (char*) "Grey";
            break;
        case (COLOR::RED):
            this->color = (char*) "Red";
            break;
        case (COLOR::ORANGE):
            this->color = (char*) "Orange";
            break;
        case (COLOR::YELLOW):
            this->color = (char*) "Yellow";
            break;
    }
}

