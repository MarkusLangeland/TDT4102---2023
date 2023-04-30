//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

// #include "std_lib_facilities.h"
// #include <vector>
// #include <iostream>

#include "iterator.h"
#include <set>
#include "person.h"
#include "templatesFunctions.h"
#include "LinkedList.h"
#include "TemplatesClass.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
    // std::vector<std::string> vec{"Lorem", "Ipsum", "Dolor", "Sit", "Amet"};
    // std::set<std::string> s{"Lorem", "Ipsum", "Dolor", "Sit", "Amet"};

    // iteratorVectorForward(vec);
    // replace(vec, "Lorem", "LOREM");
    // replace(vec, "Ipsum", "IPSUM");
    // replace(vec, "Dolor", "DOLOR");
    // iteratorVectorForward(vec);

    // iteratorSetForward(s);
    // replaceSet(s, "Lorem", "LOREM");
    // replaceSet(s, "Ipsum", "IPSUM");
    // replaceSet(s, "Dolor", "DOLOR");
    // iteratorSetForward(s);

    // std::list<Person> lst;
    // Person p1{"cc", "LastName4"};
    // Person p2{"bc", "LastName3"};
    // Person p3{"aac", "LastName2"};
    // Person p4{"cca", "LastName4"};
    // Person p5{"bca", "LastName3"};
    // Person p6{"aac", "LastName2"};
    // insertOrdered(lst, p1);
    // insertOrdered(lst, p2);
    // insertOrdered(lst, p3);
    // insertOrdered(lst, p4);
    // insertOrdered(lst, p5);
    // insertOrdered(lst, p6);

    // for (auto item : lst)
    // {
    //     std::cout << item << std::endl;
    // }

    // testLinkedList();
    // testTemplateFunc();
    // testLinkedListOverflow();
    testTeplateLinkedList();

    return 0;
}
//------------------------------------------------------------------------------
