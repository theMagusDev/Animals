// Copyright (C) 2024 Yuriy Magus

#include <iostream>
#include <cstring>
#include "../include/Animal.h"

#define MAX_COLOR_LENGTH 7
#define MAX_SEX_LENGTH 7

Animal::Animal() : mass(0.0), age(0) {
    this->sex = nullptr;
    this->color = nullptr;
}

Animal::Animal(Sex sex, Color color, int age, float mass) {
    this->mass = mass;
    this->age = age;
    setSex(sex);
    setColor(color);
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
        return (char*) "Uninitialized";
    }

    return this->sex;
}

const char* Animal::getColor() const {
    if (this->color == nullptr) {
        return (char*) "Uninitialized";
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

void Animal::setSex(Sex newSex) {
    delete [] this->sex;
    switch (newSex) {
        case (Sex::MALE):
            this->sex = new char[5];
            strcpy(this->sex, "Male");
            break;
        case (Sex::FEMALE):
            this->sex = new char[5];
            strcpy(this->sex, "Male");
            break;
    }
}

void Animal::setColor(Color newColor) {
    delete [] this->color;
    switch (newColor) {
        case (Color::BLACK):
            this->color = new char[6];
            strcpy(this->color, "Black");
            break;
        case Color::WHITE:
            this->color = new char[6];
            strcpy(this->color, "White");
            break;
        case Color::BROWN:
            this->color = new char[6];
            strcpy(this->color, "Brown");
            break;
        case Color::GREY:
            this->color = new char[5];
            strcpy(this->color, "Grey");
            break;
        case Color::RED:
            this->color = new char[4];
            strcpy(this->color, "Red");
            break;
        case Color::ORANGE:
            this->color = new char[7];
            strcpy(this->color, "Orange");
            break;
        case Color::YELLOW:
            this->color = new char[7];
            strcpy(this->color, "Yellow");
            break;
    }
}

