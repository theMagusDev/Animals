// Copyright (C) 2024 Yuriy Magus

#include <iostream>
#include "../include/Animal.h"

Animal::Animal() : mass(0.0), age(0) {
    this->sex = Sex::UNINITIALIZED;
    this->color = Color::UNINITIALIZED;
}

Animal::Animal(Sex sex, Color color, int age, float mass) {
    this->sex = sex;
    this->color = color;
    this->age = age;
    this->mass = mass;
}

Animal::Animal(const Animal& ref) {
    this->sex = ref.sex;
    this->color = ref.color;
    this->age = ref.age;
    this->mass = ref.mass;
}

Animal::Animal(Animal &&ref) {
    this->color = ref.color;
    this->sex = ref.sex;
    this->age = ref.age;
    this->mass = ref.mass;

    ref.color = Color::UNINITIALIZED;
    ref.sex = Sex::UNINITIALIZED;
    ref.age = 0;
    ref.mass = 0;
}

Animal::~Animal() {
    this->color = Color::UNINITIALIZED;
    this->sex = Sex::UNINITIALIZED;
    this->age = 0;
    this->mass = 0;
}

int Animal::getAge() const {
    return this->age;
}

float Animal::getMass() const {
    return this->mass;
}

const char* Animal::getSex() const {
    switch (this->sex) {
        case (Sex::UNINITIALIZED):
            return const_cast<char *>("None");
        case (Sex::MALE):
            return const_cast<char *>("Male");
        case (Sex::FEMALE):
            return const_cast<char *>("Female");
    }
}

const char* Animal::getColor() const {
    switch (this->color) {
        case (Color::UNINITIALIZED):
            return const_cast<char *>("None");
        case (Color::BLACK):
            return const_cast<char *>("Black");
        case Color::WHITE:
            return const_cast<char *>("White");
        case Color::BROWN:
            return const_cast<char *>("Brown");
        case Color::GREY:
            return const_cast<char *>("Grey");
        case Color::RED:
            return const_cast<char *>("Red");
        case Color::ORANGE:
            return const_cast<char *>("Orange");
        case Color::YELLOW:
            return const_cast<char *>("Yellow");
    }
}

Sex Animal::getSexEnum() const {
    return this->sex;
}

Color Animal::getColorEnum() const {
    return this->color;
}

void Animal::setAge(int newAge) {
    if (newAge <= 0) {
        return;
    }

    this->age = newAge;
}

void Animal::setAnyAge(int newAge) {
    this->age = newAge;
}

void Animal::setMass(float newMass) {
    if (newMass <= 0) {
        return;
    }

    this->mass = newMass;
}

void Animal::setAnyMass(float newMass) {
    this->mass = newMass;
}

void Animal::setSex(Sex newSex) {
    this->sex = newSex;
}

void Animal::setColor(Color newColor) {
    this->color = newColor;
}

