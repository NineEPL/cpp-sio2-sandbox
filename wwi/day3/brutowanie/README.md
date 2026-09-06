# Brutowanie

### std::next_permutation
- Składnia:
```
vector<int> vec{1, 2, 3, 4};

do
{
    sprawz_permutacje(vec);
} while(next_permutation(vec.begin(), vec.end()));
```
- Ustawia następną permutację w porządku leksykograficznym, chyba że podana permutacja jest ostatnia, to ustawia pierwszą permutację.
- Zwraca true jeśli ustawiło większą permutację i false jeśli wróciło do pierwszej permutacji.
- Jedno wywołanie next_permutation zajmuje O(n) czasu, gdzie n to długość tablicy.
- Przejście po wszystkich permutacjach zajmuje O(n*n!) czasu.
- To wchodzi czasowo dla n nie większych niż około 10.
- Jeśli elementy tablicy są takie same, to jest mniej permutacji.
- Więcej kodu i przykładów w [next_permutation.cpp](next_permutation.cpp)

### Iterowanie po podzbiorach
- Można iterować po podzbiorach za pomocą mask bitowych.
- Żeby się przeiterować po wszystkich podzbiorach, trzeba się przeiterować po wszystkich maskach długości n, czyli po liczbach od 0 do 2^n.
- Żeby sprawdzić, czy i-ty element maski bitowej jest zapalony, musimy zrobić and bitowy maski i 2^i.
- Przykład znajduje się w [podzbiory.cpp](podzbiory.cpp)

### std::bitset
- Składnia:
```
std::bitset<100> bity();
bity.set(0);
bity[0] = 0;
```
- Bity są w grupach po 64, tzn. zamiast trzymać każdy bit w osobnym bajcie, jak tablica bool, to są wykorzystane słowa maszynowe.
- Dzięki temu zużywa się mniej pamięci.
- Dzięki temu można wykonywać niektóre operacje, np. xor bitowy, 64 razy szybciej, ponieważ te operacje się wykonują na całych grupach na raz.
- Tak jak tablica i std::array, bitset jest niezainicjalizowany jeśli się go stworzy w funkcji (np. main). Należy użyć konstruktora lub bitset.set().
- Tak jak tablica i std::array, bitset stworzony w funkcji jest alokowany na stacku i może spowodować stack overflow.
- Więcej kodu i przykładów w [bitset.cpp](bitset.cpp)

### Backtrack
- Jest to sposób na przeiterowanie się po wszystkich możliwych stanach czegoś.
- Polega na tym, że każdy stan się rekurencyjnie wywołuje po sąsiednich stanach.
- Niektóre stany są graniczne, tzn. nie wywołują dalej rekurencji. Warto zrobić tak, że się sprawdza czy jest przypadek graniczny na początku wywołania rekurencyjnego.
- Warto pisać break i return gdy można. Dobrym przykładem jest sytuacja, w której szukamy "dobrego" stanu. Gdy jesteśmy w jakimś stanie i mamy pętlę po sąsiednich stanach, to warto napisać return w przypadku, gdy jeden z sąsiednich stanów znajdzie dobry stan. Wtedy być może zaoszczędzimy dużo czasu, np. gdy dobre stany są częste. W przeciwnym przypadku byśmy przeszukali wszystkie stany.
- Więcej kodu i przykładów w [backtrack_permutation.cpp](backtrack_permutation.cpp)