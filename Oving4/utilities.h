#pragma once

#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes);
void swapNumbers(int &a, int &b);

struct Student
{
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student student);
bool isInProgram(Student student, string studyProgram);
int randomWithLimits(int min, int max);
string randomizeString(int amount, int min, int max);
string readInputToString(int min, int max, int n);
int countChar(string str, char c);
