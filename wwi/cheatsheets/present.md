Kluczowa obserwacja:

Dobry podzbiór to po prostu **łańcuch w relacji podzielności**:

[
a_1 \mid a_2 \mid \dots \mid a_m
]

(po posortowaniu rosnąco).

---

## 1. Maksymalny rozmiar

Jeżeli liczby są różne, to

[
a_{i+1}\ge 2a_i
]

bo najmniejsza wielokrotność większa od (a_i) to (2a_i).

Dlatego

[
a_m \ge a_1\cdot 2^{m-1}.
]

Skoro (a_1\ge p) i (a_m\le k), to

[
p\cdot 2^{m-1}\le k.
]

Zatem

[
m\le \left\lfloor \log_2 \frac{k}{p}\right\rfloor +1.
]

I ten wynik zawsze da się osiągnąć biorąc

[
x,;2x,;4x,\dots,2^{m-1}x.
]

Stąd

[
\boxed{m=\max{t:; p\cdot 2^{t-1}\le k}}
]

czyli

[
\boxed{m=d+1}
]

gdzie

[
d=\max{r:; p\cdot 2^r\le k}.
]

---

## 2. Jak wyglądają wszystkie maksymalne łańcuchy?

Mamy (d) przejść między kolejnymi elementami.

Niech mnożniki będą:

[
c_1,c_2,\dots,c_d,\qquad c_i\ge 2.
]

Wtedy

[
a_m=a_1\cdot P,
\qquad
P=\prod c_i.
]

Ponieważ

[
2^d p\le k<2^{d+1}p,
]

to dla maksymalnego łańcucha musi zachodzić

[
P<2^{d+1}.
]

Najmniejsze możliwe (P) to (2^d).

Jeżeli:

* dwa mnożniki byłyby równe 3, to

[
P\ge 2^d\left(\frac32\right)^2

> 2^{d+1},
> ]

* jakiś mnożnik byłby (\ge4), to

[
P\ge 2^{d+1}.
]

Więc jedyne możliwości:

### Typ A

Wszystkie mnożniki równe 2.

[
P=2^d.
]

Liczba takich łańcuchów:

[
A=
\max!\left(0,\left\lfloor\frac{k}{2^d}\right\rfloor-p+1\right).
]

---

### Typ B

Dokładnie jeden mnożnik jest równy 3,
reszta równa 2.

[
P=3\cdot 2^{d-1}.
]

Takich pozycji dla „trójki” jest (d).

Dla ustalonej pozycji liczba możliwych początków:

[
B=
\max!\left(
0,
\left\lfloor
\frac{k}{3\cdot 2^{d-1}}
\right\rfloor-p+1
\right).
]

Łącznie:

[
d\cdot B.
]

---

## Odpowiedź

[
\boxed{
\text{size}=d+1
}
]

oraz

[
\boxed{
\text{count}
============

A+d\cdot B
}
]

gdzie

[
A=
\max!\left(0,\left\lfloor\frac{k}{2^d}\right\rfloor-p+1\right),
]

[
B=
\max!\left(
0,
\left\lfloor
\frac{k}{3\cdot 2^{d-1}}
\right\rfloor-p+1
\right)
]

((B=0) gdy (d=0)).

---

### Złożoność

Dla każdego zapytania trzeba znaleźć (d).

Ponieważ (k\le 10^{18}),

[
d\le 59.
]

Można więc znaleźć (d) w (O(60)).

Dla (n=10^6):

[
10^6\cdot 60 = 6\cdot 10^7
]

prostych operacji — spokojnie mieści się w limicie w C++.

```cpp
#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;
using u128 = __uint128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        long long p, k;
        cin >> p >> k;

        int d = 0;

        while ((u128)p * ((u128)1 << (d + 1)) <= (u128)k)
            d++;

        long long size = d + 1;

        u128 pow2 = (u128)1 << d;

        long long A = 0;
        u128 t = (u128)k / pow2;
        if (t >= (u128)p)
            A = (long long)(t - p + 1);

        long long B = 0;

        if (d > 0) {
            u128 prod = 3 * ((u128)1 << (d - 1));

            u128 t2 = (u128)k / prod;

            if (t2 >= (u128)p)
                B = (long long)(t2 - p + 1);
        }

        long long cnt = A + 1LL * d * B;

        cout << size << ' ' << cnt << '\n';
    }
}
```

