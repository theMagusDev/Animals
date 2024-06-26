// Copyright (C) 2024 Yuriy Magus

#ifndef INCLUDE_FOX_H_
#define INCLUDE_FOX_H_

#include "Animal.h"

enum class TypeFox {
    UNINITIALIZED,
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
    Fox(const char* name, TypeFox type, Sex sex, Color color, int age, float mass);
    Fox(const Fox& ref);
    Fox(Fox&& ref);
    ~Fox();

    char* getName() const;
    char* getType() const;
    int getNumberRabbitsEaten() const;

    void setName(const char* newName);
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


#endif  // INCLUDE_FOX_H_
