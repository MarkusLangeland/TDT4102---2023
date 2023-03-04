#include "Temps.h"
// #include "std_lib_facilities.h"

istream &operator>>(istream &is, Temps &t)
{
    double iMax, iMin;
    is >> iMax >> iMin;
    if (!is)
    {
        return is;
    }
    t.max = iMax;
    t.min = iMin;

    return is;
}

vector<Temps> readTemps(string fileName)
{
    vector<Temps> tempratures;
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            int index = line.find("\t");
            double max = stod(line.substr(0, index));
            double min = stod(line.substr(index + 1, line.size()));
            cout << max << "-----" << min << endl;
            Temps temp{max, min};
            tempratures.push_back(temp);
        }
    }
    return tempratures;
}

void tempStats(vector<Temps> tempratures)
{
    double highest, lowest;
    int indexHighest, indexLowest;
    int currIndex;
    for (const auto &day : tempratures)
    {
        currIndex += 1;
        if (day.max > highest)
        {
            highest = day.max;
            indexHighest = currIndex;
        }
        if (day.min < lowest)
        {
            lowest = day.min;
            indexLowest = currIndex;
        }
    }
    cout << "Lowest temperature was " << lowest << ", and was on day " << indexHighest << endl;
    cout << "Highest temperature was " << highest << ", and was on day " << indexLowest << endl;
}