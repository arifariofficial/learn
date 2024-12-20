#include <iostream>

using namespace std;

int *bubblesort(int a[], int n) {
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

int bubble_sort() {
    int number;
    cout << "Syötä elementtien kokonaismäärä: ";
    cin >> number;
    int list[number];
    for (int i = 0; i < number; i++) {
        int value;
        cout << "Syötä elementti " << i + 1 << ": ";
        cin >> value;
        list[i] = value;
    }
    int *sorted = bubblesort(list, number);
    cout << "Lajiteltu lista nousevassa järjestyksessä: [";
    for (int i = 0; i < number - 1; i++) {
        cout << sorted[i] << ", ";
    }
    cout << sorted[number - 1] << "]" << endl;

    return 0;
}

int main() {
    return bubble_sort();
}