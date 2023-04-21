#pragma once
#include <iostream>
#include "car.h"
#include <memory>
// #include "std_lib_facilities.h"

class Person
{
private:
    std::string name;
    std::string email;
    std::unique_ptr<Car> car;

public:
    Person(std::string Name, std::string Email, std::unique_ptr<Car> car = nullptr);
    std::string getName();
    std::string getEmail();
    void setEmail(std::string Email);
    bool hasAvailableSeats();
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
};
