// Copyright (C) 2024 Yuriy Magus

#ifndef ANIMALS_FOX_H
#define ANIMALS_FOX_H

#include "Animal.h"

enum class TypeFox {
    ARCTIC,
    FENNEC,
    CORSAC,
    BENGAL,
    SWIFT,
    KIT
};

class Fox : public Animal {
 public:
    Fox();
    Fox(char* name, TypeFox type, Sex sex, Color color, int age, float mass);
    Fox(const Fox& ref);
    Fox(Fox&& ref);
    ~Fox();

    char* getName();
    char* getType();
    int getNumberRabbitsEaten();

    void setName(char* newName);
    void setType(TypeFox newType);

    void eat();
    void whatDoesSay() override;

    Fox& operator=(const Fox& other);
    Fox& operator=(Fox&& other);

 private:
    char* name;
    TypeFox type;
    int numberRabbitsEaten;
};


#endif //ANIMALS_FOX_H
