#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll duzo = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (ll i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    ll left = 0, right = 0;
    ll roses = 0;
    ll cabages = 0;
    ll minV = duzo;

    while (right < n) {
        if (vec[right] == 1) roses++;
        else cabages++;

        while ((roses > m || vec[left] != 1)&& left < n) {
            if (vec[left] == 1) roses--;
            else cabages--;
            left++;
        }

        if (roses == m) {
            minV = min(minV, cabages);
        }

        right++;
    }

    if (minV == duzo) {
        cout << "NIE\n";
    } else {
        cout << minV << "\n";
    }

    return 0;
}
