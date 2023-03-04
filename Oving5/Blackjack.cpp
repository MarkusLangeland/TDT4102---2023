#include "Blackjack.h"

bool isAce(Card card)
{
    return rankToString(card.getRank()) == "Ace" ? true : false;
}

int Blackjack::getCardValue(Card card)
{
    map<Rank, int> rankToIntMap{
        {Rank::two, 2},
        {Rank::three, 3},
        {Rank::four, 4},
        {Rank::five, 5},
        {Rank::six, 6},
        {Rank::seven, 7},
        {Rank::eight, 8},
        {Rank::nine, 9},
        {Rank::ten, 10},
        {Rank::jack, 10},
        {Rank::queen, 10},
        {Rank::king, 10},
        {Rank::ace, 11}};
    return rankToIntMap[card.getRank()];
}

int Blackjack::gethandScore(vector<Card> cards)
{
    int sum = 0;
    for (int x = 0; x < cards.size(); x++)
    {
        if (sum + getCardValue(cards[x]) > 21 && isAce(cards[x]))
        {
            sum + 1;
            return sum;
        }
        sum += getCardValue(cards[x]);
    }
    return sum;
}

bool Blackjack::askPlayerDrawCard()
{
    string input;
    cout << "Do you want to draw another card? (y/n)" << endl;
    cin >> input;
    return input == "y" ? true : false;
}

void Blackjack::drawPlayerCard()
{
    Card newCard = deck.drawCard();
    cout << "You just drew: " << newCard.toString() << endl;
    playerHand.push_back(newCard);
    playerHandSum = gethandScore(playerHand);
}
void Blackjack::DrawDealerCard()
{
    Card newCard = deck.drawCard();
    cout << "Dealer just drew: " << newCard.toString() << endl;
    dealerHand.push_back(newCard);
    dealerHandSum = gethandScore(dealerHand);
}

void Blackjack::playGame()
{
    deck.shuffle();
    bool wantToPlay = true;
    while (wantToPlay)
    {
        drawPlayerCard();
        cout << "Current score: " << gethandScore(playerHand) << endl;
        if (gethandScore(playerHand) > 21)
        {
            cout << "You are over 21! You Lost!" << endl;
            wantToPlay = false;
            return;
        }
        wantToPlay = askPlayerDrawCard();
    }
    cout << "The dealers turn: " << endl;
    while (gethandScore(dealerHand) < 17)
    {
        DrawDealerCard();
        cout << "Current dealer score: " << gethandScore(dealerHand) << endl;
    }
    if ((gethandScore(dealerHand) > 21 && gethandScore(playerHand) <= 21) || (gethandScore(playerHand) > gethandScore(dealerHand)))
    {
        cout << "You won!" << endl;
    }
    else
    {
        cout << "Dealer won." << endl;
        return;
    }
    if (gethandScore(playerHand) == gethandScore(dealerHand))
    {
        cout << "It was a draw!" << endl;
        return;
    }
}