#include <catch2/catch_test_macros.hpp>
#include "Game.h"

TEST_CASE("nyt spil deler 2 kort til hver spiller og dealer") {
	Game game(100);
	game.startRound(10); // husk: kort deles nu i startRound, ikke i konstruktøren!
	REQUIRE(game.getPlayerValue() >= 0);
	REQUIRE(game.getDealerValue() >= 0);
	REQUIRE_FALSE(game.isOver());
}

TEST_CASE("playerHit opdaterer spillerens værdi") {
	Game game(100);
	game.startRound(10);
	int before = game.getPlayerValue();
	game.playerHit();
	int after = game.getPlayerValue();
	REQUIRE(after > before);
}

TEST_CASE("playerStand afslutter spillet") {
	Game game(100);
	game.startRound(10);
	game.playerStand();
	REQUIRE(game.isOver());
}

TEST_CASE("playerStand giver et gyldigt udfald") {
	Game game(100);
	game.startRound(10);
	GameResult result = game.playerStand();
	REQUIRE(result != GameResult::InProgress);
}