#include "Card.h"

int value0f(Rank rank) {
	switch (rank) {
	case Rank::Two: return 2;
	case Rank::Three: return 3;
	case Rank::Four: return 4;
	case Rank::Five: return 5;
	case Rank::Six: return 6;
	case Rank::Seven: return 7;
	case Rank::Eight: return 8;
	case Rank::Nine: return 9;
	case Rank::Ten:
	case Rank::Jack:
	case Rank::Queen:
	case Rank::King: 
		return 10;
	case Rank::Ace: return 11; // Ace can also be 1, but we'll handle that in the game logic
	
	}
	return 0; // Should never happen
}

const char* toString(Rank rank) {
	switch (rank) {
	case Rank::Two: return "2";
	case Rank::Three: return "3";
	case Rank::Four: return "4";
	case Rank::Five: return "5";
	case Rank::Six: return "6";
	case Rank::Seven: return "7";
	case Rank::Eight: return "8";
	case Rank::Nine: return "9";
	case Rank::Ten: return "10";
	case Rank::Jack: return "J";
	case Rank::Queen: return "Q";
	case Rank::King: return "K";
	case Rank::Ace: return "A";
	}
	return "?";
}

const char* toString(Suit suit) {
	switch (suit) {
	case Suit::Hearts: return "Hearts";
	case Suit::Diamonds: return "Diamonds";
	case Suit::Clubs: return "Clubs";
	case Suit::Spades: return "Spades";
	}
	return "?";
}	
