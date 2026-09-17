#include <catch2/catch_test_macros.hpp>
#include <string>
#include "Card.h"

TEST_CASE("valueOf giver korrekt værdi for talkort") {
	REQUIRE(valueOf(Rank::Two) == 2);
	REQUIRE(valueOf(Rank::Seven) == 7);
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
TEST_CASE("toString giver rigtig tekst for kulør")
{
	REQUIRE(std::string(toString(Suit::Hearts)) == "Hearts");
	REQUIRE(std::string(toString(Suit::Spades)) == "Spades");
}

TEST_CASE("toString giver rigtig tekst for billedkort")
{
	REQUIRE(std::string(toString(Rank::King)) == "K");
	REQUIRE(std::string(toString(Rank::Ace)) == "A");
}