#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

/***
    Args:

    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    return rand() % 100 + 1;
}

/***
    Args:

    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    int guess;
    cout << "Enter your guess (1-100): ";
    cin >> guess;
    return guess;
}

/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {
    if (number > randomNumber) return "Your number is higher.";
    if (number < randomNumber) return "Your number is lower.";
    return "Congratulation! You win.";
}

/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer) {
    return answer == "Congratulation! You win.";
}

/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    return isContinued == 'y' || isContinued == 'Y';
}

/***
    Args:

    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return choice;
}

void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;

    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
