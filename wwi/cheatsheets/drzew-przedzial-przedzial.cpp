#include <vector>
#include <iostream>
#include <queue>
#include <random>
#include <cmath>
#include <algorithm>

using ll = long long;
using namespace std;

/*
    DRZEWO PRZEDZIAŁOWE (SEGMENT TREE) Z LAZY PROPAGATION

    Obsługiwane operacje:
    1. Dodanie wartości x do wszystkich elementów na przedziale [a, b]
    2. Znalezienie maksimum na przedziale [a, b]

    Złożoność:
    - aktualizacja przedziału: O(log N)
    - zapytanie o maksimum: O(log N)

    Lazy propagation pozwala odkładać aktualizacje na później,
    dzięki czemu nie musimy schodzić do wszystkich liści przy
    każdej operacji dodawania na dużym przedziale.
*/

// Rozmiar podstawy drzewa.
// Musi być potęgą dwójki i >= maksymalnej liczbie elementów.
const int baza = (1 << 19);

/*
    segtree[v][0] - maksimum przechowywane przez wierzchołek v
    segtree[v][1] - "lazy value", czyli wartość oczekująca na
                    zepchnięcie do dzieci

    Numeracja:
                1
             /     \
            2       3
          /  \    /   \
         4   5   6     7
         ...

    Liście znajdują się w zakresie [baza, 2*baza-1].
*/
long long segtree[2 * baza][2];

/*
    Funkcja push(v)

    Przekazuje ("spycha") odłożoną aktualizację z wierzchołka v
    do jego dwóch dzieci.

    Jeśli do całego przedziału reprezentowanego przez v dodaliśmy
    wcześniej jakąś wartość i zapisaliśmy ją tylko w lazy,
    to przed zejściem niżej musimy przekazać tę informację dzieciom.
*/
void push(int v)
{
    // Dodajemy lazy do lewego syna:
    segtree[2 * v][0] += segtree[v][1]; // aktualizacja maksimum
    segtree[2 * v][1] += segtree[v][1]; // aktualizacja lazy

    // Dodajemy lazy do prawego syna:
    segtree[2 * v + 1][0] += segtree[v][1];
    segtree[2 * v + 1][1] += segtree[v][1];

    // Po przekazaniu aktualizacji węzeł v nie ma już nic do zepchnięcia.
    segtree[v][1] = 0;
}

/*
    Dodaj wartość x na przedziale [a, b].

    Parametry:
    a, b - przedział aktualizacji
    x    - wartość do dodania

    v    - aktualny wierzchołek drzewa
    l, r - przedział reprezentowany przez wierzchołek v
*/
void dodaj(int a, int b, int x, int v, int l, int r)
{
    // Brak przecięcia przedziałów:
    // [l, r] ∩ [a, b] = ∅
    if (r < a || l > b)
        return;

    // Aktualny przedział w całości zawiera się
    // w przedziale aktualizacji.
    if (a <= l && r <= b)
    {
        // Aktualizujemy maksimum.
        segtree[v][0] += x;

        // Zapamiętujemy aktualizację w lazy.
        segtree[v][1] += x;
    }
    else
    {
        // Częściowe przecięcie.
        // Musimy zejść do dzieci.

        push(v);

        int mid = (l + r) / 2;

        // Aktualizacja lewego dziecka.
        dodaj(a, b, x, 2 * v, l, mid);

        // Aktualizacja prawego dziecka.
        dodaj(a, b, x, 2 * v + 1, mid + 1, r);

        // Po aktualizacji dzieci przeliczamy maksimum
        // dla aktualnego wierzchołka.
        segtree[v][0] =
            max(segtree[2 * v][0],
                segtree[2 * v + 1][0]);
    }
}

/*
    Znajdź maksimum na przedziale [a, b].

    Parametry:
    a, b - szukany przedział
    v    - aktualny wierzchołek
    l, r - przedział reprezentowany przez v

    Zwraca:
    największą wartość na przecięciu [l, r] i [a, b].
*/
long long maks(int a, int b, int v, int l, int r)
{
    // Brak przecięcia przedziałów.
    if (r < a || l > b)
    {
        // Zwracamy bardzo małą liczbę,
        // żeby nie wpływała na wynik funkcji max().
        return -(1LL << 60);
    }

    // Aktualny przedział w całości zawiera się
    // w przedziale zapytania.
    if (a <= l && r <= b)
        return segtree[v][0];

    // Częściowe przecięcie.
    push(v);

    int mid = (l + r) / 2;

    // Maksimum z lewego poddrzewa.
    long long lewy =
        maks(a, b, 2 * v, l, mid);

    // Maksimum z prawego poddrzewa.
    long long prawy =
        maks(a, b, 2 * v + 1, mid + 1, r);

    return max(lewy, prawy);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
        Przykład użycia:

        dodaj(2, 5, 10, 1, 0, baza - 1);
            dodaj 10 do wszystkich pozycji z zakresu [2,5]

        cout << maks(0, 10, 1, 0, baza - 1);
            wypisz maksimum na przedziale [0,10]

        Korzeń drzewa zawsze ma:
        v = 1
        l = 0
        r = baza - 1
    */

    return 0;
}

