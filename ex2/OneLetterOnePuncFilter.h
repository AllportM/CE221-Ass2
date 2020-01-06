/**
 * OneLetterOnePuncFilter concrete derived class of ReadFilteredWords, for CE221 Assignment 2 (Ex 2)
 * attains words from a given filename, calling base classes to associate ifstream and attain
 * words, and returns only valid words containing at least one letter and one punctuation.
 * written by Mal / 1802882 / Ma18533
 */

#ifndef _ONELETONEPUNCF_H
#define _ONELETONEPUNCF_H

using namespace std;
#include <string>
#include "ReadFilteredWords.h"

class OneLetterOnePuncFilter: public ReadFilteredWords
{ public:

    /**
     * Constructor. Opens and associated file with the given filename to an ifstream.
     * Program exits with an error message if file does not exist.
     * @param fname - C string naming the file to be read
     */
     OneLetterOnePuncFilter(const char *fname):ReadFilteredWords(fname)
     {
     }

     /**
      * Returns a boolean, indicating whether the given input word contains at least one letter
      * and one punctuation char
      * @return - bool - whether word satisfies conditions
      */
     bool filter(string word);
};

#endif // _ONELETONEPUNCF_H

