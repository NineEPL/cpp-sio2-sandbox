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
    vector<ll> avg(3,0);
    cin >> avg[0] >> avg[1] >> avg[2];
    ll wm = avg[0] + avg[1] + avg[2];
    sort(avg.begin(),avg.end());
    cout << wm - avg[1]*2;

    
    // ):shura shura:(
    return 0;
}