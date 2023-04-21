#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "std_lib_facilities.h"

#include "person.h"

enum class Campus
{
    Trondheim,
    Ålesund,
    Gjøvik
};

std::ostream &operator<<(std::ofstream &os, const Campus &c);

class Meeting
{
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const shared_ptr<Person> leader;
    vector<shared_ptr<Person>> participants;

public:
    int getDay();
    int getStartTime();
    int getEndTime();
    Campus getLocation();
    std::string getSubject();
    const shared_ptr<Person> getLeader();
    vector<std::string> getParticipantList();

    void addParticipants(std::shared_ptr<Person> person);
    Meeting(int day, int startTime, int endTime, Campus location, std::string subject, const shared_ptr<Person> leader);
    std::vector<std::shared_ptr<Person>> findPotentialCoDrivig(Meeting meeting);
};

std::ostream &operator<<(std::ostream &os, Meeting meeting);
