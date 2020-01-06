/**
 * Main class for CE221 Assignment 2 - ex1
 * created by mal 19th Dec 2019
 */
#include "Student.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <stdlib.h>

using namespace std;

// declares the two additional functions ahead of main
void printStudentMaxMarks(list<Student*> theList, float mark);
void printModMarks(const list<Student*> theList, const string module, const float mark);

/**
 * Main's purpose is to prompt the user for two file names, instantiate student objects from
 * those files, initialize an array of pointers to those objects on the heap, perform
 * formatted output as described in the assignment brief.
 *
 * The format of both text files has been set about exactly as the sample files given therefor
 * requiring zero type checking on the inputs.
 *
 * This code is written in a procedural manner, with the brief mentioning only 3 functions
 * for this task. In effect, parts of the code that could be generalized out into functions
 * e.g casting floats from string streams, getlines loops etc have been left procedural.
 *
 * Moreso, the brief has zero mention of outputting the students registration number, although
 * the operator<< is set to output the registration number. It has been assumed that where
 * mention of student name to be output, registration number output is also required
 *
 * @returns
 *      int, arbitrary for main
 */
int main()
{
    /*
     * Part 1 - extrapolates and constructs Student objects from input file
     */
    // prompts user to enter filename and associates it to ifstream object, or re-prompts,
    // or allows user to exit
    cout << "Welcome, please enter a file name containing students to be analysed:"<<endl;
    string filename;
    getline(cin, filename);
    ifstream wordfile(filename);
    while (!wordfile)
    {
        if (filename == "q") exit(1);
        cout << endl <<"Invalid filename '" << filename << "' Please re-enter the filename "
        << "or type 'q' to exit:" << endl;
        getline(cin, filename);
        wordfile.open(filename);
    }

    // initialize variables used throughout main
    string line;
    string name;
    int regNo;
    int regIndexEnd;
    stringstream ss;
    list<Student*> students;
    // formats lines from first file to instantiate students
    while(getline(wordfile, line))
    {
        // puts regno into string stream && outputs into regNo
        regIndexEnd = line.find(' ') + 1;
        ss.str(line.substr(0, regIndexEnd));
        ss >> regNo;
        ss.clear();
        name = (line.substr(regIndexEnd, line.size() - (regIndexEnd+1)));
        Student *s = new Student(name, regNo); // adds to heap
        students.push_front(s);
        name = "";
    }
    wordfile.close();

    /*
     * Part 2 - extrapolates marks from file, same methods as above
     */
    cout << endl<<"Please enter a file name containing the students marks to be analysed:" << endl;
    getline(cin, filename);
    wordfile.open(filename);
    while (!wordfile)
    {
        if (filename == "q") exit(1);
        cout << endl << "Invalid filename '" << filename << "' Please re-enter the filename "
        << "or type 'q' to exit:" << endl;
        getline(cin, filename);
        wordfile.open(filename);
    }

    // extracts module, regNo, and mark from file, again assuming format as per sample provided
    float mark;
    string module;
    while(getline(wordfile, line))
    {
        //string manipulation through use of string stream
        int modIndex = line.find(' ') +1;
        module = line.substr(0, modIndex-1); // module
        regIndexEnd = line.find(' ', modIndex);
        ss.str(line.substr(modIndex, regIndexEnd));
        ss >> regNo; // reg no
        ss.clear();
        ss.str(line.substr(regIndexEnd, line.size() - 1));
        ss >> mark; // mark
        ss.clear();
        // inserts into student objects where reg no matches
        bool studentFound = false;
        for (Student *student: students)
        {
            if (student->getRegNo() == regNo)
            {
                studentFound = true;
                student->addMark(module, mark);
            }
        }
        // error output for reg no not found in students list
        if (!studentFound)
        {
            cout << endl << "Student Not found!\nRegNo: " << regNo << " Module: " << module
            << " Mark: " << mark << endl;
        }
    }

    /*
     * Part 3 - prints each module & marks per student in formatted table
     */
     // presumes like student class, student names will have max width of 20
    ss << endl << "Total students && marks";
    ss << endl << formattedTableLine(3) << endl;
    ss << '|' << left << setfill(' ') <<  setw(20) << "STUDENT NAME" << '|' << right <<
    setw(6) << "REGNO" << '|' << setw(6) << "MOD" << '|' << setw(6) << "MARK" << '|';
    for (const Student *student: students)
    {
        ss << endl << formattedTableLine(3) << endl;
        ss << '|' << left << setw(20) << student->getName() << '|' << right << setw(6)
        << student->getRegNo() << '|';
        bool found = false;
        // loops over all marks a student has, outputting them to screen
        for (auto const &pairEnt: student->getMarks())
        {
            if (found) ss << endl << formattedTableLine(3) << endl << '|'
                << left << setw(20) << student->getName() << '|' << setw(6) <<
                right << student->getRegNo() << '|';
            ss << setw(6) << right << pairEnt.first << '|' << setw(6) << fixed <<
            setprecision(1) << pairEnt.second
            << '|';
            found = true;
        }
        // if student has no marks
        if (!found) ss << right << setw(13) << "no marks" << '|';
    }
    ss << endl << formattedTableLine(3) << endl;
    cout << ss.str();

    /*
     * Part 4 - Loops into options for testing of two additional functions, printStudentMaxMarks
     * and printModMarks
     */
     // outputs welcome and stores user input into line variable
    string entry = string("To test the two additional functions, enter 1 for the first function")
    + string(", 2 for the second function, or q to quit:");
    cout << endl << entry << endl;
    getline(cin, line);
    while(line.compare("q") != 0) // escape clause
    {
        // detects invalid input
        while(line.compare("1") != 0 && line.compare("2") != 0 && line.compare("q") !=0)
        {
            cout << endl << "Invalid input '" << line << "', please try again with 1, 2, or q:"
            << endl;
            getline(cin, line);
            continue;
        }
        string line2;
        // main code for first function
        if (line.compare("1") == 0)
        {
            ss.clear();
            // processes user input
            cout << endl << "Please enter the mark to check, or type 'q' to quit:" << endl;
            getline(cin, line2);
            ss.str(line2);
            mark = 0;
            if (line2 == "q") exit(1);
            // goes onto next iteration to reattain user input upon invalid input given either
            //not a float, or out of range acceptable
            if (!(ss >> mark) || mark < 0 || mark > 100)
            {
                cout << endl << "Invalid mark input given of '" << ss.str() << "' please "
                << "try again:" << endl;
                continue;
            }
            printStudentMaxMarks(students, mark);
        }
        // main code for second function
        if (line.compare("2") == 0)
        {
            ss.clear();
            // processes user input
            cout << endl << "Please enter the module number string:" << endl;
            getline(cin, module);
            cout << endl << "Please enter the mark to check, or type 'q' to quit:" << endl;
            getline(cin, line2);
            ss.str(line2);
            mark = 0;
            if (line2 == "q") exit(1);
            // goes onto next iteration to reattain user input upon invalid input given either
            //not a float, or out of range acceptable
            if (!(ss >> mark) || mark < 0 || mark > 100)
            {
                cout << endl << "Invalid mark input given of '" << ss.str() << "' please "
                << "try again:" << endl;
                continue;
            }
            printModMarks(students, module, mark);
        }
        // re-enters into the main loop to test function 1 or 2 again until 'q' is input
        cout << endl << entry << endl;
        getline(cin, line);
    }
}

