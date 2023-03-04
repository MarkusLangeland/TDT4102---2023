#include "utilities.h"
#include "std_lib_facilities.h"

int randomInt()
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, 10000000);
    return distribution(generator);
}

int randomWithLimits(int min, int max)
{
    return (randomInt()) % (max - min + 1) + min;
}