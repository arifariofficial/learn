#include "bubblesort.h"  // Muista lisätä oikea otsikko
#include <gtest/gtest.h>

class BubblesortTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Luo alustava lista ennen jokaista testia
    }
};

TEST_F(BubblesortTest, EmptyList) {
    int array[] = {};
    int n = 0;
    int *sorted = bubblesort(array, n);
    EXPECT_EQ(0, n);
    // Varmista, että lista on edelleen tyhjä
}

TEST_F(BubblesortTest, SingleElementList) {
    int array[] = {5};
    int n = 1;
    int *sorted = bubblesort(array, n);
    EXPECT_EQ(5, array[0]);
    // Varmista, että lista on muuttumaton
}

TEST_F(BubblesortTest, AlreadySortedList) {
    int array[] = {1, 2, 3, 4, 5};
    int n = 5;
    int *sorted = bubblesort(array, n);
    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(5, array[4]);
    // Varmista, että lista on edelleen lajitettu
}

TEST_F(BubblesortTest, ReverseSortedList) {
    int array[] = {5, 4, 3, 2, 1};
    int n = 5;
    int *sorted = bubblesort(array, n);
    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(5, array[4]);
    // Varmista, että lista on lajitettu nousevassa järjestyksessä
}

TEST_F(BubblesortTest, UnsortedList) {
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n = 10;
    int *sorted = bubblesort(array, n);
    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(9, array[9]);
    // Varmista, että lista on lajitettu nousevassa järjestyksessä
}