#include <iostream>
#include <vector> //this stores my list of quotes
#include <string>
#include <fstream> // this is for reading in my external text file
#include <ctime> //I use ctime in this occasion to use the computer's clock to randomize the quotes eachtime so that way it's not outputting the same line.
#include "vquotes.h"

using namespace std;

int main() {
    // Setup random generator
    //I am seeding the random number generator using current time so that way the quotes are always different everytime. 
    srand(time(0));

   //vector<string>my list is creating a vector to hold all the strings of data from the file
    //string line; creates a temporary string to hold one line at a time. 
    vector<string> myList;
    string line;

    // Open the text file
    //Basically i'm telling the program to find my .txt file that is labeled vquotes in my folder.
    //if it finds it, the if statemewnt will let us start reading the lines from the txt file
    //if it can't find it then the program will just close and Poof! No more project for you, hard work will be for nada.
    ifstream theFile("vquotes.txt");

    if (theFile.is_open()) {
        while (getline(theFile, line)) {
            if (line.length() > 0) {
                myList.push_back(line);
            }
        }
        theFile.close();
    }
    else {
        return 0;
    }

    int choice = 0;
    //this while loop presents all the options to choose from when the program runs to output different things, option 4 allows for an exit command to occur
    while (choice != 4) {
        cout << "\n1. Random Quote" << endl;
        cout << "2. Show All" << endl;
        cout << "3. Clear" << endl;
        cout << "4. Exit" << endl;
        cout << "Selection: ";
        //this gets the user's input
        cin >> choice;

        if (choice == 1) {
            // This gets a decimal between 0 and 1, then multiplies by list size
            double fraction = (double)rand() / RAND_MAX;
            int r = (int)(fraction * (myList.size() - 1));

            cout << "\n" << myList[r] << endl;
        }
        else if (choice == 2) {
            for (int i = 0; i < (int)myList.size(); i++) {
     // We print i + 1 so the list starts at 1 instead of 0
    // Then we grab the quote at position 'i' and show it
                cout << i + 1 << ". " << myList[i] << endl;
            }
        }
        else if (choice == 3) {
            clearScreen();
        }
    }

    cout << "Done. Press any key." << endl;
    system("pause");
    return 0;
}