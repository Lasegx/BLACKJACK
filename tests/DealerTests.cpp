#include <catch2/catch_test_macros.hpp>
#include "Dealer.h"

TEST_CASE("Dealer skal hitte ved værdi 17") {
	Dealer dealer;
	dealer.addCard(Card{Rank::Seven, Suit::Hearts});
	dealer.addCard(Card{Rank::Eight, Suit::Spades});
	// værdi = 15, bør hitte
	REQUIRE(dealer.shouldHit());
}

TEST_CASE("Dealer skal stå ved præcis 17") {
	Dealer dealer;
	dealer.addCard(Card{Rank::King, Suit::Hearts});
	dealer.addCard(Card{Rank::Seven, Suit::Spades});
	// værdi = 17, bør stå
	REQUIRE_FALSE(dealer.shouldHit());
}

TEST_CASE("Dealer skal stå ved værdi over 17") {
	Dealer dealer;
	dealer.addCard(Card{Rank::King, Suit::Hearts});
	dealer.addCard(Card{Rank::King, Suit::Spades});
	// værdi = 20, bør stå
	REQUIRE_FALSE(dealer.shouldHit());
}

TEST_CASE("playTurn trækker kort indtil 17") {
	Deck deck;
	deck.shuffle();
	Dealer dealer;
	dealer.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());

	dealer.playTurn(deck);

	REQUIRE(dealer.getHand().getValue() >= 17);

}
