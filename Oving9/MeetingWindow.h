#pragma once

#include <iostream>

#include "AnimationWindow.h"

#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "widgets/DropdownList.h"

#include "std_lib_facilities.h"
// #include "person.h"
#include "meeting.h"

static constexpr int pad = 20;
static constexpr int btnW = 130;
static constexpr int btnH = 50;
static constexpr int fieldW = 300;
static constexpr int fieldH = 20;
static constexpr int fieldPad = 100;

class MeetingWindow : public TDT4102::AnimationWindow
{
private:
    vector<std::string> meetingLocationVec{"Trondheim", "Ålesund", "Gjovik"};
    vector<std::string> meetingLeaderVec{""};

    TDT4102::Button createPersonButton;
    TDT4102::Button createMeetingButton;

    // PersonPage:
    TDT4102::Button quitBtn;
    TDT4102::TextInput personName;
    TDT4102::TextInput personEmail;
    TDT4102::TextInput personSeats;
    TDT4102::Button personNewBtn;
    TDT4102::TextInput personData;

    // MeetingPage:
    TDT4102::TextInput meetingSubject;
    TDT4102::TextInput meetingDay;
    TDT4102::TextInput meetingStart;
    TDT4102::TextInput meetingEnd;

    TDT4102::DropdownList meetingLocation;
    TDT4102::DropdownList meetingLeader;

    TDT4102::Button meetingNewBtn;
    TDT4102::TextInput meetingData;

    vector<shared_ptr<Person>> people;
    vector<unique_ptr<Meeting>> meetings;

public:
    MeetingWindow(int x, int y, int w, int h, const std::string &title);
    void cb_quit();
    void cb_new_person();
    void cb_persons();
    void cb_meetings();
    void cb_new_meeting();

    void newPerson();
    void newMeeting();

    void showPersonPage();
    void showMeetingPage();

    void printAllPeople();
};