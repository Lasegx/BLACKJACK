// BLACKJACK.cpp : Defines the entry point for the application.
//
#include "Game.h"
#include <iostream>
#include "BLACKJACK.h"

int main() {
	Game game(100);
	game.startRound(10);

	std::cout << "== Ny runde ==\n";
	std::cout << "Spillerens hånd: " << game.getPlayerValue() << "\n";
	std::cout << "Dealerens hånd: " << game.getDealerValue() << "\n";
	std::cout << "Saldo: " << game.getBalance() << "\n\n";

	std::cout << "Spilleren tager et kort (hit)...\n";
	game.playerHit();
	std::cout << "Spillerens hånd nu: " << game.getPlayerValue() << "\n\n";

	std::cout << "Spilleren stander...\n";
	GameResult result = game.playerStand();

	std::cout << "Dealerens endelige hånd: " << game.getDealerValue() << "\n";
	std::cout << "Saldo efter runden: " << game.getBalance() << "\n";

	switch (result)
	{
	case GameResult::PlayerWins:		std::cout << "Resultat: Spilleren vinder!\n"; break;
	case GameResult::DealerWins:		std::cout << "Resultat: Dealeren vinder.\n"; break;
	case GameResult::Push:				std::cout << "Resultat: Uafgjort (push).\n"; break;
	case GameResult::PlayerBust:		std::cout << "Resultat: Spilleren buster.\n"; break;
	case GameResult::PlayerBlackjack:	std::cout << "Resultat: Blackjack!\n"; break;
	default:
		break;
	}

	return 0;
}