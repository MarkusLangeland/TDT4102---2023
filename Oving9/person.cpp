#include "person.h"

Person::Person(std::string Name, std::string Email, std::unique_ptr<Car> car)
    : name(Name), email(Email), car(std::move(car)) {}

std::string Person::getName()
{
    return name;
}
std::string Person::getEmail()
{
    return email;
}
void Person::setEmail(std::string Email)
{
    email = Email;
}

bool Person::hasAvailableSeats()
{
    if (car == nullptr)
    {
        return false;
    }
    return car->hasFreeSeats();
}

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "Name: " << p.name << "Email: " << p.email << "\n";
    return os;
}
