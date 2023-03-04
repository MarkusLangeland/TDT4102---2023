//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

#include "utilities.h"
#include "test.h"
#include "mastermind.h"
#include "masterVisual.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
    // 1a)
    // Verdien for V0 er uendret, den vil skrive 5 til skjermen, men result vil være 25.

    // Variables created for testing of functions:
    int a = 5;
    int b = 10;
    Student student{"Linus", "MTELSYS", 21};

    int input;
    cout << "What function do you want to test? (Number 1-10)" << endl;
    cin >> input;
    switch (input)
    {

    case 1:
        testCallByValue();
        break;
    case 2:
        testCallByReference();
        break;
    case 3:
        cout << "Before swap: a = " << a << ", b = " << b << endl;
        swapNumbers(a, b);
        cout << "After swap: a = " << a << ", b = " << b << endl;
        break;
    case 4:
        printStudent(student);
        break;
    case 5:
        cout << isInProgram(student, "MTELSYS") << endl;
        cout << isInProgram(student, "Kybernetikk og robotikk") << endl;
        break;
    case 6:
        testString();
        break;
    case 7:
        readInputToString(0, 9, 6);
        break;
    case 8:
        cout << countChar("ABBAGGH", 'A');
        break;
    case 9:
        playMastermind();
        break;
    case 10:
        playMastermindVisual();
        break;
    default:
        break;
    }

    return 0;
}

//------------------------------------------------------------------------------
