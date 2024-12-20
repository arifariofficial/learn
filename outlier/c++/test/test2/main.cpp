#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "bubblesort.hpp"

TEST_CASE("Testataan bubblesort-funktiota", "[bubblesort]") {
    // Tapausta, jossa lista on jo järjestyksessä
    SECTION("Jo lajiteltu lista") {
        int lista[] = {1, 2, 3, 4, 5};
        int koko = sizeof(lista) / sizeof(lista[0]);
        int* tulokset = bubblesort(lista, koko);
        REQUIRE(tulokset == lista);
        for (int i = 0; i < koko; i++) {
            REQUIRE(lista[i] == i + 1);
        }
    }

    // Tapausta, jossa lista on kääntynyt järjestyksessä
    SECTION("Kääntynyt lista") {
        int lista[] = {5, 4, 3, 2, 1};
        int koko = sizeof(lista) / sizeof(lista[0]);
        int* tulokset = bubblesort(lista, koko);
        REQUIRE(tulokset == lista);
        for (int i = 0; i < koko; i++) {
            REQUIRE(lista[i] == i + 1);
        }
    }

    // Tapausta, jossa lista on tyhjä
    SECTION("Tyhjä lista") {
        int lista[0] = {};
        int koko = sizeof(lista) / sizeof(lista[0]);
        int* tulokset = bubblesort(lista, koko);
        REQUIRE(tulokset == lista);
        REQUIRE(koko == 0);
    }

    // Tapausta, jossa listassa on yksi elementti
    SECTION("Yksi elementti") {
        int lista[] = {42};
        int koko = sizeof(lista) / sizeof(lista[0]);
        int* tulokset = bubblesort(lista, koko);
        REQUIRE(tulokset == lista);
        REQUIRE(lista[0] == 42);
    }

    // Satunnaisen listan testaus
    SECTION("Satunnainen lista") {
        int lista[] = {9, 14, 3, 2, 43, 11, 58, 22};
        int koko = sizeof(lista) / sizeof(lista[0]);
        int* tulokset = bubblesort(lista, koko);
        REQUIRE(tulokset == lista);
        for (int i = 1; i < koko; i++) {
            REQUIRE(lista[i] >= lista[i - 1]);
        }
    }
}