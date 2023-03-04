#include "cannonball.h"
#include "std_lib_facilities.h"
#include <math.h>
#include "utilities.h"
#include "cannonball_viz.h"

// oppgave 2a)

double acclY()
{
    return -9.81;
}

// oppgave 2b)

double velY(double initVelocityY, double time)
{
    return initVelocityY + acclY() * time;
}

// oppgave 2c)

double posX(double initPosition, double initVelocity, double time)
{
    return initPosition + initVelocity * time;
}

double posY(double initPosition, double initVelocity, double time)
{
    return initPosition + initVelocity * time + (acclY() * time * time) * 0.5;
}

// oppgave 2d)

void printTime(double time)
{
    int hours = time / 3600;
    int minutes = (static_cast<int>(time) / 60) % 60;
    int seconds = static_cast<int>(time) % 60;

    cout << hours << "h, " << minutes << "m, " << seconds << "s" << endl;
}

// oppgave 2e)

double flightTime(double initVelocity)
{
    return (-2 * initVelocity) / acclY();
}

// Opgave 4a)

// Ber brukeren om en vinkel
double getUserInputTheta()
{
    double angle;
    cout << "Input Angle: " << endl;
    cin >> angle;
    return angle;
}
// Ber brukeren om en absoluttfart
double getUserInputAbsVelocity()
{
    double AbsVelocity;
    cout << "Input AbsVelocity: " << endl;
    cin >> AbsVelocity;
    return AbsVelocity;
}
// Konverterer fra grader til radianer
double degToRad(double deg)
{
    return deg * M_PI / 180;
}
// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity)
{
    return absVelocity * cos(theta);
}
double getVelocityY(double theta, double absVelocity)
{
    return absVelocity * sin(theta);
}

double getDistanceTraveled(double velocityX, double VelocityY)
{
    double time = flightTime(VelocityY);
    return time * velocityX;
}

double targetPractice(double distanceToTarget, double VelocityX, double VelocityY)
{
    return abs(distanceToTarget - getDistanceTraveled(VelocityX, VelocityY));
}

void playTargetPractice()
{
    int distanceToTarget = randomWithLimits(100, 1000);
    for (int x = 0; x < 10; x++)
    {
        double angle = getUserInputTheta();
        double initVelocity = getUserInputAbsVelocity();
        double VelocityX = getVelocityX(angle, initVelocity);
        double VelocityY = getVelocityY(angle, initVelocity);
        double distanceFromTarget = targetPractice(distanceToTarget, VelocityX, VelocityY);
        if (distanceFromTarget < 5)
        {
            cout << "Congratulations! You won!" << endl;
            cout << "You was " << distanceFromTarget << "m away from the target" << endl;
            cannonBallViz(distanceToTarget, 1000, VelocityX, VelocityY, 100);
            return;
        }
        cout << "You was " << distanceFromTarget << "m away from the target" << endl;
        cannonBallViz(distanceToTarget, 1000, VelocityX, VelocityY, 100);
    }
    cout << "You Lost!" << endl;
    return;
}
