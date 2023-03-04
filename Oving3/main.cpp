//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "cannonball.h"
#include "utilities.h"
#include "std_lib_facilities.h"
#include "cannonball_viz.h"

//------------------------------------------------------------------------------'

void testDeviation(double compareOperand, double toOperand, double maxError, string name);
vector<double> getVelocityVector(double theta, double absVelocity);
bool checkIfDistanceToTargetIsCorrect();
// C++ programs start by executing the function main

int main()
{
    playTargetPractice();
    return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name)
{
    if (abs(compareOperand - toOperand) <= maxError)
    {
        cout << name << " is within max error" << endl;
    }
    cout << name << " is outside max error" << endl;
}

bool checkIfDistanceToTargetIsCorrect()
{
    double error = targetPractice(0, 0, 0);
    // return true;
    if (error == 0.0)
    {
        return true;
    }
    return false;
    // Må alltid ha en return, hvis den er inne i en if blir det ikke returnert noe.
}

vector<double> getVelocityVector(double theta, double absVelocity)
{
    vector<double> velocityXandY;
    velocityXandY.push_back(getVelocityX(theta, absVelocity));
    velocityXandY.push_back(getVelocityY(theta, absVelocity));
    return velocityXandY;
}
//------------------------------------------------------------------------------
