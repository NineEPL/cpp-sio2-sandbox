#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
using ll = long long;

bool condition(pair<ll,ll> a, pair<ll,ll> b){
    return a.second - a.first < b.second - b.first;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll,ll> > vek(n);
    for(ll i = 0; i < n; i++){
        cin >> vek[i].first >> vek[i].second;
    }
    sort(vek.begin(), vek.end(), condition);

    //debug
    // for(ll i=0; i<n; i++){
    //     cout << vek[i].first << " " << vek[i].second << endl;
    // }
    
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        sum += vek[i].first * i + vek[i].second * (n - i - 1);
    }
    cout << sum << endl;
    return 0;

}
