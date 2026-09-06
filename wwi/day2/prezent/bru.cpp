#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n; // n


    for (int i = 0; i < n; i++) // from the beginning
    {
        
        
    }
}



// Prezent
// WWI 2026 – grupa 21/2 Kod zadania: pre
// Dzień 1 – 18 sierpnia 2026 Limit pamięci: 128 MiB
// Masz daną liczbę całkowitą n oraz n przedziałów liczb całkowitych. Dla każdego przedziału napisz, jaki jest rozmiar maksymalnego dobrego podzbioru tego przedziału oraz ile jest maksymalnych dobrych podzbiorów.
// Dobry podzbiór (nazwijmy go X) polega na tym, że dla każdych a, b ∈ X zachodzi a | b lub b | a. Maksymalny dobry
// podzbiór polega na tym, że ma największą (być może ex aequo) moc spośród wszystkich dobrych podzbiorów.
// Wejście
// W pierwszym wierszu standardowego wejścia znajduje się liczba całkowita n. Zachodzi 1 ≤ n ≤ 106
// . W i + 1-szym wierszu
// znajdują się dwie liczby całkowite pi
// , ki
// , oznaczające że i-ty przedział to [pi
// , ki
// ]. Zachodzi 1 ≤ pi ≤ ki ≤ 1018
// .
// Wyjście
// Na standardowym wyjściu powinno się znaleźć n wierszy oznaczające odpowiedzi na kolejne zapytania. W i-tym wierszu powinny się znaleźć dwie liczby całkowite oddzielone spacją: moc maksymalnego dobrego podzbioru oraz liczba maksymalnych
// dobrych podzbiorów w i-tym przedziale.
// Przykłady
// Wejście dla testu pre0a:
// 4
// 1 2
// 1 3
// 2 7
// 1 1
// Wyjście dla testu pre0a:
// 2 1
// 2 2
// 2 3
// 1 1
// Wyjaśnienie do przykładu: Możliwe maksymalne prezenty w życzeniach:
// 1. {1, 2}
// 2. {1, 2}, {1, 3}
// 3. {2, 4}, {2, 6}, {3, 6}
// 4. {1}
// Ocenianie
// Podzadanie Ograniczenia Limit czasu Liczba punktów
// 1 n ≤ 5, ki ≤ 20 10 s 9
// 2
// Pn
// i=1 ki − pi ≤ 106 6 s 12
// 3 Brak dodatkowych ograniczeń. 6 s 79
// Prezent
// © 2026 XIV LO im. Stanisława Staszica
// sio2.staszic.waw.pl
// Szablon treści zadania został zaadaptowany z szablonu
// stworzonego przez Bartosza Kostkę, dostępnego pod
// warunkami licencji CC BY-NC-SA 4.0.
// 1/1

// #include <iostream>

// using namespace std;

// int main() {
//     int n;
//     cout << "Podaj liczbe: ";
//     cin >> n;

//     cout << "Czynniki pierwsze: ";
//     int d = 2;

//     while (n > 1) {
//         while (n % d == 0) {
//             cout << d << " ";
//             n = n / d;
//         }
//         d++;
//     }

//     cout << endl;
//     return 0;
// }
