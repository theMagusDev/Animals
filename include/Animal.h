// Copyright (C) 2024 Yuriy Magus

#ifndef ANIMALS_ANIMAL_H
#define ANIMALS_ANIMAL_H

enum class Sex {MALE, FEMALE};
enum class Color {BLACK, WHITE, BROWN, GREY, RED, ORANGE, YELLOW};

class Animal {
 public:
    Animal();
    Animal(Sex sex, Color color, int age, float mass);
    Animal(const Animal& ref);
    Animal(Animal&& ref);
    virtual ~Animal();

    int getAge() const;
    float getMass() const;
    const char* getSex() const;
    const char* getColor() const;

    void setMass(float newMass);
    void setAge(int newAge);
    void setSex(Sex newSex);
    void setColor(Color newColor);

    virtual void whatDoesSay() = 0;
 private:
    float mass;
    char* sex;
    char* color;
    int age;
};


#endif //ANIMALS_ANIMAL_H
