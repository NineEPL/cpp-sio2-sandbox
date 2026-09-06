// imagine-dragons
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;

// bool compareSecond(const pair<ll, ll> &a, const pair<ll, ll> &b)
// {
//     return a.second < b.second;
// }

// ll binarySearchSec(vector<pair<ll, ll> > &arr, ll x)
// { // geeksforgeeks tiny bit modified
//     ll low = 0;
//     ll high = arr.size() - 1;
//     while (low <= high)
//     {
//         ll mid = low + (high - low) / 2;

//         // Check if x is present at mid
//         if (arr[mid].second == x)
//             return mid;

//         // If x greater, ignore left half
//         if (arr[mid].second < x)
//             low = mid + 1;

//         // If x is smaller, ignore right half
//         else
//             high = mid - 1;
//     }

//     // If we reach here, then element was not present
//     return -1;
// }

// ll binarySearchFst(vector<pair<ll, ll> > &arr, ll x)
// {
//     ll low = 0;
//     ll high = arr.size() - 1;
//     while (low <= high)
//     {
//         ll mid = low + (high - low) / 2;

//         // Check if x is present at mid
//         if (arr[mid].first == x)
//             return mid;

//         // If x greater, ignore left half
//         if (arr[mid].first < x)
//             low = mid + 1;

//         // If x is smaller, ignore right half
//         else
//             high = mid - 1;
//     }

//     // If we reach here, then element was not present
//     return -1;
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    //vector<vector<ll> > plain;
    //vector<pair<ll, ll> > ones;
    vector<vector<ll> > plainOne;
    for (ll i = 0; i < n; i++)
    {
        //plain.push_back(vector<ll>());
        plainOne.push_back(vector<ll>());
        for (ll j = 0; j < n; j++)
        {
            ll x;
            cin >> x;
            if (x == 1)
            {
                //ones.push_back(make_pair(i, j));
                plainOne[i].push_back(j);
            }
           // plain[i].push_back(x);
        }
    }
    // vector<pair<ll,ll> > twos = ones;
    // sort(twos.begin(), twos.end(), compareSecond);
    
    // maybe chaecking out pairs in a row
    vector<vector<ll>> pairs(n, vector<ll>(n, 0));
    ll rect_counter = 0;
    for (ll i = 0; i < n; i++)
    {

        for (ll j = 0; j < plainOne[i].size(); j++)
        {
            for (ll k = j + 1; k < plainOne[i].size(); k++)
            {
                rect_counter += pairs[plainOne[i][j]][plainOne[i][k]];
                pairs[plainOne[i][j]][plainOne[i][k]]++;
            }
        }
    }
    // debug
    //  for(ll i = 0; i < twos.size(); i++){
    //      cout << twos[i].first << ":" << twos[i].second << "  ";
    //  }

    cout << rect_counter << "\n";
    return 0;

    // P.S. i don't have a brain
}
