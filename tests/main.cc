#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "my_lib.h"

TEST_CASE("Test my library", "LibraryTest")
{
    linalg::aliases::float3 v = print_linalg_vector();
    REQUIRE( linalg::aliases::float3{1,2,3} == v );
}

TEST_CASE("Test boost version", "BoostTest")
{
    REQUIRE_FALSE( print_boost_version() == false );
}

