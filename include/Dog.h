// Copyright (C) 2024 Yuriy Magus

#ifndef ANIMALS_DOG_H
#define ANIMALS_DOG_H

#include "../include/Animal.h"

enum BREED

class Dog : Animal {

    Dog();
    Dog(Sex sex, Color color, int age, float mass);
    void whatDoesSay() override;
};


#endif //ANIMALS_DOG_H
