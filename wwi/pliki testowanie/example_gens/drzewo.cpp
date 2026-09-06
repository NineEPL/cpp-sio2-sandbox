// Generuje drzewo o n wierzchołkach dla danego seeda.

// Dołączenie standardowej biblioteki nagłówkowej w C++, która zawiera
// większość potrzebnych narzędzi (m.in. iostream, random, vector itp.)
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <random>


// Użycie przestrzeni nazw std, co pozwala pisać np. 'cout' zamiast 'std::cout'
using namespace std;

int main() {
    // Wyłączenie synchronizacji strumieni C i C++ dla szybszego wejścia/wyjścia
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s; // Zmienna do przechowywania ziarna (seed) dla generatora losowego
    cin >> s; // Wczytanie ziarna podanego przez użytkownika

    // Tworzenie generatora liczb pseudolosowych Mersenne Twister (odporny i szybki)
    mt19937 gen;
    
    // Ustawienie ziarna generatora. Dzięki temu dla tego samego 's' 
    // kod zawsze wygeneruje dokładnie to samo drzewo (powtarzalność wyników)
    gen.seed(s);

    // Liczba wierzchołków w generowanym drzewie (stała wartość = 10)
    int n = 10;
    
    // Wypisanie liczby wierzchołków na standardowe wyjście
    cout << n << "\n";

    // Pętla generująca krawędzie drzewa.
    // Drzewo o 'n' wierzchołkach zawsze posiada dokładnie 'n - 1' krawędzi.
    // Przechodzimy po kolejnych wierzchołkach od 1 do n-1:
    for (int i = 1; i < n; ++i) {
        int a = i; // Aktualnie dołączany nowy wierzchołek (indeksowany od 0)
        
        // Wybieramy losowo jeden z już istniejących wierzchołków (od 0 do i-1),
        // do którego podłączymy nowy wierzchołek 'a'.
        // Gwarantuje to spójność grafu i brak cykli (powstaje poprawne drzewo).
        int b = gen() % i; 

        // Wypisujemy krawędź łączącą wierzchołki 'a' oraz 'b'.
        // Dodajemy 1 do obu zmiennych, aby zmienić numerację z 0-indexed na 1-indexed
        // (tj. wierzchołki będą miały numery od 1 do n zamiast od 0 do n-1).
        cout << a + 1 << " " << b + 1 << "\n";
    }

    return 0; // Pomyślne zakończenie programu
}