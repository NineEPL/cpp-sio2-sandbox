#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> vek(n);
    for(ll i = n-1; i >= 0; i--){
        cin >> vek[i];
    }
    ll sum = 0;
    ll minw = vek[0];
    for(ll i = 0; i < n; i++){
        if(vek[i] <= minw ){
            sum += vek[i];
            minw = vek[i];
        }
        else{
            sum += minw;
        }
    }
    cout << sum << endl;
    return 0;

}