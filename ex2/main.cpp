/**
 * Main class created to test functionality of ReadWords and all derived classes for Assignment
 * 2 (Ex 2).
 * Attains filename from user to be analysed, which filter they would like to test,
 * and then creates a map counting the frequency of occurrences displaying them as required.
 * Created by Mal - 1802882 - Ma18533
 */

#include <iostream>
#include <algorithm>
#include "LowerCaseFilter.h"
#include "OneLetterOnePuncFilter.h"
#include "TwoLetterOneNumberFilter.h"

using namespace std;

int main()
{
    // attains filename from user
    cout << "Welcome, please enter a file name containing words to be analysed:"
    << endl << "> ";
    string filename;
    getline(cin, filename); // attains user input for filename to be checked
    ifstream temp(filename);

    // engages loop to get correct filename, although invalidates the exit clause
    // of ReadWords derived classes this seems more convenient if wrong filename given
    while(!temp)
    {
        if (filename == "q") exit(1);
        cout << "Invalid filename '" << filename << "'" << endl << "Please re-enter "
        << "the filename, or type 'q' to quit:" << endl << "> ";
        getline(cin, filename);
        temp.open(filename);
    }
    temp.close();


    string filterString = "";
    ReadFilteredWords* filter;
    while (filterString.compare("q") != 0)
    {
        cout << endl << "Please enter the filter to be tested." << endl << "1 - At least "
        << "one lowercase letter and no uppercase letters." << endl << "2 - At least two letters "
        << "and one digit." << endl << "3 - At least one letter and one punctuation character."
        << endl << "q - quit" << endl << "> ";
        getline(cin, filterString); // attains input for option to be tested

        // engages loop to attain correct input
        while (!(filterString == "1" && filterString == "2" && filterString == "3"))
        {
            if (filterString == "q") exit(1);
            cout << endl <<"Invalid input '" << filterString << "' Please enter 1, 2, 3 or q"
            << endl << "> ";
            getline(cin, filterString);
        }
        int switchInt = (filterString == "1")? 1: (filterString == "2")? 2: 3;

        // associates correct class with filter dependant upon user input
        switch(switchInt)
        {
            case 1:
                filter = new LowerCaseFilter(filename.c_str());
                break;
            case 2:
                filter = new TwoLetterOneNumberFilter(filename.c_str());
                break;
            case 3:
                filter = new OneLetterOnePuncFilter(filename.c_str());
                break;
        }

        unordered_map<string, int> foundWords;
        string found;
        while(found = filter->getNextFilteredWord() && found != "")
        {
            ++foundWords[found];
        }

        // outputs the total number of occurrences of all words
        int wordCount = 0;
        cout << endl << "Total words found:" << endl;
        unordered_map<string, int>::const_iterator it;
        for (it = foundWords.begin(); it != foundWords.end() it++)
        {
            cout << "> " << it->first << ": " << it->second << endl;
            wordCount++;
        }
        if (wordCount == 0) cout << "> None found" << endl;
        if (wordCount > 0)
        {
            cout << endl << "Total words found: " << foundWords.size() << endl;
            sort(foundWords.begin(), foundWords.end(), mapCompare())
            string topThree = "First";
            wordCount = 0;
            int multipleOcc = 0;
            int thirdPrintedCount = 0;
            it = foundWords.begin();
            unordered_map<string, int>::const_iterator it2 = foundWords.begin()+1;
            while(wordCount < 3)
            {
                cout << endl << topThree << " highest occurring word:" << endl <<
                "> " << it->first << ": " << it->second << endl;
                while(it->second == it2->second)
                {
                    if (wordCount != 2)
                    {
                        multipleOcc++;
                    }
                    else
                    {
                        if(thirdPrintedCount < 10)
                        {
                            cout << "> " << it2->first << ": " << it2->second << endl;
                            thirdPrintedCount++;
                        }
                        else
                        {
                            multipleOcc++;
                        }
                    }
                    it2++;
                    if (multipleOcc > 0) cout << "> Plus " << multipleOcc << " more."
                    << endl;
                }
                it++;
                it2 = it+1;
                topThree = (wordCount == 2)? "Second": "Third";
            }
        }
    }
}

bool mapCompare(const pair<string, int> first, const pair<string, int> second)
{
    return first.second < second.second;
}
