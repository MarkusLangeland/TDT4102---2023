#pragma once
#include "std_lib_facilities.h"

struct Temps
{
    double max;
    double min;
};

istream &operator>>(istream &is, Temps &t);
vector<Temps> readTemps(string fileName);
void tempStats(vector<Temps> tempratures);
