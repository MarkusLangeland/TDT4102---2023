#include "car.h"
#include <cassert>

bool Car::hasFreeSeats() const
{
    return freeSeats > 0;
}
void Car::reservedFreeSeats()
{
    assert(hasFreeSeats());
    freeSeats--;
}

Car::Car(int freeSeats) : freeSeats(freeSeats) {}