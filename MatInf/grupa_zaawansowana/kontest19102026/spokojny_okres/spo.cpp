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

    ll n, d;
    cin >> n >> d;
    if (d == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll maxo = 0;
    ll curr = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i; j < n; j++)
        {
            if (arr[j] - arr[i] <= d)
            {
                curr++;
            }
            else
            {
                break;
            }
        }
        maxo = max(maxo, curr);
        curr = 0;
    }
    cout << maxo << endl;
    return 0;
}