/**
 * printStudentMaxMark's purpose is to fulfill the first additional function requirement.
 * Given an input list of pointers to students, each student's minMaxAvg vector is attained
 * and the max is compared against mark input. If the students max mark is greater than or
 * equal to the mark input, the student is output into a neatly formatted table using the
 * operator<<. If no students match the criteria then no student found is output.
 * In addition, the list is sorted utilizing a non-member comparator declared in Student.h/.cpp
 * files.
 *
 * @params:
 *      theList, A list of pointers to students populated through the main function
 *      mark, a float of the users mark to be checked against
 * @returns:
 *      void
 */
void printStudentMaxMarks(const list<Student*> theList, const float mark)
{
    // copies array and sorts
    list<Student*> sortedList(theList);
    sortedList.sort(studCompare);
    // formats mark
    stringstream numStr;
    numStr << fixed << setprecision(1) << mark;
    // prints welcome followed by neatly formatted table header
    cout << endl << endl << "Students whom scored greater than " << numStr.str() << '.' << endl;
    cout << formattedTableLine(4) << endl;
    cout << setfill(' ') << '|' << setw(20) << left << "STUDENT NAME" << '|' << setw(6)
    << right << "REGNO" << '|' << setw(6) << "MIN" << '|' << setw(6) << "MAX" << '|'
    << setw(6) << "AVG" << '|' << endl;
    cout << formattedTableLine(4) << endl;
    // loops over all students to output ones that meet required conditions
    bool found = false;
    for (Student *student: sortedList)
    {
        try
        {
            if (student->getMinMaxAvg().at(1) >= mark)
            {
                cout << *student;
                found = true;
            }
        }
        catch (NoMarkException ignore){}
    }
    // outputs no students found if so
    if (!found) cout << '|' << setfill(' ') << setw(48) << left << "No students found..." << '|'
        << endl << formattedTableLine(4) << endl;
}

/**
 * printModMark's purpose is to fulfill the second additional function requirement from brief.
 * Given an input list of students, a module code, and mark to be checked, every student
 * in the array is searched for whom has attained a mark in that module, and if their mark
 * is less than or equal to the third mark argument.
 *
 * @params:
 *      theList, list of pointers to students on the heap to be searched through
 *      module, the string of module code to be checked, Student file handles uppercase input
 *      mark, float of the mark to be analysed
 * @returns:
 *      void
 */
void printModMarks(const list<Student*> theList, const string module, const float mark)
{
    // outputs intro and neatly formatted table header
    cout << endl << "Students whom scored <= '" << mark << "' in " << module << endl;
    cout << formattedTableLine(2) << endl;
    cout << setfill(' ') << '|' <<left << setw(20) << "STUDENT NAME" << '|' << right
    << setw(6) << "REGNO" << '|' << setw(6) << "MARK" << '|' << endl << formattedTableLine(2) << endl;
    bool found = false;
    // loops over all students in the list to check if they have a mark for the module, and
    // that their mark is <= argument mark
    for (Student *student: theList)
    {
        try
        {
            float studMark = student->getMark(module);
            if (studMark <= mark)
            {
                // outputs is matches
                found = true;
                cout << '|' << left << setw(20) << student->getName() << '|' << right <<
                setw(6) << student->getRegNo() << '|' << setw(6) << fixed << setprecision(1)
                << studMark << '|' << endl << formattedTableLine(2) << endl;
            }
        }
        catch (NoMarkException ignore){}
    }
    // none found output
    if (!found) cout << '|' << left << setw(34) << "No students found..." << '|' << endl <<
        formattedTableLine(2) << endl;
}
