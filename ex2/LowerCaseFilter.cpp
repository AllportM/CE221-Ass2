/**
 * LowerCaseFilter concrete derived class of ReadFilteredWords, for CE221 Assignment 2 (Ex 2)
 * attains words from a given filename, calling base classes to associate ifstream and attain
 * words, and returns only valid words containing at least one lowercase letter and no
 * uppercase characters.
 * written by Mal / 1802882 / Ma18533
 */

using namespace std;
#include "LowerCaseFilter.h"
#include <string>
#include <cctype>

bool LowerCaseFilter::filter(string word)
{
    bool lcFound = false;
    bool ucFound = false;
    for (char& c: word) // loops over each char and checks for upper/lower case letters
    {
        if (islower(c)) lcFound = true;
        if (isupper(c)) ucFound = true;
    }
    return (lcFound && !ucFound);
}
