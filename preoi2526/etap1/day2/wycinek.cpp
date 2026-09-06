#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, s;
    cin >> n >> s;
    vector<ll> pref(n+1);
    pref[0] = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> pref[i];
        pref[i] += pref[i-1];
    }


    unordered_map<ll, ll> first_pos;
    first_pos.reserve(n+1);
    first_pos[pref[0]] = 0;

    ll best = 0; 
    for (ll i = 1; i <= n; i++) {
        ll needed = pref[i] - s;
        if (first_pos.count(needed)) {
            ll length = i - first_pos[needed];
            if (length > best) best = length;
        }
        if (!first_pos.count(pref[i])) {
            first_pos[pref[i]] = i;
        }
    }

    if (best == 0) {
        cout << "BRAK\n";
    } else {
        cout << best << "\n";
    }
    return 0;
}
