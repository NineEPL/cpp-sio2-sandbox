#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;
const ll duzo = 1000000000+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;

    vector<ll> start(m+1);
    vector<ll> end(m+1);

    for(ll i = 0; i < n; i++){
        ll x,y;
        cin >> x >> y;
        start[x] += y;
        end[min(x+y-1,m)]++;
        //cout << start[x] << " " << end[x+y] << endl;
    }
    // for(ll i= 0; i<m; i++){
    //     cout << start[i] << " ";
    // }
    // cout << endl;
    // for(ll i= 0; i<m; i++){
    //     cout << end[i] << " ";
    // }
    // cout << endl;
    ll summ = 0;
    ll active = 0;
    ll max_v = -1;  
    ll min_v =duzo;
    ll max_p = 0;
    ll min_p = 0;

    for(ll i = 1; i <= m; i++){
        if (i == 1) {

            summ = start[i];

            if (start[i] > 0)
                active = 1;
        }
        else{
            summ -= active;
            active -= end[i-1];
            summ += start[i];
            if(start[i]){
                active++;
            }
        }
        if(summ > max_v){
            max_v = summ;
            max_p = i;
        }
        if(summ < min_v){
            min_v = summ;
            min_p=i;
        }
    }

    cout << max_p << " " << min_p<<endl;


    //cout << "HELP!!" << endl;
    return 0;
}

