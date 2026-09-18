#include "Hand.h"

void Hand::addCard(const Card& card) {
	cards.push_back(card);
}

int Hand::getValue() const {
	int total = 0;
	int aces = 0;

	for (const auto& c : cards) {
		total += valueOf(c.rank);
		if (c.rank == Rank::Ace) {
			aces++;
	}
}

// Nedjustér es fra 11 til 1, ét ad gangen, indtil hånden ikke længere buster
	while (total > 21 && aces > 0) {
		total -= 10; // Juster Ace fra 11 til 1
		aces--;
	}
	return total;
}

bool Hand::isBust() const {
	return getValue() > 21;
}

bool Hand::isBlackjack() const {
	return cards.size() == 2 && getValue() == 21;
}

int Hand::cardCount() const {
	return static_cast<int>(cards.size());
}
