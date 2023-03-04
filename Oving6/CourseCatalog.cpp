#include "CourseCatalog.h"

void CourseCatalog::addCourse(string code, string name)
{
    // codesToName.emplace(code, name);
    // codesToName.insert({code, name});
    codesToName[code] = name;
}
void CourseCatalog::removeCourse(string code)
{
    codesToName.erase(code);
}
string CourseCatalog::getCourse(string code)
{
    return codesToName.at(code);
}
ostream &operator<<(ostream &os, const CourseCatalog &c)
{
    string str;
    for (const auto m : c.codesToName)
    {
        str += m.first + " - " + m.second + "\n";
    }
    return os << str;
}

void CourseCatalog::loadCourses()
{
    fstream file;
    file.open("courses.txt", ios::in);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            int index = line.find(';');
            string code = line.substr(0, index);
            string name = line.substr(index + 1, line.size());
            addCourse(code, name);
        }
        file.close();
    }
}
void CourseCatalog::saveCourses()
{
    fstream file;
    file.open("courses.txt", ios::out);
    if (file.is_open())
    {
        for (const auto &c : codesToName)
        {
            file << c.first << ";" << c.second << "\n";
        }
    }
}