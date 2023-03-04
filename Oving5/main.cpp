
#include "std_lib_facilities.h"
#include "Card.h"
#include "Blackjack.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
    // Show a nice message in the Terminal window
    cout << "Write a number between 1 and 3: " << endl;
    int input;
    cin >> input;
    switch (input)
    {
    case 1:
    {
        Rank r = Rank::king;
        Suit s = Suit::hearts;
        string rank = rankToString(r);
        string suit = suitToString(s);
        cout << "Rank: " << rank << " , Suit: " << suit << endl;
        break;
    }
    case 2:
    {
        Card c{Suit::spades, Rank::ace};
        cout << c.toString() << '\n';
        break;
    }
    case 3:
    {
        Blackjack b;
        b.playGame();
    }
    }
    return 0;
}

//------------------------------------------------------------------------------
