#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
// ll duzo = 1000000 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> pref;      // sumy prefiksowe
    map<ll, int> leftest; // idk
    vector<bool> arr;       // poprostu zeby to wszystko wczytać
    leftest[0]=-1;
    string ciag;
    cin >> ciag;
    if (ciag[0] == 'R')
    {
        //arr.push_back(0);
        pref.push_back(k * -1);
        leftest[k * -1] = 0;
    }
    else
    {
        //arr.push_back(1);
        pref.push_back(1);
        leftest[1] = 0;
    }
    for (ll i = 1; i < n; i++)
    {
        if (ciag[i] == 'R')
        {
            //arr.push_back(0);
            pref.push_back(pref[i - 1] - k);
        }
        else
        {
            //arr.push_back(1);
            pref.push_back(pref[i - 1] + 1);
        }
        if (leftest.find(pref[i]) == leftest.end())
        {
            leftest[pref[i]] = i;
        }
    }
    ll maxr = 0;
    for(ll i = n-1; i >= 0; i-- ){
        maxr = max(i-leftest[pref[i]],maxr);
    }
    cout << maxr <<endl;

    //debug
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << pref[i] << " ";
    // }
    // cout << endl;
    // for (auto i : leftest)
    //     cout << i.first << " " << i.second << endl;

    // cout << "HELP!!" << endl;
    return 0;
}