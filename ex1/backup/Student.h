/**
 * Student class for CE221 Assignment 2 - ex1
 * created by msands, edited by mal 19th Dec 2019
 */

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <map>
#include <stdexcept>
#include <vector>
#include "Person.h"

using namespace std;

class NoMarkException: public exception
{
};

/**
 * Student's purpose is to extend the base Person class with additional methods and data members
 * for storing student's marks, calculating statistical values, and overriding the ostream friend
 * function for desired output.
 */
class Student: public Person
{   public:
        /**
         * Standard constructor, given a no arg constructor not required for assignment.
         *
         * @param:
         *  name, const string of the students name value
         *  regNo, int value of the students registration number
         */
        Student(const string &name, int regNo);

	   /**
	    * getRegNo's purpose is to return the students registration number.
	    *
        * @param:
        *   None
        * @returns:
        *   int, student's reg no
	    */
	   int getRegNo() const;

	   /**
	    * addMark's purpose is to insert/update a students mark for a given value, stored within
	    * the Student's map<String, float> data member marks.
	    *
	    * @params:
	    *   module, const string value of the module code
	    *   mark, float value of the students mark
	    * @returns:
        *   None
	    */
	   void addMark(const string& module, float mark);

	   /**
	    * getMark's purpose is to return the mark a student has attained for a specific module
	    *
	    * @params:
	    *   module, const string of the given module code
	    * @returns:
	    *   float, the students mark for the given input module
	    */
	   float getMark(const string &module) const;

	   /**
	    * getMinMaxAvg's purpose is to return a vector containing three elements, the Student's
	    * minimum, maximum, and average marks.
	    *
	    * @params:
	    *   None
	    * @returns:
	    *   vector<float>, vector containing minimum at position 0, maximum pos 1, avg pos 2
	    */
	   vector<float> getMinMaxAvg() const;

	   /**
	    * operator<'s purpose is to overload the less than comparitor so that sort algorithms
	    * and/or non random-access iterator sort methods can be utilized which use < operator
	    * by comparing the regNo
	    *
	    * @params:
	    *   &other, reference to the Student object to be compared against
	    * @returns:
	    *   bool, indicating true if this instances regNo is less than the one supplied as argument
	    */
	   bool operator<(const Student &other) const;

	   map<string, float> getMarks() const;

    private:
	   int regNo; // students registration number
	   map<string, float> marks;  // a map containing students marks, values, for a given module, key

    /**
     * friend function's main responsibility is to allow outputting of the student objects
     * to an ostream in a formatted manner befitting of the brief i.e name, regno, minimum,
     * maximum, and average marks. This has been done in a neat table format.
     * Although error handling has been introduced for zero marks, given the only place this
     * is used is for when a student has a mark >= an input mark for comparison, it's pretty
     * irrelevant functionality.
     */
    friend ostream& operator<<(ostream &str, const Student &s);
};
// although the following are not member functions, they are, or at least one is, required outisde
// of the 3 functions required to be written in main for sorting. The other two give additional
// functionality for some generalization

/**
 * studCompare's purpose is to be passed as comparator function argument for use in sorting
 * a list of students by registration number
 *
 * @params:
 *      *first, pointer to a Student to be compared to
 *      *second, pointer to a second Student instance to be compared agains
 * @returns:
 *      boolean, indicating if student 1's regNo is less than student 2's
 */
bool studCompare(const Student *first, const Student *second);

/**
 * formattedTableLine's purpose is to return a string containing '-' and '+' characters to suit
 * the table being printed, given the argument specifies how many 6 width -'s and +'s are to
 * be output
 *
 * @params:
 *      noExtras, integer indicating how many 6 field width -'s and +'s to output
 * @returns:
 *      string, formatted line for the table
 */
string formattedTableLine(const int noExtras);

/**
 * setToUpper's purpose is to take an input string, and change all of the alpha characters to
 * their uppercase counterparts
 *
 * @params:
 *      toConvert, string requiring converting
 * @returns:
 *      string, converted string
 */
string setToUpper(string toConvert);

#endif
