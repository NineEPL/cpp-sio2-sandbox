#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    //cout << s << "\n";
    int n = s.size();

    int maxstreak = 0;
    int currstreak = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            currstreak++;
            if (currstreak > maxstreak) {
                maxstreak = currstreak;
            }
        } else {
            currstreak = 0;
        }
    }
    cout << maxstreak / 2<< "\n"; //niezdąyłem dopisać

    return 0;
}
