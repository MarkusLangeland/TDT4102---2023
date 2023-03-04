//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "CourseCatalog.h"
#include "Temps.h"
#include <iostream>

//------------------------------------------------------------------------------'
void task1a()
{
    string line;
    string lines;
    std::filesystem::path task1{"Task1.txt"};
    std::ofstream outputStream{task1};

    cout << "Write a line you want to save to file, write quit to end." << endl;
    while (line != "quit")
    {
        cin >> line;
        if (line != "quit")
        {
            lines += line + "\n";
        }
    }

    outputStream << lines << "\n";
}

void task1b()
{
    fstream file;
    file.open("Task1.txt", ios::in);
    fstream newFile;
    newFile.open("Task1b.txt", ios::out);
    if (file.is_open())
    {
        string line;
        int linenumber = 0;
        while (getline(file, line))
        {
            linenumber += 1;
            newFile << linenumber << " - " << line << endl;
        }
        file.close();
    }
}

void task2a()
{
    fstream file;
    file.open("grunnlov.txt", ios::in);
    string line;

    map<char, int> lettercount;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            for (int x = 0; x < line.size(); x++)
            {
                if (isalpha(line[x]))
                {
                    lettercount[tolower(line[x])] = lettercount[tolower(line[x])] + 1;
                }
            }
        }
    }
    for (const auto &m : lettercount)
    {
        cout << m.first << " : " << m.second << endl;
    }
}

const map<string, string> capitalsMap{
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}};

string getCapital(const string &country)
{
    return capitalsMap.at(country);
}

void task2b()
{
    std::cout << "Capitals:" << std::endl;
    for (pair<const string, const string> elem : capitalsMap)
    {
        cout << getCapital(elem.first) << std::endl;
    }
}

// C++ programs start by executing the function main
int main()
{
    CourseCatalog c;
    c.loadCourses();
    c.addCourse("TMA1234", "Test 1");
    c.addCourse("TMA1235", "Test 2");
    c.saveCourses();
    vector<Temps> tempratures = readTemps("temperatures.txt");


    cout << "Write a number from 1 - 4" << endl;
    int input;
    cin >> input;
    switch (input)
    {
    case 1:
        task1a();
        break;
    case 2:
        task1b();
        break;
    case 3:
        task2a();
        break;
    case 4:
        task2b();
        break;
    case 5:
        tempStats(tempratures);
        break;
    default:
        break;
    }
    return 0;
}

//------------------------------------------------------------------------------
