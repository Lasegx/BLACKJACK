#include "Dealer.h"

void Dealer::addCard(const Card& card) {
	hand.addCard(card);
}

bool Dealer::shouldHit() const {
	return hand.getValue() < 17;
}

void Dealer::playTurn(Deck& deck) {
	while (shouldHit()) {
		hand.addCard(deck.dealCard());
	}
}

const Hand& Dealer::getHand() const {
	return hand;
}