#pragma once
#include <vector>
#include "Card.h"

class Deck {
public:
	Deck(); // opretter et standard sæt af 52 kort
	explicit Deck(std::vector<Card> presetCards);

	void shuffle(); // blander kortene
	Card dealCard(); // tager et kort fra toppen af bunken
	int cardsRemaining() const;

private:
	std::vector<Card> cards;
};	
