#include <iostream>
#include <cassert>

using namespace std;

// Bubblesort-funktio
int* bubblesort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
    return a;
}

// Funktio, joka testaa bubblesort-funktiota
void test_bubblesort() {
    // Testitilanteet
    // 1. Normaali tapaus: Satunnaiset arvot
    int arr1[] = {4, 2, 5, 1, 3};
    int expected1[] = {1, 2, 3, 4, 5};
    assert(memcmp(bubblesort(arr1, 5), expected1, 5 * sizeof(int)) == 0);

    // 2. Reunatapaus: Tyhjät taulukot
    int arr2[] = {};
    int* sorted2 = bubblesort(arr2, 0);
    assert(sorted2 == arr2); // Tyhjään taulukkoon lajittelu ei muuta mitään.

    // 3. Reunatapaus: Taulukko, jossa on yksi elementti
    int arr3[] = {42};
    int expected3[] = {42};
    assert(memcmp(bubblesort(arr3, 1), expected3, 1 * sizeof(int)) == 0);

    // 4. Tapaus: Kaikki arvot ovat samoja
    int arr4[] = {7, 7, 7, 7};
    int expected4[] = {7, 7, 7, 7};
    assert(memcmp(bubblesort(arr4, 4), expected4, 4 * sizeof(int)) == 0);

    // 5. Käänteisjärjestyksessä oleva taulukko
    int arr5[] = {5, 4, 3, 2, 1};
    int expected5[] = {1, 2, 3, 4, 5};
    assert(memcmp(bubblesort(arr5, 5), expected5, 5 * sizeof(int)) == 0);

    cout << "Kaikki testit läpäisty!" << endl;
}

int main() {
    test_bubblesort(); // Kutsutaan testifi
    return 0;
}