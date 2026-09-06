// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// using ll = long long;

// bool condition(ll a, ll b)
// {
//     return a > b;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     ll prod_a, prom_a;
//     cin >> prod_a >> prom_a;
//     vector<ll> prod(prod_a);
//     vector<ll> prom(prom_a);
//     for (ll i = 0; i < prod_a; i++)
//     {
//         cin >> prod[i];
//     }
//     for (ll i = 0; i < prom_a; i++)
//     {
//         cin >> prom[i];
//     }
//     sort(prom.begin(), prom.end());
//     sort(prod.begin(), prod.end(), condition);

//     // //debug
//     // for(ll i = 0; i < prom_a; i++){
//     //      cout << prom[i] << " ";
//     // }
//     // cout << endl;
//     // for(ll i = 0; i < prod_a; i++){
//     //         cout << prod[i] << " ";
//     // }
//     // cout << endl;
//     // //end debug
//     ll sum = 0;
//     ll j = 0;

//     for (ll i = 0; i < prom_a; i++)
//     {
//         prod[i + j - 1] = 0;
//         j += prom[i]-1;
//     }
//     for (ll i = 0; i < prod_a; i++)
//     {
//         sum += prod[i];
//     }
//     cout << sum << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> prod(n);
    vector<ll> prom(k);

    for (ll i = 0; i < n; i++) cin >> prod[i];
    for (ll i = 0; i < k; i++) cin >> prom[i];

    sort(prod.begin(), prod.end(), greater<ll>());  
    sort(prom.begin(), prom.end());  

    ll sum = 0;
    for (ll x : prod) sum += x;

    ll idx = 0;

    for (ll c : prom) {
        if (idx + c > n) break; 
        sum -= prod[idx + c - 1];
        idx += c;
    }

    cout << sum << "\n";
    return 0;
}
