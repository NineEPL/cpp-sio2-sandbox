// Mnoży dwie liczby. Zawiera bład.
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <random>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    // Jako że a i b mogą być nawet wielkości 50000, pomnożone mogą wyjść poza zakres inta (overflow), co jest błędem.
    cout << a * b << "\n";
}
