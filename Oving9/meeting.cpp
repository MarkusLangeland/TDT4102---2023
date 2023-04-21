
#include "meeting.h"
#include <cassert>

std::map<Campus, std::string> campToString{
    {Campus::Trondheim, "Trondheim"},
    {Campus::Ålesund, "Ålesund"},
    {Campus::Gjøvik, "Gjøvik"},
};

std::ostream &operator<<(std::ostream &os, const Campus c)
{
    os << campToString[c];
    return os;
}

int Meeting::getDay()
{
    return day;
}
int Meeting::getStartTime()
{
    return startTime;
}
int Meeting::getEndTime()
{
    return endTime;
}
Campus Meeting::getLocation()
{
    return location;
}
std::string Meeting::getSubject()
{
    return subject;
}
const shared_ptr<Person> Meeting::getLeader()
{
    return leader;
}

void Meeting::addParticipants(std::shared_ptr<Person> person)
{
    participants.push_back(person);
}

Meeting::Meeting(int day, int startTime, int endTime, Campus location, std::string subject, const shared_ptr<Person> leader)
    : day(day), startTime(startTime), endTime(endTime), location(location), subject(subject), leader(leader)
{
    addParticipants(leader);
}

vector<std::string> Meeting::getParticipantList()
{
    vector<std::string> participantsString;
    for (int i = 0; i < participants.size(); i++)
    {
        participantsString.push_back(participants[i]->getName());
    }
    return participantsString;
}

std::ostream &operator<<(std::ostream &os, Meeting meeting)
{
    os << "startTime: " << meeting.getStartTime() << "\n";
    os << "endTime: " << meeting.getEndTime() << "\n";
    os << "subject: " << meeting.getSubject() << "\n";
    os << "location: " << meeting.getLocation() << "\n";
    vector<std::string> partisipantsList = meeting.getParticipantList();
    for (int i = 0; i < partisipantsList.size(); i++)
    {
        os << "Partisipant " << i << ": " << partisipantsList[i] << "\n";
    }
    return os;
}

std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDrivig(Meeting meeting)
{
    assert(meeting.participants.size() > 0);
    std::vector<std::shared_ptr<Person>> canDrive;
    if ((meeting.startTime - 1 <= this->startTime <= meeting.startTime + 1) && (meeting.endTime - 1 <= this->endTime <= meeting.endTime + 1) && (this->day == meeting.day) && (this->location == meeting.location))
    {
        for (int i = 0; i < meeting.participants.size(); i++)
        {
            if (meeting.participants[i]->hasAvailableSeats())
            {
                canDrive.push_back(meeting.participants[i]);
            }
        }
    }
    return canDrive;
}