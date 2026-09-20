//punktprzedzial
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
using ll = long long;

const ll maxn = pow(2,17);
const ll double_maxn = 2*maxn;
ll tree[262144]; // f#cking compilator!!!!!!!!! WAaaaaaaaaaaaa!!!!!

void update(ll pos, ll val){
    ll i = pos + maxn;
    tree[i] = val;
    while(i > 1){
        i /= 2;
        tree[i] = max(tree[2*i], tree[2*i+1]);
    }
}

ll search(ll l, ll r){
    l += maxn;
    r += maxn;
    ll ans = 0;
    while(l <= r){
        if(l%2 == 1) ans = max(ans, tree[l++]);
        if(r%2 == 0) ans = max(ans, tree[r--]);
        l /= 2;
        r /= 2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll t, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t >> a >> b;
        if(t == 0){
            update(a, b);
        }
        else{
            cout << search(a, b) << endl;
        }
    }



    // cout << "HELP!!" << endl;
    return 0;
}