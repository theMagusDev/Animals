// Copyright (C) 2024 Yuriy Magus

#ifndef ANIMALS_ANIMAL_H
#define ANIMALS_ANIMAL_H

#include <string>

class Animal {
 public:
    Animal();
    Animal(float mass, char* sex, const char* color, int age);

    Animal(const Animal& ref);

    virtual ~Animal();

    float getMass();
    char* getSex();
    int getAge();
    char* getColor();

    void setMass(float newMass);
    void setSex(char* newSex);

 private:
    float mass;
    char* sex;
    char* color;
    int age;
};


#endif //ANIMALS_ANIMAL_H
