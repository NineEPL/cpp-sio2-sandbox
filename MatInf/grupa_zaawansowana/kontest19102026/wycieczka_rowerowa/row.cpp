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
    ll n, s;
    cin >> n >> s;
    ll curr_sum = 0;
    ll days = 0;
    ll max_days = 0;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll L = 0;

    for (ll R = 0; R < n; R++)
    {
        curr_sum += arr[R];
        days++;

        while (curr_sum > s)
        {
            curr_sum -= arr[L];
            L++;
            days--;
        }

        max_days = max(max_days, days);
    }
    cout << max_days << "\n";
    return 0;
}