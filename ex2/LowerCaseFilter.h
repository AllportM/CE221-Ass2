/**
 * LowerCaseFilter concrete derived class of ReadFilteredWords, for CE221 Assignment 2 (Ex 2)
 * attains words from a given filename, calling base classes to associate ifstream and attain
 * words, and allows return of valid words containing at least one lowercase letter and no
 * uppercase characters by defining filter function.
 * written by Mal / 1802882 / Ma18533
 */

#ifndef _LOWERCASEF_H
#define _LOWERCASEF_H

using namespace std;
#include <string>
#include "ReadFilteredWords.h"

class LowerCaseFilter: public ReadFilteredWords
{ public:

    /**
     * Constructor. Opens and associated file with the given filename to an ifstream.
     * Program exits with an error message if file does not exist.
     * @param fname - C string naming the file to be read
     */
     LowerCaseFilter(const char *fname):ReadFilteredWords(fname)
     {
     }

     /**
      * Returns a boolean, indicating whether the given input word contains at least one
      * lowercase letter and no uppercase letters
      * @return - bool - whether word satisfies conditions
      */
     bool filter(string word);
};

#endif // _LOWERCASEF_H
