#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Think of a number between 1 and 100" << endl;
    int highest = 100, lowest = 0, attempts = 0;
    attempts++;
    int step = 0;
    while (step < 7)
    {
        step++;
        int guess = lowest + ((highest - lowest) * 0.5);
        cout << "I guess {" << guess << "}. Am I right?" << ends;
        cout << "\"q\" to quit, \"y\" if correct, \"h\" if too high, \"l\" if too low." << endl;
        string input;
        cin >> input;
        cout << endl;
        if (input == "y")
        {
            cout << endl
                 << "I guessed it in {" << guess << "} attempts";
            exit(step);
        }

        else if (input == "q")
        {
            cout << "You quit. Bye.";
            exit(step);
        }
        else if (input == "h")
        {
            highest -= guess;
        }
        else if (input == "l")
        {

            lowest -= guess;
        }
        else
        {
            cout << "I didn’t understand that response." << endl;
        }
    }

    exit(step);
}
