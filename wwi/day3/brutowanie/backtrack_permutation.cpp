#include <iostream>
#include <vector>

using namespace std;

const int n = 4;
vector<int> permutacja(n);
bool uzyta[n + 1];

void generuj(int pozycja) {
    if (pozycja == n) {
        for (int x : permutacja) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    for (int x = 1; x <= n; ++x) {
        if (!uzyta[x]) {
            // Wykonujemy wybor.
            permutacja[pozycja] = x;
            uzyta[x] = true;

            generuj(pozycja + 1);

            // Cofamy wybor - to jest backtracking.
            uzyta[x] = false;
        }
    }
}

int main() {
    generuj(0);
    return 0;
}
