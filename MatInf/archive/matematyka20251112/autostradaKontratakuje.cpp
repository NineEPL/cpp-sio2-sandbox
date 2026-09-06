#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;
    // cout << "a: " << a << " b: " << b << " c: " << c << "\n";
    vector<ll> counts(10e5 + 7, 0);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        counts[x]++;
    }
    ll min_count = n * c;
    ll ac, bc, cc;
    bc = n;
    min_count = bc * b;
    ac = 0;
    cc = 0;
    for (ll i = 1; i <= counts.size(); i++)
    {
        cc += ac;
        ac = counts[i];
        bc = n - ac - cc;
        // if(counts[i] != 0){
        // cout << "ac: " << ac << " bc: " << bc << " cc: " << cc << "\n";
        // cout << "count: " << ac * a + bc * b + cc * c <<" maxcount: " << min_count <<"\n";
        // }

        ll current = ac * a + bc * b + cc * c;
        if (current < min_count)
        {
            min_count = current;
        }
    }
    cout << min_count << "\n";

    return 0;
}