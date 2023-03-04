//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "AnimationWindow.h"

//------------------------------------------------------------------------------'

void inputAndPrintInteger()
{
    int number;
    cout << "Skriv inn et tall:" << endl;
    cin >> number;
    cout << "Du skrev: " << number << endl;
}

int inputInteger()
{
    int number;
    cout << "Skriv inn et tall:" << endl;
    cin >> number;
    return number;
}

void inputIntegersAndPrintSum()
{
    int number1 = inputInteger();
    int number2 = inputInteger();
    cout << "Summen av tallene: " << number1 + number2 << endl;
}

bool isOdd(int n)
{
    if (!(n % 2))
    {
        return false;
    }
    return true;
}

void printHumanReadableTime(int n)
{
    int timer = n / 3600;
    int minutt = (n / 60) % 60;
    int sekunder = n % 60;
    cout << timer << " Timer, " << minutt << " Minutter, " << sekunder << " Sekunder" << endl;
}

void printSumNumbers()
{
    int antall;
    cout << "Hvor mange tall vil du legge inn?" << endl;
    cin >> antall;
    int sum = 0;
    for (int x = 0; x < antall; x++)
    {
        sum += inputInteger();
    }
    cout << "Sum: " << sum << endl;
}

void printSumNumbersUntillUserType0()
{
    int sum = 0;
    int tall = 1;
    while (tall != 0)
    {
        int input = inputInteger();
        sum += input;
        tall = input;
    }
    cout << "Sum: " << sum << endl;
}

double inputDouble()
{
    double desimal;
    cout << "Skriv inn et desimaltall:" << endl;
    cin >> desimal;
    return desimal;
}

void convertNOKToEURO()
{
    double Decimal = inputDouble();
    while (Decimal < 0)
    {
        Decimal = inputDouble();
    }
    cout << Decimal / 9.5 << endl;
}

void gangeTabell()
{
    int height = 0;
    int width = 0;
    cout << "Enter height: " << endl;
    cin >> height;
    cout << "Enter width: " << endl;
    cin >> width;
    for (int x = 1; x < height + 1; x++)
    {
        for (int y = 1; y < width + 1; y++)
        {
            cout << "   " << x * y << "   " << ends;
        }
        cout << endl;
    }
}

double discriminant(double a, double b, double c)
{
    return pow(b, 2) - 4 * a * c;
}

void printRealRoots(double a, double b, double c)
{
    if (discriminant(a, b, c) > 0)
    {
        cout << (-b + sqrt(discriminant(a, b, c))) / (2 * a) << endl;
        cout << (-b - sqrt(discriminant(a, b, c))) / (2 * a) << endl;
    }
    else if (discriminant(a, b, c) == 0)
    {
        // cout << (-b + sqrt(discriminant(a, b, c))) / (2 * a) << endl;
        cout << (-b - sqrt(discriminant(a, b, c))) / (2 * a) << endl;
    }
    else if (discriminant(a, b, c) < 0)
    {
        cout << "Ingen løsninger" << endl;
    }
}

void solveQuadraticEquation()
{
    double a;
    double b;
    double c;
    cout << "Skriv inn a:" << endl;
    cin >> a;
    cout << "Skriv inn b:" << endl;
    cin >> b;
    cout << "Skriv inn c:" << endl;
    cin >> c;
    printRealRoots(a, b, c);
}

void Pythagoras()
{
    int w = 1000;
    int h = 1000;
    AnimationWindow win{100, 100, w, h, "Pytagoras"};
    int a = 100;
    int b = 100;

    // Triangle
    Point point1{350, 350};
    Point point2{350, 350 + b};
    Point point3{350 + a, 350 + b};

    // Square 1
    Point point4{350 + a, 350 - b};
    Point point5{350 + 2 * a, 350 + b - a};

    // Square 2
    Point point6{350 - a, 350};
    Point point7{350 - a, 350 + b};

    // Square 3
    Point point8{350, 350 + 2 * b};
    Point point9{350 + a, 350 + 2 * b};

    win.draw_triangle(point1, point2, point3, Color::black);
    win.draw_quad(point1, point4, point5, point3, Color::blue);
    win.draw_quad(point1, point6, point7, point2, Color::green);
    win.draw_quad(point2, point8, point9, point3, Color::red);

    win.wait_for_close();
}

vector<int> calculateBalance(int innskudd, int rente, int antallAr)
{
    vector<int> bankBalance;
    for (int x = 0; x < antallAr; x++)
    {
        int saldo = innskudd * pow((1 + static_cast<double>(rente) / 100), x);
        cout << saldo << endl;
        bankBalance.push_back(saldo);
    }
    return bankBalance;
}

void printBalance(vector<int> bankBalance) {
    cout << "År:    Saldo:" << endl;
    for (int x = 0; x < bankBalance.size(); x++) {
        cout << x << "    " << bankBalance[x] << endl;
    }
}



int main()
{
    //Oppgave 5d:
    //----------
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i <= v.size()-1; i++) {
        cout << v.at(i) << endl;
    }
    //Feilmeldingen kommer fordi for loopen prøver å aksisere et element fra vektoren som ikke eksisterer
    //Dette kan bli fikset ved å ta ende for loopen tidligere ( i <= v.size()-1;)
    //----------

    int valg;
    cout << "0) Avslutt" << endl;
    cout << "1) Summer to tall" << endl;
    cout << "2) Summer flere tall" << endl;
    cout << "3) konverter NOK til Euro" << endl;
    cout << "4) inputAndPrintInteger() (Oppgave 1b)" << endl;
    cout << "5) inputInteger() (Oppgave 1c)" << endl;
    cout << "6) inputIntegersAndPrintSum() (Oppgave 1d)" << endl;
    cout << "7) isOdd() (Oppgave 1f)" << endl;
    cout << "8) printHumanReadableTime() (Oppgave 1g)" << endl;
    cout << "9) printSumNumbersUntillUserType0() (Oppgave 2b)" << endl;
    cout << "10) inputDouble() (Oppgave 2d)" << endl;
    cout << "11) gangeTabell() (Oppgave 2g)" << endl;
    cout << "12) solveQuadraticEquation() (Oppgave 3d)" << endl;
    cout << "13) Pythagoras()" << endl;
    cout << "14) printBalance() (oppgave 5b)" << endl;
    cout << "Angi valg (0-13):" << endl;
    cin >> valg;

    switch (valg)
    {
    case 0:
        // Avslutt()
        break;
    case 1:
        // Avslutt()
        break;
    case 2:
        printSumNumbers();
        break;
    case 3:
        convertNOKToEURO();
        break;
    case 4:
        inputAndPrintInteger();
        break;
    case 5:
        inputInteger();
        break;
    case 6:
        inputIntegersAndPrintSum();
        break;
    case 7:
        isOdd(5);
        break;
    case 8:
        printHumanReadableTime(10000);
        break;
    case 9:
        printSumNumbersUntillUserType0();
        break;
    case 10:
        inputDouble();
        break;
    case 11:
        gangeTabell();
        break;
    case 12:
        solveQuadraticEquation();
        break;
    case 13:
        Pythagoras();
        break;
    case 14:
        printBalance(calculateBalance(5000, 3, 4));
        break;
    default:
        break;
    }

    return 0;
}

//------------------------------------------------------------------------------
