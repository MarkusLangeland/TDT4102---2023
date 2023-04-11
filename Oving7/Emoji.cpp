#include "Emoji.h"

void Face::draw(AnimationWindow &win)
{
    win.draw_circle(center, radius, Color::yellow, Color::black);
}

Face::Face(Point c, int r)
{
    center = c;
    radius = r;
}

EmptyFace::EmptyFace(Point c, int r) : Face(c, r)
{
    RightEye = {c.x + 30, c.y - 40};
    LeftEye = {c.x - 30, c.y - 40};
    EyeRadius = r / 5;
}

void EmptyFace::draw(AnimationWindow &win)
{
    Face::draw(win);
    win.draw_circle(LeftEye, EyeRadius, Color::white, Color::black);
    win.draw_circle(RightEye, EyeRadius, Color::white, Color::black);
    // win.draw_circle({LeftEye.x, LeftEye.y + 5}, EyeRadius / 5, Color::black);   // Pupil
    // win.draw_circle({RightEye.x, RightEye.y + 5}, EyeRadius / 5, Color::black); // Pupil
}

SmilingFace::SmilingFace(Point c, int r) : EmptyFace(c, r)
{
    mouth = {c.x, c.y + 30};
}

void SmilingFace::draw(AnimationWindow &win)
{
    EmptyFace::draw(win);
    win.draw_arc(mouth, width, height, startDeg, endDeg, color);
}

SadFace::SadFace(Point c, int r) : EmptyFace(c, r)
{
    mouth = {c.x, c.y + 40};
}

void SadFace::draw(AnimationWindow &win)
{
    EmptyFace::draw(win);
    win.draw_arc(mouth, width, height, startDeg, endDeg, color);
}

AngryFace::AngryFace(Point c, int r) : SadFace(c, r)
{
    RightEyebrowStart = {c.x + 15, c.y - 60};
    RightEyebrowEnd = {c.x + 40, c.y - 80};
    LeftEyebrowStart = {c.x - 15, c.y - 60};
    LeftEyebrowEnd = {c.x - 40, c.y - 80};
}
void AngryFace::draw(AnimationWindow &win)
{
    SadFace::draw(win);
    win.draw_line(RightEyebrowStart, RightEyebrowEnd, color);
    win.draw_line(LeftEyebrowStart, LeftEyebrowEnd, color);
}

WinkingFace::WinkingFace(Point c, int r) : Face(c, r)
{
    rightEye = {c.x + 30, c.y - 30};
    leftEye = {c.x - 30, c.y - 40};
    eyeRadius = r / 5;
    mouth = {c.x, c.y + 30};
}
void WinkingFace::draw(AnimationWindow &win)
{
    Face::draw(win);
    win.draw_circle(leftEye, eyeRadius, Color::white, Color::black);
    win.draw_arc(mouth, width, height, startDeg, endDeg, Color::black);
    win.draw_arc(rightEye, eyeRadius, eyeRadius, 0, 160);
}

SurprisedFace::SurprisedFace(Point c, int r) : EmptyFace(c, r)
{
    mouth = {c.x, c.y + 40};
}
void SurprisedFace::draw(AnimationWindow &win)
{
    EmptyFace::draw(win);
    win.draw_circle(mouth, mouthRadius, Color::white, Color::black);
}