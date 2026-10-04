#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
#include <deque>
using namespace std;
using ll = long long;
const ll duzo = 200000000000007;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b; // i don't like that...
    cin >> n >> a >> b;

    vector<ll> arr(n+1); // ima pirate arr!!
    vector<ll> pref(n+1,0); //sumy prefiksowe 
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i]; // fock this shit i had arr[1] instead of arr[i] here
    }
    // for(ll i = 1; i <= n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // for(ll i = 1; i <= n; i++){
    //     cout << pref[i] << " ";
    // }
    // cout << endl;

    deque<ll> dq;// here we go...

    ll maxs = duzo*(-1);
    //cout << maxs <<endl;

    for(ll i = a; i <= n; i++){
        while(!dq.empty() && pref[dq.back()] >= pref[i-a]){
            dq.pop_back();
        }
        dq.push_back(i-a);

        while(!dq.empty() && dq.front() < i-b){
            dq.pop_front();
        }
        //cout << dq.front() << " " << dq.back() << " "<< maxs << " " << pref[i]-pref[dq.front()] << endl;

        maxs = max(maxs,pref[i]-pref[dq.front()]);
    }
    cout << maxs << endl;
    


    //cout << "HELP!!" << endl;
    return 0;
}