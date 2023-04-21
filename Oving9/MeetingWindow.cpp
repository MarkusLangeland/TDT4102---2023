#include "MeetingWindow.h"
#include "std_lib_facilities.h"

// #include <cassert>

void MeetingWindow::cb_quit()
{
    AnimationWindow::close();
};

std::map<Campus, std::string> CampToString{
    // Had to have two of theese, (Is another in the meeting.cpp file) and dont know why, the program just chrashed
    {Campus::Trondheim, "Trondheim"},
    {Campus::Ålesund, "Ålesund"},
    {Campus::Gjøvik, "Gjøvik"},
};

MeetingWindow::MeetingWindow(int x, int y, int w, int h, const std::string &title)
    : AnimationWindow{x, y, w, h, title},
      quitBtn{TDT4102::Point{w - btnW - pad, pad}, btnW, btnH, "Quit"},
      personName{TDT4102::Point{fieldPad, pad}, fieldW, fieldH, "Name"},
      personEmail{TDT4102::Point{fieldPad, fieldH + 2 * pad}, fieldW, fieldH, "Email"},
      personSeats{TDT4102::Point{fieldPad, 2 * fieldH + 3 * pad}, fieldW, fieldH, "Car Seats"},
      personNewBtn{TDT4102::Point{fieldPad, pad * 4 + fieldH * 3}, btnW, btnH, "Add person"},
      personData{TDT4102::Point{fieldPad, 3 * fieldH + 5 * pad + btnH + 150}, fieldW * 2, fieldH * 10, ""},
      createPersonButton{TDT4102::Point{w - btnW - pad, 2 * pad + btnH}, btnW, btnH, "Show People"},
      createMeetingButton{TDT4102::Point{w - btnW - pad, 2 * pad + btnH}, btnW, btnH, "Show Meeting"},
      meetingSubject{TDT4102::Point{fieldPad + fieldW, pad}, fieldW, fieldH, "Subject"},
      meetingDay{TDT4102::Point{fieldPad + fieldW, fieldH + 2 * pad}, fieldW, fieldH, "Day"},
      meetingStart{TDT4102::Point{fieldPad + fieldW, 2 * fieldH + 3 * pad}, fieldW, fieldH, "Start time"},
      meetingEnd{TDT4102::Point{fieldPad + fieldW, 3 * fieldH + 4 * pad}, fieldW, fieldH, "End time"},
      meetingLocation{TDT4102::Point{fieldPad + fieldW, 4 * fieldH + 6 * pad}, fieldW, fieldH, meetingLocationVec},
      meetingLeader{TDT4102::Point{fieldPad + fieldW, 5 * fieldH + 7 * pad}, fieldW, fieldH, meetingLeaderVec},
      meetingNewBtn{TDT4102::Point{fieldPad + fieldW, 6 * fieldH + 9 * pad}, fieldW, fieldH, "Add Meeting"},
      meetingData{TDT4102::Point{fieldPad + fieldW, 6 * fieldH + 11 * pad}, 2 * fieldW, 10 * fieldH, ""}
{
    add(quitBtn);
    add(personName);
    add(personEmail);
    add(personNewBtn);
    add(personSeats);
    add(personData);

    add(meetingSubject);
    add(meetingDay);
    add(meetingStart);
    add(meetingEnd);
    add(meetingLocation);
    add(meetingLeader);
    add(meetingNewBtn);
    add(meetingData);

    add(createMeetingButton);
    add(createPersonButton);

    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
    personNewBtn.setCallback(std::bind(&MeetingWindow::cb_new_person, this));
    createMeetingButton.setCallback(std::bind(&MeetingWindow::cb_persons, this));
    createPersonButton.setCallback(std::bind(&MeetingWindow::cb_meetings, this));
    meetingNewBtn.setCallback(std::bind(&MeetingWindow::cb_new_meeting, this));

    showPersonPage();
};

