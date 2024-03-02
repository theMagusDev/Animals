//
// Created by Yuriy on 02.03.2024.
//

#include "../include/Animal.h"

enum gender {MALE, FEMALE};

char* gender[] = {[MALE]="Male", [FEMALE]="Female"};

float Animal::getMass() {
    return this->mass;
}

int Animal::getAge() {
    return this->age;
}

char* Animal::getSex() {
    return this->sex;
}

char* Animal::getColor() {
    return color;
}

void Animal::setMass(float newMass) {
    if (newMass <= 0) {
        return;
    }

    this->mass = newMass;
}

void setSex(char* newSex) {
    if (newMass <= 0) {
        return;
    }

    this->mass = newMass;
}
