#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vec(n);
    char action;
    ll x;
    cin >> action >> x;
    vec[0] = {x, 0};
    for(int i = 1; i < n; ++i){
    cin >> action >> x;
    }

}
