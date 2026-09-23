#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include "Game.h"

TEST_CASE("startRound afviser ugyldig indsats") {
	
	Game game(100);

	REQUIRE_THROWS_AS(game.startRound(0), std::invalid_argument);
	REQUIRE_THROWS_AS(game.startRound(-10), std::invalid_argument);
	REQUIRE_THROWS_AS(game.startRound(101), std::invalid_argument);
}


TEST_CASE("playerHit giver PlayerBust når spilleren kommer over 21") {
	
	std::vector<Card> cards = {
		{ Rank::Ten, Suit::Clubs }, // Player
		{ Rank::Five, Suit::Hearts }, // Dealer
		{ Rank::Nine, Suit::Diamonds }, // Player = 19
		{ Rank::Ten, Suit::Spades }, // Dealer = 15
		{ Rank::Five, Suit::Clubs } // Player hit = 24
	};


	Game game(100);
	game.startRound(10, Deck(cards));
	
	GameResult result = game.playerHit();

	REQUIRE(result == GameResult::PlayerBust);
	REQUIRE(game.isOver());
	REQUIRE(game.getPlayerValue() == 24);
	REQUIRE(game.getBalance() == 90);
	REQUIRE(game.getCurrentBet() == 0);
	

}

TEST_CASE("spilleren vinder når dealer bust") {
	
	std::vector<Card> cards = {
		{ Rank::Ten, Suit::Clubs }, // Player
		{ Rank::Ten, Suit::Hearts }, // Dealer
		{ Rank::Eight, Suit::Diamonds }, // Player = 18
		{ Rank::Six, Suit::Spades }, // Dealer = 16
		{ Rank::King, Suit::Clubs } // Dealer hit = 26
	};

	Game game(100);
	game.startRound(10, Deck(cards));

	GameResult result = game.playerStand();

	REQUIRE(result == GameResult::PlayerWins);
	REQUIRE(game.isOver());
	REQUIRE(game.getBalance() == 110);
	REQUIRE(game.getCurrentBet() == 0);
}

TEST_CASE("spilleren vinder med højere værdi end dealer") {
	std::vector<Card> cards = {
		{ Rank::Eight, Suit::Spades }, // Dealer kort 2
		{ Rank::Nine, Suit::Diamonds }, // Player kort 
		{ Rank::Ten, Suit::Hearts }, // Dealer kort 1
		{ Rank::Ten, Suit::Clubs } // Player kort 1
	};

	Game game(100);
	game.startRound(10, Deck(cards));

	REQUIRE(game.getPlayerValue() == 19);
	REQUIRE(game.getDealerValue() == 18);

	GameResult result = game.playerStand();

	REQUIRE(result == GameResult::PlayerWins);
	REQUIRE(game.isOver());
	REQUIRE(game.getBalance() == 110);
}

TEST_CASE("samme værdi giver push") {

	std::vector<Card> cards = {
		{ Rank::Ten, Suit::Clubs }, // Player
		{ Rank::Ten, Suit::Hearts }, // Dealer
		{ Rank::Eight, Suit::Diamonds }, // Player = 18
		{ Rank::Eight, Suit::Spades } // Dealer = 18
	};

	Game game(100);
	game.startRound(10, Deck(cards));

	GameResult result = game.playerStand();

	REQUIRE(result == GameResult::Push);
	REQUIRE(game.isOver());
	REQUIRE(game.getBalance() == 100);
	REQUIRE(game.getCurrentBet() == 0);

}

TEST_CASE("blackjack giver PlayerBlackjack og korrekt udbetaling") {

	std::vector<Card> cards = {
		{ Rank::Eight, Suit::Spades }, //Dealer kort 2
		{ Rank::King, Suit::Diamonds }, //Player kort 2
		{ Rank::Ten, Suit::Hearts }, //Player = 21 blackjack
		{ Rank::Ace, Suit::Clubs } // Dealer = 18
	};

	Game game(100);
	game.startRound(10, Deck(cards));

	REQUIRE(game.getPlayerValue() == 21);
	REQUIRE(game.getDealerValue() == 18);

	GameResult result = game.playerStand();

	REQUIRE(result == GameResult::PlayerBlackjack);
	REQUIRE(game.isOver());

	// 100- 10 + (10*2,5) = 115
	REQUIRE(game.getBalance() == 115);
	REQUIRE(game.getCurrentBet() == 0);


}
