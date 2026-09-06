#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    ll counter = 0;
    string result;

    for (char c : s) {
        int len = result.size();
        if (len >= 1 && result[len - 1] == c) {
            counter++;  
            continue;
        }
        if (len >= 2 && result[len - 2] == c) {
            counter++;
            continue;
        }
        result += c;
    }

    cout << counter << "\n";
    return 0;
}