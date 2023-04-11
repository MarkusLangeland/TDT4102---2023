#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow &) = 0;
    virtual ~Emoji(){}; // destruktør
};

class Face : public Emoji
{
protected:
    Point center;
    int radius;

public:
    Face(Point c, int r);
    void draw(AnimationWindow &win) override = 0;
};

class EmptyFace : public Face
{
private:
    Point RightEye;
    Point LeftEye;
    int EyeRadius;

public:
    EmptyFace(Point c, int r);
    void draw(AnimationWindow &win) override;
};

class SmilingFace : public EmptyFace
{
private:
    Point mouth;
    int width = 40;
    int height = 30;
    int startDeg = 180;
    int endDeg = 360;
    Color color = Color::black;
    Point TextPos;

public:
    SmilingFace(Point c, int r);
    void draw(AnimationWindow &win) override;
};

class SadFace : public EmptyFace
{
private:
    Point mouth;
    int width = 40;
    int height = 30;
    int startDeg = 0;
    int endDeg = 180;
    Color color = Color::black;

    Point TextPos;

public:
    SadFace(Point c, int r);
    void draw(AnimationWindow &win) override;
};

class AngryFace : public SadFace
{
private:
    Point RightEyebrowStart;
    Point RightEyebrowEnd;
    Point LeftEyebrowStart;
    Point LeftEyebrowEnd;
    Point TextPos;
    Color color = Color::black;

public:
    AngryFace(Point c, int r);
    void draw(AnimationWindow &win) override;
};

class WinkingFace : public Face
{
private:
    Point rightEye;
    Point leftEye;
    Point mouth;
    int eyeRadius;

    int width = 40;
    int height = 30;
    int startDeg = 180;
    int endDeg = 360;

    Point TextPos;

public:
    WinkingFace(Point c, int r);
    void draw(AnimationWindow &win) override;
};

class SurprisedFace : public EmptyFace
{
private:
    Point mouth;
    int mouthRadius = 10;
    Point TextPos;

public:
    SurprisedFace(Point c, int r);
    void draw(AnimationWindow &win) override;
};