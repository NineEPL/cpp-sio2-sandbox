// Wczytuje seeda i na jego podstawie generuje 2 liczby z zakresu [1, 50000].
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <random>
using namespace std;

// mt19937_64 dla liczb 64-bitowych.
mt19937 gen;

// Zwraca liczbę z przedziału [a, b]
int gen_range(int a, int b) {
    return gen() % (b - a + 1) + a;
}

int main() {
    int seed;
    cin >> seed;
    gen.seed(seed);

    cout << gen_range(1, 50000) << " " << gen_range(1, 50000) << "\n";
}
