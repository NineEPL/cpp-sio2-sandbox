#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;

const ll maxn = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // vector<vector<ll> > arr(maxn, vector<ll>());
    // for (ll i = 1; i <= n; i++)
    // {
    //     set<ll> st;
    //     for (ll j = 0; j < m; j++)
    //     {
    //         ll x;
    //         cin >> x;
    //         st.insert(x);
    //     }
    // //     for(ll v : st){
    // //         arr[v].push_back(i);
    // //     }
    // // }

    // cout << "AAAAAAAAAA";
    // // for(ll i = 0; i < 10; i++){
    // //     for(ll j = 0; j < arr[i].size(); j++){
    // //         cout << arr[i][j] << " ";
    // //     }
    // //     cout << endl;
    // // }
    // return 0;

    ll n , m;
    cin >> n >> m;

    vector <pair<ll,ll > > cukr; // position and type

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            ll x;
            cin >> x;
            cukr.push_back(make_pair(x,i));
        }
    }

    // for(ll i = 0; i < n*m; i++)
    // {
    //     cout << cukr[i].first << " " << cukr[i].second << endl;
    // }
    ll min_l = maxn;


    sort(cukr.begin(),cukr.end());
    vector<ll> type_counter(n,0);
    ll uni = 0;
    //debug
    // for(ll i = 0; i < n*m; i++)
    // {
    //     cout << cukr[i].first << " " << cukr[i].second << endl;
    // }

    ll left = 0;
    for(ll right = 0; right < cukr.size(); right++){
        if(type_counter[cukr[right].second] == 0){
            uni++;
        }
        type_counter[cukr[right].second]++;
        //cout << "unique types: " << uni << endl;; 
        while(uni ==n){
            ll cl = cukr[right].first - cukr[left].first + 1;
            min_l = min(min_l,cl);
            type_counter[cukr[left].second]--;

            if(type_counter[cukr[left].second] == 0)
            {
                uni--;
            }
            left++;

        }
        //cout << left << " " << right << endl;

    }
    cout << min_l << endl;





    return 0;


}