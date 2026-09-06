#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    const int n = 4;

    // std::bitset jest szablonem, a jego rozmiar jest parametrem tego szablonu.
    // Dlatego kompilator musi znac rozmiar bitsetu juz podczas kompilacji.
    // Ponizsza proba utworzenia bitsetu o rozmiarze z wejscia nie skompiluje sie:
    // int rozmiar;
    // cin >> rozmiar;
    // bitset<rozmiar> dynamiczny_bitset; // BLAD: rozmiar nie jest stala

    // Jesli rozmiar danych poznamy dopiero na wejsciu, ustalamy odpowiednio duzy
    // maksymalny rozmiar i korzystamy tylko z potrzebnych bitow.
    const int maksymalny_rozmiar = 1000;
    bitset<maksymalny_rozmiar> duzy_bitset;

    // Wszystkie 2^n masek: od 0 do 2^n - 1.
    cout << "Wszystkie maski:\n";
    for (int maska = 0; maska < (1 << n); ++maska) {
        cout << bitset<n>(maska) << '\n';
    }

    bitset<8> bity(string("00101101"));
    cout << "\nNa poczatku: " << bity << '\n';

    // Odczyt pojedynczego bitu. Bity numerujemy od prawej strony, zaczynajac od 0.
    cout << "Bit numer 2: " << bity[2] << '\n';
    cout << "Bit numer 3: " << bity.test(3) << '\n';

    // Zmiana pojedynczych bitow.
    bity.set(1);       // Ustawia bit numer 1 na 1.
    bity.reset(2);     // Ustawia bit numer 2 na 0.
    bity.flip(3);      // Zmienia bit numer 3 na przeciwny.
    bity[0] = false;   // Bit mozna tez zmienic za pomoca operatora [].
    cout << "Po zmianach: " << bity << '\n';

    // Operacje na wszystkich bitach naraz.
    bity.set();
    cout << "set():   " << bity << '\n';
    bity.reset();
    cout << "reset(): " << bity << '\n';
    bity.flip();
    cout << "flip():  " << bity << '\n';

    // Informacje o bitsecie.
    cout << "Liczba jedynek: " << bity.count() << '\n';
    cout << "Liczba bitow: " << bity.size() << '\n';
    cout << "Czy jest jakas jedynka? " << bity.any() << '\n';
    cout << "Czy wszystkie bity to jedynki? " << bity.all() << '\n';
    cout << "Czy wszystkie bity to zera? " << bity.none() << '\n';

    // Operatory bitowe.
    bitset<8> a(string("11001100"));
    bitset<8> b(string("10101010"));
    cout << "\na     = " << a << '\n';
    cout << "b     = " << b << '\n';
    cout << "a & b = " << (a & b) << '\n'; // AND
    cout << "a | b = " << (a | b) << '\n'; // OR
    cout << "a ^ b = " << (a ^ b) << '\n'; // XOR
    cout << "~a    = " << (~a) << '\n';     // NOT
    cout << "a << 2 = " << (a << 2) << '\n';
    cout << "a >> 2 = " << (a >> 2) << '\n';

    // Konwersja bitsetu na liczbe i napis.
    cout << "a jako liczba: " << a.to_ulong() << '\n';
    string napis = a.to_string();
    cout << "a jako napis: " << napis << '\n';

    return 0;
}
