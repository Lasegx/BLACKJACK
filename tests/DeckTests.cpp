#include <catch2/catch_test_macros.hpp>
#include "Deck.h"

TEST_CASE ("Ny kortbunke har 52 kort")
{
	Deck deck;
	REQUIRE(deck.cardsRemaining() == 52);
}

TEST_CASE("dealCard reducerer antal af kort med 1")
{
	Deck deck;
	deck.dealCard();
	REQUIRE(deck.cardsRemaining() == 51);
}

TEST_CASE("dealCard kaster exception når bunken er tom")
{
	Deck deck;
	for (int i = 0; i < 52; ++i) {
		deck.dealCard();
	}
	REQUIRE_THROWS_AS(deck.dealCard(), std::runtime_error);
}