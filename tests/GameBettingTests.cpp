#include <catch2/catch_test_macros.hpp>
#include "Game.h"

TEST_CASE("startRound trækker korrekt fra balancen") {
	Game game(100);
	game.startRound(20);
	REQUIRE(game.getBalance() == 80);
}	

TEST_CASE("startRound kaster exception ved for høj indsats") {
	Game game(50);
	REQUIRE_THROWS_AS(game.startRound(100), std::invalid_argument);
	
}

TEST_CASE("startRound kaster exception ved indsat på 0 eller mindre") {
	Game game(50);
	REQUIRE_THROWS_AS(game.startRound(0), std::invalid_argument);
	REQUIRE_THROWS_AS(game.startRound(-10), std::invalid_argument);
}

TEST_CASE("Push giver indsatsen tilbage til balancen") {
	std::vector<Card> cards = {
		{Rank::King, Suit::Diamonds },
		{Rank::King, Suit::Spades },
		{Rank::King, Suit::Clubs },
		{Rank::King, Suit::Hearts }

	};

	Game game(100);
	game.startRound(10, Deck(cards));

	REQUIRE(game.getPlayerValue() == 20);
	REQUIRE(game.getDealerValue() == 20);

	game.playerStand();

	REQUIRE(game.getBalance() == 100);
}

TEST_CASE("playerHit resulterer i PlayBust ved værdi over 21") {
	std::vector<Card> cards = {
		{ Rank::King, Suit::Diamonds },
		{ Rank::Three, Suit::Clubs },
		{ Rank::Five, Suit::Hearts },
		{ Rank::Two, Suit::Spades },
		{ Rank::Ten, Suit::Hearts }
	};
	
	Game game(100);
	game.startRound(10, Deck(cards));

	REQUIRE(game.getPlayerValue() == 15);

	GameResult result = game.playerHit();

	REQUIRE(result == GameResult::PlayerBust);
	REQUIRE(game.isOver());
}