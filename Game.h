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
	explicit Game(int startingBalance); // blader kort og deler to til vær
	
	void startRound(int bet); // starter en ny runde med en given indsats
	void startRound(int bet, Deck presetDeck); // starter en ny runde med en given indsats og et forudbestemt sæt kort (til testformål)
	GameResult playerHit(); // spiller trekker et kort
	GameResult playerStand(); // dealer spiller sin tur, og udfald afgøres

	int getPlayerValue() const; // returnerer spillerens håndværdi
	int getDealerValue() const; // returnerer dealerens håndværdi
	bool isOver() const; // returnerer true hvis spillet er slut
	int getBalance() const; // returnerer spillerens balance
	int getCurrentBet() const; // returnerer spillerens nuværende indsats

private:
	Deck deck;
	Hand playerHand;
	Dealer dealer;
	bool gameOver = false;

	int balance;
	int currentBet = 0;

	GameResult determineOutcome() const; // afgør udfaldet af spillet
	void applyPayout(GameResult result); // anvender udbetalingen baseret på udfaldet
};
