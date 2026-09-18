#include "Game.h"

Game::Game() {
	deck.shuffle();
	playerHand.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());
	playerHand.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());
}

GameResult Game::playerHit() {
	if (gameOver) {
		return determineOutcome();
	}

	playerHand.addCard(deck.dealCard());

	if (playerHand.isBust()) {
		gameOver = true;
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
	return determineOutcome();
}

GameResult Game::determineOutcome() {
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

int Game::getPlayervalue() const {
	return playerHand.getValue();
}

int Game::getDealervalue() const {
	return dealer.getHand().getValue();
}

bool Game::isOver() const {
	return gameOver;
}