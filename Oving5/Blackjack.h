#pragma once
#include "Card.h"

class Blackjack
{
private:
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum;
    int dealerHandSum;
public:
    int getCardValue(Card card);
    int gethandScore(vector<Card> cards);
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void DrawDealerCard();
    void playGame();
};


bool isAce(Card card);
