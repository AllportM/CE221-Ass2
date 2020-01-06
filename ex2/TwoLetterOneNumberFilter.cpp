/**
 * TwoLetterOneNumberFilter concrete derived class of ReadFilteredWords, for CE221 Assignment 2 (Ex 2)
 * attains words from a given filename, calling base classes to associate ifstream and attain
 * words, and returns only valid words containing at least two letters and one digit
 * written by Mal / 1802882 / Ma18533
 */

using namespace std;
#include "TwoLetterOneNumberFilter.h"
#include <string>
#include <cctype>

bool TwoLetterOneNumberFilter::filter(string word)
{
    int lcCount = 0;
    bool numFound = false;
    for (char& c: word) // loops over each char and checks for upper/lower case letters and digits
    {
        if (islower(c) || isupper(c)) lcCount++;
        if (isdigit(c)) numFound = true;
    }
    return (lcCount > 2 && numFound);
}

