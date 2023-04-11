#pragma once

#include "std_lib_facilities.h"

class Animal
{
protected:
    string name;
    int age;

public:
    Animal(string Name, int Age);
    virtual ~Animal();
    // viritual ~Animal();
    virtual string toString() = 0;
};

class Cat : public Animal
{
public:
    Cat(string Name, int Age) : Animal(Name, Age){};
    string toString() override;
};

class Dog : public Animal
{
public:
    Dog(string Name, int Age) : Animal(Name, Age){};
    string toString() override;
};

void testAnimal();