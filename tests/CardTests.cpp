#include <catch2/catch_test_macros.hpp>
#include <string>
#include "Card.h"

TEST_CASE("valueOf giver korrekt værdi for talkort") {

	REQUIRE(valueOf(Rank::Two) == 2);
		REQUIRE(valueOf(Rank::Three) == 3);
		REQUIRE(valueOf(Rank::Four) == 4);
		REQUIRE(valueOf(Rank::Five) == 5);
		REQUIRE(valueOf(Rank::Six) == 6);
		REQUIRE(valueOf(Rank::Seven) == 7);
		REQUIRE(valueOf(Rank::Eight) == 8);
		REQUIRE(valueOf(Rank::Nine) == 9);
}

TEST_CASE("valueOf giver 10 for billedkort") {
	REQUIRE(valueOf(Rank::Ten) == 10);
	REQUIRE(valueOf(Rank::Jack) == 10);
	REQUIRE(valueOf(Rank::Queen) == 10);
	REQUIRE(valueOf(Rank::King) == 10);
}

TEST_CASE("valueOf giver 11 for es") {
	REQUIRE(valueOf(Rank::Ace) == 11);
}
TEST_CASE("toString giver korrekt tekst for alle ranks")
{
		REQUIRE(std::string(toString(Rank::Two)) == "2");
		REQUIRE(std::string(toString(Rank::Three)) == "3");
		REQUIRE(std::string(toString(Rank::Four)) == "4");
		REQUIRE(std::string(toString(Rank::Five)) == "5");
		REQUIRE(std::string(toString(Rank::Six)) == "6");
		REQUIRE(std::string(toString(Rank::Seven)) == "7");
		REQUIRE(std::string(toString(Rank::Eight)) == "8");
		REQUIRE(std::string(toString(Rank::Nine)) == "9");
		REQUIRE(std::string(toString(Rank::Ten)) == "10");
		REQUIRE(std::string(toString(Rank::Jack)) == "J");
		REQUIRE(std::string(toString(Rank::Queen)) == "Q");
		REQUIRE(std::string(toString(Rank::King)) == "K");
		REQUIRE(std::string(toString(Rank::Ace)) == "A");
}


TEST_CASE("toString giver rigtig tekst for kulør")
{
	REQUIRE(std::string(toString(Suit::Hearts)) == "Hearts");
	REQUIRE(std::string(toString(Suit::Diamonds)) == "Diamonds");
	REQUIRE(std::string(toString(Suit::Clubs)) == "Clubs");
	REQUIRE(std::string(toString(Suit::Spades)) == "Spades");
}

TEST_CASE("toString giver rigtig tekst for billedkort")
{
	REQUIRE(std::string(toString(Rank::Jack)) == "J");
		REQUIRE(std::string(toString(Rank::Queen)) == "Q");
		REQUIRE(std::string(toString(Rank::King)) == "K");
		REQUIRE(std::string(toString(Rank::Ace)) == "A");
}

TEST_CASE("Ugyldig rank giver fallback-værdier") {
	Rank invaild = static_cast<Rank>(99);
	REQUIRE(valueOf(invaild) == 0);
	REQUIRE(std::string(toString(invaild)) == "?");

}

TEST_CASE("Ugyldig suit giver fallback-tekst") {
	Suit invaild = static_cast<Suit>(99);
	REQUIRE(std::string(toString(invaild)) == "?");
}