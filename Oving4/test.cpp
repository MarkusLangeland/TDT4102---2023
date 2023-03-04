#include "utilities.h"
#include "std_lib_facilities.h"

void testCallByValue()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

void testCallByReference()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations << endl;
}

void testString()
{
    string grades = randomizeString(8, 0, 5);
    int A = countChar(grades, 'A');
    int B = countChar(grades, 'B');
    int C = countChar(grades, 'C');
    int D = countChar(grades, 'D');
    int E = countChar(grades, 'E');
    int F = countChar(grades, 'F');
    vector<int> gradeCount{A, B, C, D, E, F};
    double average = static_cast<double>(A * 5 + B * 4 + C * 3 + D * 2 + E * 1) / (A + B + C + D + E + F);

    cout << grades << endl;
    cout << "Average: " << average << endl;
}
