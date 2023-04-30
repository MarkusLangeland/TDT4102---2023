#pragma once
#include "iostream"
#include <list>

class Person
{
private:
    std::string firstName;
    std::string lastName;

public:
    Person(std::string firstName, std::string lastName);
    std::string getFirstName() const;
    std::string getLastName() const;
};

void insertOrdered(std::list<Person> &l, const Person &p);

std::ostream &operator<<(std::ostream &os, const Person &obj);