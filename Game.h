#pragma once
#include "Deck.h"
#include "Hand.h"
#include "Dealer.h"

enum class GameResult {
	InProgress,
	PlayerBust,
	PlayerBlackjack,
	PlayerWins,
	DealerWins,
	Push
};

class Game {
public:
		Game(); // blader kort og deler to til vær

	GameResult playerHit(); // spiller trekker et kort
	GameResult playerStand(); // dealer spiller sin tur, og udfald afgøres

	int getPlayervalue() const; // returnerer spillerens håndværdi
	int getDealervalue() const; // returnerer dealerens håndværdi
	bool isOver() const; // returnerer true hvis spillet er slut

private:
		Deck deck;
	Hand playerHand;
	Dealer dealer;
	bool gameOver = false;

	GameResult determineOutcome(); // afgør udfaldet af spillet
};
