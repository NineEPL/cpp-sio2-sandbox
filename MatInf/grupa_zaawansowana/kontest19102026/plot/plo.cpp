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
    ll n, m;
    cin >> n >> m;
    vector<bool> arr(n,false);
    for(ll i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        for(ll j = a-1; j < b; j++){
            arr[j] = true;
        }
    }
    ll res = 0;
    for(ll i = 0; i < n; i++){  
        if(arr[i] == false){
            res++;
        }
    }
    cout << res << endl;
    //brute force solution
    return 0;
}