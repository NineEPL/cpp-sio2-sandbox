#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    map<ll, ll> counts;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        counts[x]++;
    }
    ll max_count = 0;
    for (auto& p : counts) {
        max_count = max(max_count, p.second);
    }
    cout << max_count + (n - max_count)*2 << "\n";
    return 0;
}