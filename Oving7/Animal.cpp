#include "Animal.h"

Animal::Animal(string Name, int Age)
{
    name = Name;
    age = Age;
}

Animal::~Animal()
{
}

string Animal::toString()
{
    string text = "Animal: " + name + ", " + to_string(age);
    return text;
}

string Dog::toString()
{
    string text = "Dog: " + name + ", " + to_string(age);
    return text;
}
string Cat::toString()
{
    string text = "Cat: " + name + ", " + to_string(age);
    return text;
}

void testAnimal()
{
    // Part 1:
    //  Animal A("name1", 12);
    //  Cat C("name2", 13);
    //  Dog D("name3", 14);
    //  cout << A.toString() << endl;
    //  cout << C.toString() << endl;
    //  cout << D.toString() << endl;

    vector<std::unique_ptr<Animal>> animals;
    // animals.emplace_back(new Animal("name1", 3)); You cannot do this anymore because Animal class is abstract
    animals.emplace_back(new Dog("name2", 7));
    animals.emplace_back(new Cat("name3", 5));

    cout << "inside TestAnimal" << endl;
    for (int i = 0; i < animals.size(); i++)
    {
        cout << animals.at(i)->toString() << endl;
    }
}