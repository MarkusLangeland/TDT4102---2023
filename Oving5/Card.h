#pragma once

#include "std_lib_facilities.h"

enum class Suit
{
    clubs,
    diamonds,
    hearts,
    spades
};

enum class Rank
{
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};

string rankToString(Rank rank);
string suitToString(Suit suit);

class Card
{
private:
    Suit s;
    Rank r;

public:
    Card(Suit s, Rank r);
    Suit getSuit();
    Rank getRank();
    string toString();
};

class CardDeck
{
private:
    vector<Card> cards;

public:
    CardDeck();
    void swap(int pos1, int pos2);
    void print();
    void shuffle();
    Card drawCard();
};