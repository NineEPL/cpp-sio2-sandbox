#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    ll mod;
    cin >> n >> mod;

    vector<ll> vek(n);
    for (ll i = 0; i < n; ++i)
        cin >> vek[i];

    vector<ll> dp_len(n, 1);  
    vector<ll> licz(n, 1); 

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < i; ++j) {
            if (vek[j] < vek[i]) {
                if (dp_len[j] + 1 > dp_len[i]) {
                    dp_len[i] = dp_len[j] + 1;
                    licz[i] = licz[j];
                } else if (dp_len[j] + 1 == dp_len[i]) {
                    licz[i] = (licz[i] + licz[j]) % mod;
                }
            }
        }
    }

    ll mlen = *max_element(dp_len.begin(), dp_len.end());
    ll ans = 0;
    for (ll i = 0; i < n; ++i)
        if (dp_len[i] == mlen)
            ans = (ans + licz[i]) % mod;

    cout << ans % mod << "\n";
    return 0;
}
