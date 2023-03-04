
// #include "std_lib_facilities.h"
#include "Card.h"

string suitToString(Suit suit)
{
    map<Suit, string> suitToStringMap{
        {Suit::clubs, "Clubs"},
        {Suit::diamonds, "Diamonds"},
        {Suit::hearts, "Hearts"},
        {Suit::spades, "Spades"}};
    return suitToStringMap[suit];
}

string rankToString(Rank rank)
{
    map<Rank, string> rankToStringMap{
        {Rank::two, "Two"},
        {Rank::three, "Three"},
        {Rank::four, "Four"},
        {Rank::five, "Five"},
        {Rank::six, "Six"},
        {Rank::seven, "Seven"},
        {Rank::eight, "Eight"},
        {Rank::nine, "Nine"},
        {Rank::ten, "Ten"},
        {Rank::jack, "Jack"},
        {Rank::queen, "Queen"},
        {Rank::king, "King"},
        {Rank::ace, "Ace"}};
    return rankToStringMap[rank];
}
Card::Card(Suit s, Rank r) : s{s}, r{r} {}

Suit Card::getSuit()
{
    return s;
}

Rank Card::getRank()
{
    return r;
}

string Card::toString()
{
    string rank = rankToString(r);
    string suit = suitToString(s);
    string cardString = rank + " of " + suit;
    return cardString;
}

CardDeck::CardDeck()
{
    for (int s = 0; s < 4; s++)
    {
        for (int r = 2; r < 15; r++)
        {
            cards.push_back(Card((Suit)s, (Rank)r));
        }
    }
}

void CardDeck::swap(int pos1, int pos2)
{
    Card cardAtPos1 = cards[pos1];
    cards[pos1] = cards[pos2];
    cards[pos2] = cardAtPos1;
}

void CardDeck::print()
{
    for (int x = 0; x < cards.size(); x++)
    {
        cout << cards[x].toString() << endl;
    }
}

void CardDeck::shuffle()
{
    for (int x = 0; x < 1000; x++)
    {
        std::random_device rd;                         // obtain a random number from hardware
        std::mt19937 gen(rd());                        // seed the generator
        std::uniform_int_distribution<> distr(0, 52); // define the range

        int rand1 = distr(gen);
        int rand2 = distr(gen);
        swap(rand1, rand2);
    }
}

Card CardDeck::drawCard()
{
    Card lastCard = cards[cards.size() - 1];
    cards.pop_back();
    return lastCard;
}
