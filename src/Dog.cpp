// Copyright (C) 2024 Yuriy Magus

#include "../include/Dog.h"
#include <iostream>

Dog::Dog() : Animal() {}

Dog::Dog(Sex sex, Color color, int age, float mass) : Animal(sex, color, age, mass) {}

void Dog::whatDoesSay() {
    std::cout << "Woof!" << std::endl;
}
