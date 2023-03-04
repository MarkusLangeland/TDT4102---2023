#pragma once

double acclY();

double velY(double initVelocityY, double time);

double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

void printTime(double time);

double flightTime(double initVelocity);

double getUserInputTheta();

double getUserInputAbsVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

double getDistanceTraveled(double velocityX, double VelocityY);

double targetPractice(double distanceToTarget, double VelocityX, double VelocityY);

void playTargetPractice();