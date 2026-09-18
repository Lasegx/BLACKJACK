#pragma once
#include <vector>
#include "Card.h"

class Hand{ 
public:
	void addCard(const Card& card);
	int getValue() const;
	bool isBust() const;
	bool isBlackjack() const;
	int cardCount() const;

private:
	std::vector<Card> cards;
};
