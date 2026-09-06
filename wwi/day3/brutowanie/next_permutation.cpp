#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int n = 4;
    vector<int> permutacja{1, 1, 2, 2};

    //for (int i = 1; i <= n; ++i) {
    //    permutacja.push_back(i);
    //}

    do {
        for (int liczba : permutacja) {
            cout << liczba << ' ';
        }
        cout << '\n';
        // next_permutation, podobnie jak sort, wywołujemy na zakresie [begin, end).
        // Zwraca bool: true, jeśli istnieje następna permutacja,
        // albo false, jeśli bieżąca permutacja była ostatnia.
    } while (next_permutation(permutacja.begin(), permutacja.end()));
}
