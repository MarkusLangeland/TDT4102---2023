#include "utilities.h"
#include "std_lib_facilities.h"

int checkCharactersAndPosition(string guess, string code)
{
    int rightPlace = 0;
    for (int x = 0; x < size(code); x++)
    {
        if (guess[x] == code[x])
        {
            rightPlace += 1;
        }
    }
    return rightPlace;
}

int checkCharacters(string guess, string code)
{
    int rightChar = 0;
    for (int x = 0; x < size(guess); x++)
    {
        if (guess.find(code[x]) < size(guess)) {
            rightChar += 1;
        }
    }
    return rightChar;
}

void playMastermind()
{
    // Bruker constexpr for at verdiene skal være definert ved compiletime.
    constexpr int size = 4;
    constexpr int letters = 6;
    constexpr int maxGuessAmount = 10;

    string code = randomizeString(size, 0, letters - 1);
    string guess;
    cout << code << endl;
    cout << "You have " << maxGuessAmount << " Guesses." << endl;
    int amountOfGuesses = 0;
    for (int x = 0; x < maxGuessAmount; x++)
    {
        cout << "You have " << maxGuessAmount - amountOfGuesses << " out of " << maxGuessAmount << " guesses left." << endl;
        guess = readInputToString(0, letters - 1, size);
        if (guess == code)
        {
            cout << "You guessed correctly!" << endl;
            break;
        }
        cout << "Your guess had " << checkCharactersAndPosition(guess, code) << " in the right position" << endl;
        cout << "You guessed " << checkCharacters(guess, code) << " right Characters." << endl;
        amountOfGuesses++;
    }
}
