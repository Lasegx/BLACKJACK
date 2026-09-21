#include "Deck.h"
#include <algorithm>
#include <random>
#include <stdexcept>

Deck::Deck() {
	for (int s=0; s < 4; ++s) {
		for (int r=0; r < 13; ++r) {
			cards.push_back(Card{ static_cast<Rank>(r), static_cast<Suit>(s) });
		}
	}
}

Deck::Deck(std::vector<Card> presetCards) : cards(std::move(presetCards)) {}

void Deck::shuffle() {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::dealCard() {
	if (cards.empty()) {
		throw std::runtime_error("kort bunken er tom");
	}
	Card top = cards.back();
	cards.pop_back();
	return top;
}

int Deck::cardsRemaining() const {
	return static_cast<int>(cards.size());
}