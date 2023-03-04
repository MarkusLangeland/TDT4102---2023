#include "utilities.h"
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
}

void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printStudent(Student student)
{
    cout << "Name: " << student.name << endl;
    cout << "Study program: " << student.studyProgram << endl;
    cout << "Age: " << student.age << endl;
}

bool isInProgram(Student student, string studyProgram)
{
    if (student.studyProgram == studyProgram)
    {
        return true;
    }
    return false;
}

// From exercise 3:
int randomInt()
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, 10000000);
    return distribution(generator);
}
int randomWithLimits(int min, int max)
{
    return (randomInt()) % (max - min + 1) + min;
}

string randomizeString(int amount, int min, int max)
{
    string randomizedString;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int x = 0; x < amount; x++)
    {
        int randNum = randomWithLimits(min, max);
        randomizedString += alphabet[randNum];
    }
    return randomizedString;
}

string makeUpper(string text)
{
    string tempStr = "";
    for (int x = 0; x < size(text); x++)
    {
        tempStr += toupper(text[x]);
    }
    return tempStr;
}

string readInputToString(int min, int max, int n)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string input;
    cout << "Write a string " << n << " letters wide" << endl;
    cin >> input;
    string inputUpper = makeUpper(input);

    int allLettersInsideBound = 0;
    for (int x = 0; x < size(inputUpper); x++)
    {
        if (alphabet.find(inputUpper[x]) > min || alphabet.find(inputUpper[x]) < max)
        {
            allLettersInsideBound += 1;
        }
    }
    while (allLettersInsideBound != n)
    {
        cout << "String was not inside bound, or wrong length!" << endl;
        cout << "Write a string " << n << " letters wide" << endl;
        cin >> input;
        string inputUpper = makeUpper(input);
        allLettersInsideBound = 0;
        for (int x = 0; x < size(inputUpper); x++)
        {

            if (alphabet.find(inputUpper[x]) > min || alphabet.find(inputUpper[x]) < max)
            {
                allLettersInsideBound += 1;
            }
        }
    }
    return inputUpper;
}

int countChar(string str, char c)
{
    int amount = 0;
    for (int x = 0; x < size(str); x++)
    {
        if (str[x] == c)
        {
            amount += 1;
        }
    }
    return amount;
}