#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

/*
* There are no direct inputs, just the runners.txt file. Basically the program reads the
* file, it then prints the names from the file, then the Calculate() function will print the data.
* The output is the names, the amount they ran each day, the total they ran, and the average per day.
*/

/*
* I basically just took my other program and changed the arrays RunnersNames[] and MilesRun[] into a struct.
* The struct has the string runners inside it, and the array milesRun[]. 
* I also changed all of the places that used 5 and 7 to just use the variables numRunners and numDays
*/

using namespace std;

const int numRunners = 5;
const int numDays = 7;


struct Runner {
    string name;
    int milesRun[numDays];
};

// Preconditions: The file has to exist
// Post conditions: The struct Runner will have it's string runners and it's array milesRun[] defined.
void Data(Runner runners[numRunners]) {
    ifstream file("runners.txt");

    if (file.is_open()) {
        for (int index = 0; index < numRunners; ++index) {
            string line;
            if (getline(file, line)) {
                size_t spacePos = line.find(' ');
                runners[index].name = line.substr(0, spacePos);

                stringstream stringstream(line.substr(spacePos + 1));
                for (int j = 0; j < numDays; ++j) {
                    stringstream >> runners[index].milesRun[j];
                }
            }
        }
    }
}


// Preconditions: runners and milesRun must be defined
// Postconditions: The data will be output
void Calculate(Runner runners[numRunners]) {

    const int Width = 15;

    for (int day = 0; day < numDays; day++) {
        cout << "Day " << day + 1 << ":" << setw(Width);
        for (int runner = 0; runner < numRunners; runner++) {
            cout << runners[runner].milesRun[day] << setw(Width);
        }
        cout << endl;
    }

    cout << "Total:" << setw(Width);
    for (int i = 0; i < numRunners; ++i) {
        int totalMiles = 0;

        for (int j = 0; j < numDays; ++j) {
            totalMiles += runners[i].milesRun[j];
        }
        cout << totalMiles << setw(Width);
    }
    cout << endl;
    cout << "Average:" << setw(Width);
    for (int i = 0; i < numRunners; ++i) {
        int totalMiles = 0;

        for (int j = 0; j < numDays; ++j) {
            totalMiles += runners[i].milesRun[j];
        }
        cout << totalMiles / numDays << setw(Width);
    }
}


// Preconditions: runners and milesRun must be definied
// Postconditions: The names will be outputted
int main() {
    Runner runners[numRunners];
    Data(runners);

    cout << "OUTPUT" << endl;

    const int Width = 15;

    cout << setw(Width) << "Names:" << setw(Width);
    for (int index = 0; index < numRunners; index++) {
        cout << runners[index].name << setw(Width);
    }

    cout << endl;

    Calculate(runners);

    return 0;
}