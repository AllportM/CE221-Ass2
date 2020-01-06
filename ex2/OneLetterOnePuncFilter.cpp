/**
 * OneLetterOnePuncFilter concrete derived class of ReadFilteredWords, for CE221 Assignment 2 (Ex 2)
 * attains words from a given filename, calling base classes to associate ifstream and attain
 * words, and returns only valid words containing at least one letter and one punctuation char
 * written by Mal / 1802882 / Ma18533
 */

using namespace std;
#include "OneLetterOnePuncFilter.h"
#include <string>
#include <cctype>

bool OneLetterOnePuncFilter::filter(string word)
{
    bool letFound = false;
    bool puncFound = false;
    for (char& c: word) // loops over each char and checks for upper/lower case letters and punct
    {
        if (islower(c) || isupper(c)) letFound = true;
        if (ispunct(c)) puncFound = true;
    }
    return (letFound && puncFound);
}

