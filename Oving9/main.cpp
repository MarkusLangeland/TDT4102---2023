
#include "std_lib_facilities.h"
#include "car.h"
#include "person.h"
#include "meeting.h"

#include "widgets/TextInput.h"
#include "widgets/Button.h"

#include "MeetingWindow.h"

//------------------------------------------------------------------------------'

int main()
{
    cout << "Hello, World!" << endl;

    unique_ptr<Car> car2{new Car{1}};
    unique_ptr<Car> car3{new Car{4}};
    // Car c2{3};
    // Car c3{4};

    shared_ptr<Person> p1{new Person{"name1", "name1@gmail.com"}};
    shared_ptr<Person> p2{new Person{"name2", "name2@gmail.com", std::move(car2)}};
    shared_ptr<Person> p3{new Person{"name3", "name3@gmail.com", std::move(car3)}};
    shared_ptr<Person> p4{new Person{"name4", "name4@gmail.com", make_unique<Car>(0)}};

    // cout << *p1 << endl;
    // cout << *p2 << endl;
    // cout << *p3 << endl;
    // cout << *p4 << endl;

    // cout << p1->hasAvailableSeats() << endl;
    // cout << p2->hasAvailableSeats() << endl;
    // cout << p3->hasAvailableSeats() << endl;
    // cout << p4->hasAvailableSeats() << endl;

    Meeting m{2, 11, 12, Campus::Trondheim, "TDT4102", p1};
    m.addParticipants(p2);
    m.addParticipants(p3);
    m.addParticipants(p4);

    cout << m;

    MeetingWindow meetingWin{50, 50, 1300, 700, "Meeting"};
    meetingWin.wait_for_close();
    meetingWin.printAllPeople();

    return 0;
}

//------------------------------------------------------------------------------
