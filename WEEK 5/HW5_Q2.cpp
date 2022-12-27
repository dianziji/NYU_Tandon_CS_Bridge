// or2092_hw5_q2.cpp:
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    // Setting Variables
    const int MAX_GUESSES = 5;
    int rNum;
    int userInput, x = 1, y = 100;
    int guessesLeft;

    // RNGeneration [1, 100]
    srand(time(0));
    rNum = (rand() % 100) + 1;

    // Tree
    guessesLeft = MAX_GUESSES;
    cout << "I thought of a number between 1 and 100! Try to guess it.";
    do {
        cout << "\nRange: [" << x << ", " << y << "], Number of guesses left: " << guessesLeft << "\n"
             << "Your guess: ";
        cin >> userInput;
        if (userInput == rNum) {
            guessesLeft--;
            cout << "Congrats! You guessed my number in " << MAX_GUESSES - guessesLeft << " guesses.";
        }
        else {
            guessesLeft--;
            if (userInput > rNum && guessesLeft > 0) {
                cout << "Wrong! My number is smaller.\n";
                if (userInput < y)
                    y = userInput - 1;
            }
            else {
                if (guessesLeft > 0) {
                    cout << "Wrong! My number is bigger.\n";
                    if (userInput > x)
                        x = userInput + 1;
                }
            } 
        }
    } while (userInput != rNum && guessesLeft > 0);
    
    if(userInput != rNum && guessesLeft == 0)
        cout << "Out of guesses! My number is " << rNum << "\n" << endl;

    return 0;
}