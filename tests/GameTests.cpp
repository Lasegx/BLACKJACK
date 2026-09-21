#include <catch2/catch_test_macros.hpp>
#include "Game.h"

TEST_CASE("nyt spil deler 2 kort til hver spiller og dealer") {
	std::vector<Card> cards = {
		{ Rank::Five, Suit::Clubs },
		{ Rank::King, Suit::Hearts },
		{ Rank::Six, Suit::Diamonds },
		{ Rank::Seven, Suit::Spades }
	};


	Game game(100);
	game.startRound(10, Deck(cards));

	REQUIRE(game.getPlayerValue() == 17);
	REQUIRE(game.getDealerValue() == 11);
	REQUIRE_FALSE(game.isOver());
}

TEST_CASE("playerHit opdaterer spillerens værdi") {
	std::vector<Card> cards = {
		{ Rank::Six, Suit::Clubs },
		{ Rank::Five, Suit::Hearts },
		{ Rank::Four, Suit::Diamonds },
		{ Rank::Three, Suit::Spades },
		{ Rank::Two, Suit::Hearts }
	};


	Game game(100);
	game.startRound(10, Deck(cards));

	int before = game.getPlayerValue();
	game.playerHit();
	int after = game.getPlayerValue();

	REQUIRE(after > before);
	REQUIRE(after == 12);
}

TEST_CASE("playerStand afslutter spillet") {
	std::vector<Card> cards = {
		{ Rank::Six, Suit::Clubs },
		{ Rank::Ten, Suit::Diamonds },
		{ Rank::Three, Suit::Hearts },
		{ Rank::Seven, Suit::Spades },
		{ Rank::Two, Suit::Diamonds },
		{ Rank::King, Suit::Hearts }
	};

	Game game(100);
	game.startRound(10, Deck(cards));

	REQUIRE(game.getPlayerValue() == 17);

	game.playerStand();

	REQUIRE(game.isOver());
	REQUIRE(game.getDealerValue() == 21);
}

TEST_CASE("playerStand giver et gyldigt udfald") {
	std::vector<Card> cards = {
		{ Rank::Six, Suit::Clubs },
		{ Rank::Ten, Suit::Diamonds },
		{ Rank::Three, Suit::Hearts },
		{ Rank::Seven, Suit::Spades },
		{ Rank::Two, Suit::Diamonds },
		{ Rank::King, Suit::Hearts }
	};

	Game game(100);
	game.startRound(10, Deck(cards));

	GameResult result = game.playerStand();

	REQUIRE(result == GameResult::DealerWins);
}

TEST_CASE("Kald efter spillet er slut returnerer bare samme udfald") {
	Game game(100);
	game.startRound(10);
	game.playerStand();

	GameResult result = game.playerHit(); // kaldes IGEN, selvom spillet er slut
	REQUIRE(game.isOver());
	REQUIRE(result != GameResult::InProgress);

}