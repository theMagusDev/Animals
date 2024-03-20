// Copyright (C) 2024 Yuriy Magus

#ifndef INCLUDE_ANIMAL_H_
#define INCLUDE_ANIMAL_H_

enum class Sex {
    UNINITIALIZED,
    MALE,
    FEMALE
};
enum class Color {
    UNINITIALIZED,
    BLACK,
    WHITE,
    BROWN,
    GREY,
    RED,
    ORANGE,
    YELLOW
};

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

    void setAge(int newAge);
    void setMass(float newMass);
    void setSex(Sex newSex);
    void setColor(Color newColor);

    virtual void whatDoesSay() = 0;

 protected:
    void setAnyAge(int newAge);
    void setAnyMass(float newMass);
    Sex getSexEnum() const;
    Color getColorEnum() const;

 private:
    float mass;
    Sex sex;
    Color color;
    int age;
};


#endif  // INCLUDE_ANIMAL_H_
