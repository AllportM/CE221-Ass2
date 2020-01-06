#include "Student.h"
#include <numeric>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Student::Student(const string& name, int regNo): Person(name), marks()
{
    this->regNo = regNo;
}

int Student::getRegNo() const { return regNo; }

void Student::addMark(const string& module, float mark)
{
    // converts module to uppercase, and add's or updates mark
    // additionally uses range checking on input
    string moduleUpper = setToUpper(string(module));
    if(mark >= 0.0 && mark <= 100.0)
    {
        if(!marks.insert(make_pair(moduleUpper, mark)).second)
        {
            marks[moduleUpper] = mark;
        }
    }
    else cout << "Error, module " << module << " with mark of " << mark << " is out of valid"
        << "range and has not been added." << endl;
}

float Student::getMark(const string&module) const
{
    // converts module to uppercase and finds a score related to module or throws error
    string moduleUpper = setToUpper(string(module));
    map<string, float>::const_iterator found = marks.find(moduleUpper);
    if (found == marks.end()) throw NoMarkException();
    return found->second;
}

vector<float> Student::getMinMaxAvg() const
{
    if (!(marks.size() > 0)) throw NoMarkException();
    // loops through marks and instantiates vector containing min/max/avg
    float myMin, myMax, sum = 0;
    myMin = myMax = marks.begin()->second;
    for(const auto &it: marks)
    {
        myMin = (it.second < myMin)? it.second: myMin;
        myMax = (it.second > myMax)? it.second: myMax;
        sum += it.second;
    }
    float temp[] = {myMin, myMax, sum / marks.size()};
    vector<float> minMaxAvg(temp, temp+3);
    return minMaxAvg;
}

map<string, float> Student::getMarks() const
{
    return marks;
}

ostream &operator<<(ostream &str, const Student &s)
{
    // outputs required format onto stream, either student with marks or without
    try
    {
        vector<float> stats = s.getMinMaxAvg();
        str << setfill(' ') << "|" << left << setw(20) << s.getName() << "|" << right
        << setw(6) << s.getRegNo() << "|" << setw(6) << fixed << setprecision(1)
        << stats.at(0) << "|" << setw(6) << stats.at(1) << "|" << setw(6) << stats.at(2)
        << "|" << endl;
        str << formattedTableLine(4) << endl;
    }
    catch (NoMarkException e)
    {
        str << "|" << left << setfill(' ') << setw(48) << s.getName() + " has no marks" << "|";
    }
    return str;
}

bool studCompare(const Student *first, const Student *second)
{
    return first->getRegNo() < second->getRegNo();
}

string formattedTableLine(const int noExtras)
{
    stringstream str;
    str << setfill('-') << '+' << setw(20) << '-' << '+';
    for (int i = 0; i < noExtras; i++)
    {
        str << setw(6) << '-' << '+';
    }
    return str.str();
}

string setToUpper(string toConvert)
{
    for (string::iterator it = toConvert.begin(); it != toConvert.end(); it++)
    {
        *it = toupper(*it);
    }
    return toConvert;
}
