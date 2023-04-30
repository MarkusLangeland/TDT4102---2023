
#include "person.h"

Person::Person(std::string firstName, std::string lastName) : firstName(firstName), lastName(lastName){};

std::string Person::getFirstName() const
{
    return firstName;
}
std::string Person::getLastName() const
{
    return lastName;
}

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.getFirstName() << " " << p.getLastName() << "\n";
    return os;
}

void insertOrdered(std::list<Person> &l, const Person &p)
{
    for (auto it = l.begin(); it != l.end(); it++)
    {
        if ((it->getFirstName() + it->getLastName()) > (p.getFirstName() + p.getLastName()))
        {

            l.insert(it, p);
            return;
        }
    }
    l.push_back(p);
}