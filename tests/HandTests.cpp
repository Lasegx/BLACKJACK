#include <catch2/catch_test_macros.hpp>
#include "Hand.h"

TEST_CASE("Hand uden es tæller normalt") {
	Hand hand;
	hand.addCard({ Rank::Seven, Suit::Hearts });
	hand.addCard({ Rank::King, Suit::Spades });
	REQUIRE(hand.getValue() == 17);
}

TEST_CASE("Es alene tæller som 11") {
	Hand hand;
	hand.addCard({ Rank::Ace, Suit::Spades });
	REQUIRE(hand.getValue() == 11);
}

TEST_CASE("Es nedjusteres til 1 for at undgå bust") {
	Hand hand;
	hand.addCard({ Rank::Ace, Suit::Spades });
	hand.addCard({ Rank::King, Suit::Hearts });
	hand.addCard({ Rank::Five, Suit::Clubs });
	REQUIRE(hand.getValue() == 16); // 11+10+5=26, es nedjusteres til 1, så 1+10+5=16
}
TEST_CASE("2 esser håndteres korrekt"){
	Hand hand;
	hand.addCard({ Rank::Ace, Suit::Spades });
	hand.addCard({ Rank::Ace, Suit::Hearts });
	REQUIRE(hand.getValue() == 12); // 11+1=12
}

TEST_CASE("isBust returnerer true ved værdi over 21"){
	Hand hand;
	hand.addCard({ Rank::King, Suit::Hearts });
	hand.addCard({ Rank::Queen, Suit::Spades });
	hand.addCard({ Rank::Five, Suit::Clubs });
	REQUIRE(hand.isBust());
}

TEST_CASE("isBlackjack er true ved es + 10-kort på 2 kort") {
	Hand hand;
	hand.addCard({ Rank::Ace, Suit::Spades });
	hand.addCard({ Rank::King, Suit::Hearts });
	REQUIRE(hand.isBlackjack());
}

TEST_CASE("isBlackjack er false ved 21 på 3 kort") {
	Hand hand;
	hand.addCard({ Rank::Seven, Suit::Hearts });
	hand.addCard({ Rank::Seven, Suit::Spades });
	hand.addCard({ Rank::Seven, Suit::Clubs });
	REQUIRE(hand.getValue() == 21);
	REQUIRE_FALSE(hand.isBlackjack());
}