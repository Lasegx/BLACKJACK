#include <catch2/catch_test_macros.hpp>
#include "Game.h"

TEST_CASE("nyt spil deler 2 kort til hver spiller og dealer") {
	Game game;
	REQUIRE(game.getPlayervalue() >= 0);
	REQUIRE(game.getDealervalue() >= 0);
	REQUIRE_FALSE(game.isOver());
}

TEST_CASE("playerHit opdaterer spillerens værdi") {
	Game game;
	int before = game.getPlayervalue();
	game.playerHit();
	int after = game.getPlayervalue();
	REQUIRE(after > before);
}

TEST_CASE("playerStand afslutter spillet") {
	Game game;
	game.playerStand();
	REQUIRE(game.isOver());
}

TEST_CASE("playerStand giver et gyldigt udfald") {
	Game game;
	GameResult result = game.playerStand();
	REQUIRE(result != GameResult::InProgress);
}