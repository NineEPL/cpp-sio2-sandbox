#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n+1), b(n+1), c(n+1);
    a[0] = 0;
    b[0] = 0;
    c[0] = 0;
    for(ll i =1; i <= n; i++){
        ll ta, tb, tc;
        cin >> ta >> tb >> tc;
        a[i] = max(b[i-1], c[i-1]) + ta;
        b[i] = max(a[i-1], c[i-1]) + tb;
        c[i] = max(a[i-1], b[i-1]) + tc;
    }
    cout << max(a[n], max(b[n], c[n])) << endl;
    return 0;
}