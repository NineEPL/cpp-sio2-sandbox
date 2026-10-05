#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, p, d;
    cin >> n >> p >> d;
    vector<ll> weight(n + 1, 0);
    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> weight[i];
        pref[i] = pref[i - 1] + weight[i];
    }
    vector<ll> koniec(n + 1, 0);
    for (ll i = d; i <= n; i++)
    {
        koniec[i] = pref[i] - pref[i - d];
    }

    // cout << "n = " << n << ", p = " << p << ", d = " << d << endl << endl;
    deque<ll> dq;
    ll maxl = 0;
    ll l = 1;
    for (ll r = 1; r <= n; r++)
    {
        //cout << r << " " << weight[r] << endl;
        if (r - l + 1 < d)
        {
            maxl = max(maxl, r - l + 1);
            // cout  << l << " " << r << " " << (r - l + 1)  << " " << d << endl;
            // cout << " " << maxl << endl;
        }
        else
        {
            // cout << r << " " << koniec[r] << endl;
            while (!dq.empty() && koniec[dq.back()] <= koniec[r])
            {
                // cout << dq.back()  << " " << koniec[dq.back()] << "  " << koniec[r] << " " << endl;
                dq.pop_back();
            }
            dq.push_back(r);

            while (l <= r - d + 1)
            {
                while (!dq.empty() && dq.front() < l + d - 1)
                {
                    //cout << dq.front() << "  " << (l + d - 1) << endl;
                    dq.pop_front();
                }
                ll max_cover = koniec[dq.front()];
                ll total = pref[r] - pref[l - 1];
                ll curr_cost = total - max_cover;

                if (curr_cost <= p)
                {
                    //cout << l << " " << r  << endl;
                    break;
                }
                //cout << (l + 1) << endl;
                l++;
            }
            maxl = max(maxl, r - l + 1);
            //cout << maxl << endl;
        }
    }
    cout << maxl << endl;
    // cout << "HELP!!" << endl;
    return 0;
}