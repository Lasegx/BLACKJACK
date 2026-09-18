#pragma once
#include "Hand.h"
#include "Deck.h"

class Dealer {
public:
	void addCard(const Card& card);
	bool shouldHit() const;
	void playTurn(Deck& deck);
	const Hand& getHand() const;

private:
	Hand hand;
};
