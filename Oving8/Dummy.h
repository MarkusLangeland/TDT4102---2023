#pragma once
#include <iostream>
#include <utility>

class Dummy
{
public:
    int *num;
    Dummy()
    {
        num = new int{0};
    }
    Dummy(const Dummy &other) : Dummy()
    {
        *num = *other.num;
    }
    ~Dummy()
    {
        delete num;
    }
    Dummy operator=(Dummy d)
    {
        *num = *d.num;
        return d;
    }
};

void dummyTest();