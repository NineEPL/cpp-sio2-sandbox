#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, t;
    cin >> n >> t;
    vector<ll> forest(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> forest[i];
        // cout << forest[i] << " ";
    }
    // cout << endl;
    if (t == 0)
    {
        cout << forest[0];
        return 0;
    }
    if( n==1){
        cout <<forest[0] * (t/2) + forest[0];
        return 0;
    }

    ll max_m = 0;
    ll max_pair = 0;
    ll curr = forest[0];

    for (ll i = 1; i < n && i <= t; i++)
    {
        curr += forest[i];
        ll curr_pair = forest[i] + forest[i - 1];
        max_pair = max(max_pair, curr_pair);

        ll overandover = t - i;
        ll res = 0;
        if (overandover % 2 == 0)
        {
            res = curr + (overandover / 2) * max_pair;
            // cout << res << " " << overandover << " " << max_pair <<" " << t <<  endl;
        }
        else
        {
            res = curr + forest[i - 1] + (overandover - 1) / 2 * max_pair;
            // cout << res << " " << overandover << " " << max_pair << " " << forest[i-1] << " " << t <<endl;
        }
        max_m = max(max_m, res);
    }

    cout << max_m << endl;

    return 0;
}