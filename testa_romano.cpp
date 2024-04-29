#define CATCH_CONFIG_MAIN
// ^^ This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./romano.hpp"

// Copyright 2024.04.29 Paulo Fernando Vilarim

TEST_CASE(
    "Numeros romanos - validos - simbolos existentes",
    "[romano]"
    ) {
    REQUIRE(converteRomanoArabico("I") == 1);

    REQUIRE(converteRomanoArabico("V") == 5);

    REQUIRE(converteRomanoArabico("X") == 10);

    REQUIRE(converteRomanoArabico("L") == 50);

    REQUIRE(converteRomanoArabico("C") == 100);

    REQUIRE(converteRomanoArabico("D") == 500);

    REQUIRE(converteRomanoArabico("M") == 1000);
}


TEST_CASE(
    "Numeros romanos - validos",
    "[romano]"
    ) {
    REQUIRE(converteRomanoArabico("IX") == 9);

    REQUIRE(converteRomanoArabico("CMLXXXIII") == 983);
}


TEST_CASE(
    "Numeros romanos - invalidos - simbolos inexistentes",
    "[romano]"
    ) {
    REQUIRE(converteRomanoArabico("G") == -1);

    REQUIRE(converteRomanoArabico("i") == -1);

    REQUIRE(converteRomanoArabico("_") == -1);
}


TEST_CASE(
    "Numeros romanos - invalidos - 4 ou mais símbolos consecutivos repetidos",
    "[romano]"
    ) {
    REQUIRE(converteRomanoArabico("CCCC") == -1);

    REQUIRE(converteRomanoArabico("IIIII") == -1);

    REQUIRE(converteRomanoArabico("CXXXX") == -1);
}


TEST_CASE(
    "Numeros romanos - invalidos - simbolos redundantes",
    "[romano]"
    ) {
    REQUIRE(converteRomanoArabico("VX") == -1);

    REQUIRE(converteRomanoArabico("CLL") == -1);

    REQUIRE(converteRomanoArabico("XDM") == -1);
}


TEST_CASE("Numeros romanos - entrada com valor entre 1 e 3000") {
    REQUIRE(converteRomanoArabico("MMM") == 3000);

    REQUIRE(converteRomanoArabico("MMMI") == -1);
}
