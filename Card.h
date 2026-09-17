#pragma once

enum class Suit {
	Hearts,
	Diamonds,
	Clubs,
	Spades	
};

enum class Rank {
	Two, Three, Four, Five, Six,
	Seven, Eight, Nine, Ten,
	Jack, Queen, King, Ace
};

struct Card {
	Rank rank;
	Suit suit;
};

int valueOf(Rank rank);
const char* toString(Rank rank);
const char* toString(Suit suit);