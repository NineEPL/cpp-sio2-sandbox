#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n; 
    ll res = 0;
    ll p = 1;
    //cout << n << endl;
    for(ll i = 1; p*5 <= n; i++){
        //cout << res << " " << pow(5,i) << " " <<n/pow(5,i) << endl;
        
        res += n/(p*5);
        p *= 5;
    }

    cout << res << endl;
    return 0;
}