void MeetingWindow::newPerson()
{
    if (personEmail.getText() != "" && personName.getText() != "" && personSeats.getText() != "")
    {
        int freeSeats = stoi(personSeats.getText());
        cout << "New person added" << endl;
        if (freeSeats > 0)
        {
            unique_ptr<Car> car{new Car{stoi(personSeats.getText())}};
            people.emplace_back(new Person{personName.getText(), personEmail.getText(), std::move(car)});
            meetingLeaderVec.emplace_back(personName.getText());
        }
        else
        {
            people.emplace_back(new Person{personName.getText(), personEmail.getText()});
            meetingLeaderVec.emplace_back(personName.getText());
        }
        meetingLeader.setOptions(meetingLeaderVec);
        personName.setText("");
        personEmail.setText("");
        personSeats.setText("");
        // vector<std::string> partisipants =  people.getParticipantList();
        std::string peopleList = "";
        for (int i = 0; i < people.size(); i++)
        {
            std::string availableSeats = people[i]->hasAvailableSeats() ? "True" : "False";
            peopleList += "Name: " + people[i]->getName() + ", Email: " + people[i]->getEmail() + ", free seats " + availableSeats + "\n";
        }
        personData.setText(
            peopleList);
    }
}

void MeetingWindow::cb_new_person()
{
    newPerson();
}

void MeetingWindow::printAllPeople()
{
    for (int i = 0; i < people.size(); i++)
    {
        cout << (*people[i]) << endl;
    }
}

void MeetingWindow::showPersonPage()
{
    createPersonButton.setVisible(true);
    createMeetingButton.setVisible(false);

    personName.setVisible(true);
    personEmail.setVisible(true);
    personSeats.setVisible(true);
    personNewBtn.setVisible(true);
    personData.setVisible(true);

    meetingSubject.setVisible(false);
    meetingDay.setVisible(false);
    meetingStart.setVisible(false);
    meetingEnd.setVisible(false);
    meetingLocation.setVisible(false);
    meetingLeader.setVisible(false);
    meetingData.setVisible(false);
    meetingNewBtn.setVisible(false);
}
void MeetingWindow::showMeetingPage()
{
    createPersonButton.setVisible(false);
    createMeetingButton.setVisible(true);

    personName.setVisible(false);
    personEmail.setVisible(false);
    personSeats.setVisible(false);
    personNewBtn.setVisible(false);
    personData.setVisible(false);

    meetingSubject.setVisible(true);
    meetingDay.setVisible(true);
    meetingStart.setVisible(true);
    meetingEnd.setVisible(true);
    meetingLocation.setVisible(true);
    meetingLeader.setVisible(true);
    meetingData.setVisible(true);
    meetingNewBtn.setVisible(true);
}

void MeetingWindow::cb_persons()
{
    showPersonPage();
}
void MeetingWindow::cb_meetings()
{
    showMeetingPage();
}

int getIndex(vector<string> v, string K)
{
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {

        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    return -1;
}

void MeetingWindow::newMeeting()
{
    cout << "Yooooooooooo";
    if (meetingSubject.getText() != "" && meetingDay.getText() != "" && meetingStart.getText() != "" && meetingEnd.getText() != "" && meetingLeader.getValue() != "")
    {
        // cout << people[getIndex(meetingLeaderVec, meetingLeader.getValue())-1];
        // cout << find(meetingLeaderVec.begin(), meetingLeaderVec.end(), meetingLeader.getValue()) - meetingLeaderVec.begin();
        cout << "Inside:1";

        shared_ptr<Person> leader = people.at(getIndex(meetingLeaderVec, meetingLeader.getValue()) - 1);
        cout << "Inside:2";

        // cout << getIndex(meetingLocationVec ,meetingLocation.getValue());
        Campus location = Campus{getIndex(meetingLocationVec, meetingLocation.getValue())};
        cout << "Inside:3";

        meetings.emplace_back(std::make_unique<Meeting>(stoi(meetingDay.getText()), stoi(meetingStart.getText()), stoi(meetingEnd.getText()), location, meetingSubject.getText(), leader));
        cout << "Inside:4";

        // Show meeting:
        string text = "";
        for (int i = 0; i < meetings.size(); i++)
        {
            text += "Day " + to_string(meetings[i]->getDay()) + ": " + CampToString[meetings[i]->getLocation()] + ", " + to_string(meetings[i]->getStartTime()) + " - " + to_string(meetings[i]->getEndTime()) + "\n";
        }
        meetingData.setText(text);
    }
}

void MeetingWindow::cb_new_meeting()
{
    newMeeting();
}
