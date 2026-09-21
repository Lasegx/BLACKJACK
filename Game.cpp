#include "Game.h"
#include <stdexcept>

Game::Game(int startingBalance) : balance(startingBalance) {}

void Game::startRound(int bet, Deck presetDeck) {
	if (bet <= 0 || bet > balance) {
		throw std::invalid_argument("Ugyldig indsats");
	}

	currentBet = bet;
	balance -= bet;
	gameOver = false;

	deck = std::move(presetDeck); // Bruger det forudbestemte sæt kort
	playerHand = Hand();
	dealer = Dealer();


	playerHand.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());
	playerHand.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());
}
void Game::startRound(int bet) {
	Deck freshDeck;
	freshDeck.shuffle();
	startRound(bet, std::move(freshDeck));
}



GameResult Game::playerHit() {
	if (gameOver) {
		return determineOutcome();
	}

	playerHand.addCard(deck.dealCard());

	if (playerHand.isBust()) {
		gameOver = true;
		GameResult result = GameResult::PlayerBust;
		applyPayout(result);
		return GameResult::PlayerBust;
	}

	return GameResult::InProgress;
}

GameResult Game::playerStand() {
	if (gameOver) {
		return determineOutcome();
	}

	dealer.playTurn(deck);
	gameOver = true;
	GameResult result = determineOutcome();
	applyPayout(result);
	return result;
}

GameResult Game::determineOutcome() const {
	if (playerHand.isBust()) {
		return GameResult::PlayerBust;
	}
	if (dealer.getHand().isBust()) {
		return GameResult::PlayerWins;
	}
	if (playerHand.isBlackjack() && !dealer.getHand().isBlackjack()) {
		return GameResult::PlayerBlackjack;
	}

	int playerValue = playerHand.getValue();
	int dealerValue = dealer.getHand().getValue();

	if (playerValue > dealerValue) return GameResult::PlayerWins;
	if (dealerValue > playerValue) return GameResult::DealerWins;
	return GameResult::Push;

}

void Game::applyPayout(GameResult result) {
	switch (result) {
		case GameResult::PlayerBust:
		// Spilleren taber indsatsen
			break;
		case GameResult::PlayerBlackjack:
		balance += static_cast<int>(currentBet * 2.5); // Blackjack betaler 3:2
			break;
		case GameResult::PlayerWins:
		balance += currentBet * 2; // Spilleren vinder dobbelt indsatsen
			break;
		case GameResult::DealerWins:
		// Spilleren taber indsatsen
			break;
		case GameResult::Push:
		balance += currentBet; // Spilleren får indsatsen tilbage
			break;
		default:
			break;
	}
		currentBet = 0; // Nulstil den aktuelle indsats efter udbetalingen
}


int Game::getPlayerValue() const {
	return playerHand.getValue();
}

int Game::getDealerValue() const {
	return dealer.getHand().getValue();
}

bool Game::isOver() const {
	return gameOver;
}

int Game::getBalance() const {
	return balance;
}

int Game::getCurrentBet() const {
	return currentBet;
}