To jest pełne rozwiązanie pod 79 punktów.












Na najmniejsze podzadanie (`k <= 20`) można zrobić kompletny brute force po wszystkich podzbiorach przedziału.

Idea:

* wygeneruj wszystkie liczby z przedziału `[p, k]`,
* przejdź po wszystkich maskach `0...(2^len-1)-1`,
* sprawdź, czy wybrany podzbiór jest dobry:

  * dla każdej pary `(a,b)` musi zachodzić `a|b` lub `b|a`,
* jeśli jest dobry:

  * policz jego rozmiar,
  * aktualizuj najlepszy wynik.

Złożoność:

[
O(2^m \cdot m^2)
]

gdzie (m = k-p+1).

Dla podzadania `k <= 20` mamy najwyżej `m=20`, więc:

[
2^{20}\approx 10^6
]

co przejdzie.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // liczba zapytań

    while (n--) {

        int p, k;
        cin >> p >> k; // przedział [p, k]

        vector<int> nums;

        // zapisujemy wszystkie liczby z przedziału
        for (int x = p; x <= k; x++)
            nums.push_back(x);

        int m = nums.size();

        int bestSize = 0;        // największy znaleziony rozmiar dobrego podzbioru
        long long bestCount = 0; // liczba maksymalnych dobrych podzbiorów

        // przechodzimy po wszystkich podzbiorach
        // maska bitowa:
        // bit i = 1 => nums[i] należy do podzbioru
        for (int mask = 0; mask < (1 << m); mask++) {

            vector<int> subset;

            // budujemy aktualny podzbiór z maski
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i))
                    subset.push_back(nums[i]);
            }

            bool good = true;

            // sprawdzamy warunek zadania:
            // dla każdej pary liczb
            // a | b lub b | a
            for (int i = 0; i < (int)subset.size() && good; i++) {

                for (int j = i + 1; j < (int)subset.size(); j++) {

                    long long a = subset[i];
                    long long b = subset[j];

                    // jeśli żadna liczba nie dzieli drugiej,
                    // podzbiór nie jest dobry
                    if (a % b != 0 && b % a != 0) {
                        good = false;
                        break;
                    }
                }
            }

            // pomijamy złe podzbiory
            if (!good)
                continue;

            int sz = subset.size();

            // znaleźliśmy większy dobry podzbiór
            if (sz > bestSize) {
                bestSize = sz;
                bestCount = 1;
            }

            // znaleźliśmy kolejny maksymalny podzbiór
            else if (sz == bestSize) {
                bestCount++;
            }
        }

        cout << bestSize << " " << bestCount << "\n";
    }

    return 0;
}




#include <bits/stdc++.h>
using namespace std;

int bestSize;          // największy znaleziony rozmiar
long long bestCount;   // liczba maksymalnych podzbiorów

vector<int> nums;      // liczby z przedziału
vector<int> current;   // aktualnie budowany podzbiór

// sprawdza czy podzbiór spełnia warunek zadania
bool isGood() {

    for (int i = 0; i < (int)current.size(); i++) {

        for (int j = i + 1; j < (int)current.size(); j++) {

            int a = current[i];
            int b = current[j];

            // musi zachodzić a|b lub b|a
            if (a % b != 0 && b % a != 0)
                return false;
        }
    }

    return true;
}

// generujemy wszystkie podzbiory
void generate(int pos) {

    // rozważyliśmy już wszystkie liczby
    if (pos == (int)nums.size()) {

        if (isGood()) {

            int sz = current.size();

            if (sz > bestSize) {
                bestSize = sz;
                bestCount = 1;
            }
            else if (sz == bestSize) {
                bestCount++;
            }
        }

        return;
    }

    // OPCJA 1: nie bierzemy nums[pos]
    generate(pos + 1);

    // OPCJA 2: bierzemy nums[pos]
    current.push_back(nums[pos]);

    generate(pos + 1);

    // cofamy zmianę (backtracking)
    current.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {

        int p, k;
        cin >> p >> k;

        nums.clear();
        current.clear();

        for (int x = p; x <= k; x++)
            nums.push_back(x);

        bestSize = 0;
        bestCount = 0;

        generate(0);

        cout << bestSize << " " << bestCount << "\n";
    }

    return 0;
}