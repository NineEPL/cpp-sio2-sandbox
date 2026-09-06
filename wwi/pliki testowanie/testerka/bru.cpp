// Mnoży dwie liczby dodając je do siebie wielokrotnie.
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    long long result = 0;
    for (int i = 0; i < a; i++) {
        result += b;
    }
    cout << result;
}
