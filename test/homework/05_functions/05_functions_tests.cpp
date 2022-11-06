#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test get gc content")
{
	REQUIRE(get_gc_content("AGCTATAG") == .375);
	REQUIRE(get_gc_content("CGCTATAG") == .5);
}

TEST_CASE("Test reverse string")
{
	REQUIRE(reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(reverse_string("CGCTATAG") == "GATATCGC");
}

TEST_CASE("Test get dna compliment")
{
	REQUIRE(get_dna_compliment("CCCGGAAAAT") == "ATTTTCCGGG");
	REQUIRE(get_dna_compliment("AAAACCCGGT") == "ACCGGGTTTT");
}
