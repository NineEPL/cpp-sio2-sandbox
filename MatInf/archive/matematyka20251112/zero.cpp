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
    vector<ll> arr(n+1);
    map<ll, ll> random;
    arr[0] = 0;
    random[0] = 1;
    ll count = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
        random[arr[i]]++;
    }
    for (auto it : random) {
        ll c = it.second;
        count += (c * (c - 1)) / 2;
    }
    // // debug
    // for(ll i = 0; i <= n; i++){
    //     cout << arr[i] << " ";
    // }
    //cout << "\n";
    cout << count << "\n";
    return 0;

}