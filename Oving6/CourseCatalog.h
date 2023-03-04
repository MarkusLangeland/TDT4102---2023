#pragma once
#include "std_lib_facilities.h"

class CourseCatalog
{
private:
    map<string, string> codesToName;
    string test = "Yooo";

public:
    void addCourse(string code, string name);
    void removeCourse(string code);
    string getCourse(string code);
    void loadCourses();
    void saveCourses();
    friend ostream& operator<<(ostream& os, const CourseCatalog& c);
};
