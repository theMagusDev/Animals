// Copyright (C) 2024 Yuriy Magus

#ifndef ANIMALS_ANIMAL_H
#define ANIMALS_ANIMAL_H

#include <string>

enum class SEX {MALE, FEMALE};
enum class COLOR {BLACK, WHITE, BROWN, GREY, RED, ORANGE, YELLOW};

class Animal {
 public:
    Animal();
    Animal(SEX sex, COLOR color, int age, float mass);

    Animal(const Animal& ref);
    Animal(Animal&& ref);
    virtual ~Animal();

    float getMass();
    char* getSex();
    int getAge();
    char* getColor();

    void setMass(float newMass);
    void setAge(int newAge);
    void setSex(SEX newSex);
    void setColor(COLOR newColor);

 private:
    float mass;
    char* sex;
    char* color;
    int age;
};


#endif //ANIMALS_ANIMAL_H
