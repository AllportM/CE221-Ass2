/**
 * ReadFilteredWords class for CE221 Assignment 2 (Ex 2) derived class of
 * of ReadWords and to be used as a base class for three separate derived filter classes
 * written by Mal / 1802882 / Ma18533
 */

#include "ReadFilteredWords.h"
#include <string>

using namespace std;

string ReadFilteredWords::getNextFilteredWord()
{
    string word;
    while(ReadWords::isNextWord())
    {
        word = ReadWords::getNextWord();
        if (filter(word)) return word;
    }
    return ""; // returns correct word format or empty string
}
