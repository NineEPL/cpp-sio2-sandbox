#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <random>
using namespace std;

int call(string cmd) {
    // cout << "Running: " << cmd << "\n";
    return system(cmd.c_str());
}

int main() {
    // Flagi kompilacji.
    string flags = "-Wall -Wextra -O3 -std=c++20 -fsanitize=undefined -fsanitize=address";

    // Kompilujemy programy.
    cout << "Kompilacja programów...\n";
    call("g++ " + flags + " -o gen gen.cpp");
    call("g++ " + flags + " -o wzo wzo.cpp");
    call("g++ " + flags + " -o bru bru.cpp");

    // Pętla nieskończona - testujemy aż nie znajdzie błędu albo się znudzimy.
    // Jeśli chcemy kontynuować testowanie od jakiegoś seeda, ustawiamy 'i' na ten seed.
    for (int i = 0; ; i++) {
        // Generujemy test z seedem 'i'.
        // Dodatkowo moglibyśmy upewniać się że programy nie wywalają błędu, otaczając calle w assert(call(...) == 0).
        call("echo " + to_string(i) + " | ./gen > test.in" );

        // Puszczamy test na wzorcówce i brucie.
        call("./wzo < test.in > wzo.out");
        call("./bru < test.in > bru.out");

        // Porównujemy wyjścia wzorcówki i bruta. Jeśli jest źle, wypisujemy na jakim seedzie i kończymy program.
        // Test na którym jest źle można odzyskać dając seeda jako wejście do generatorki.
        if (call("diff --ignore-all-space wzo.out bru.out") != 0) {
            cout << "WRONG ANSWER! Seed: " << i << "\n";
            return 0;
        }
        cout << "OK Seed: " << i << "\n";
    }
}
