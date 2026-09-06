// Generuje wszystkie permutacje n liczb podanych przez użytkownika.

// Dołączenie standardowej biblioteki nagłówkowej w C++, która zawiera
// wszystkie potrzebne narzędzia (iostream, vector, algorithm itd.)
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <random>

// Użycie przestrzeni nazw std, aby nie pisać np. 'std::vector' czy 'std::cout'
using namespace std;

int main() {
    // Optymalizacja operacji wejścia/wyjścia (przyspiesza wczytywanie i wypisywanie danych)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // Zmienna określająca liczbę elementów
    cin >> n; // Wczytanie liczby elementów

    vector<int> a; // Dynamiczna tablica (wektor) na wczytywane liczby

    // Pętla wczytująca 'n' liczb od użytkownika
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x); // Dodanie wczytanej liczby na koniec wektora
    }

    // Sortowanie wektora w kolejności rosnącej.
    // Jest to kluczowe, ponieważ 'std::next_permutation' generuje permutacje 
    // w porządku leksykograficznym (słownikowym). Aby uzyskać WSZYSTKIE permutacje,
    // musimy zacząć od najmniejszej możliwej (czyli posortowanej rosnąco).
    sort(a.begin(), a.end());

    // Używamy pętli 'do ... while' zamiast zwykłego 'while'.
    // Dzięki temu NAJPIERW wypisujemy aktualną (w tym przypadku pierwszą, posortowaną)
    // permutację, a DOPIERO POTEM funkcja 'next_permutation' zmienia układ elementów na następny.
    do {
        // Pętla zakresowa (range-based for) wypisująca każdy element wektora
        for (int x : a) {
            cout << x << " ";
        }
        cout << "\n"; // Przejście do nowej linii po wypisaniu całej permutacji

    // Funkcja 'std::next_permutation' modyfikuje wektor 'a' do kolejnej permutacji.
    // Zwraca 'true', jeśli uda się wygenerować kolejną permutację, 
    // lub 'false', gdy dotrze do ostatniej (największej, posortowanej malejąco).
    } while (next_permutation(a.begin(), a.end()));

    return 0; // Pomyślne zakończenie programu
}

/*
Przykładowe wejście:
4
1 2 3 4
*/