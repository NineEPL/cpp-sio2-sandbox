// zdjecia-dla-przedszkolaów
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;

vector<pair<int, int> > pairs;
vector<int> dist(1000005);
int n;
// mi się wydaje że to binsearch po wyniku XD

bool check(int d)
{
    vector<int> positions(n, -1);
    positions[0] = pairs[0].first;
    int cd = pairs[0].first; // current distance
    for (int i = 1; i < n; i++)
    {
        int min_d = d + cd;
        if (min_d < pairs[i].first)
        {
            positions[i] = pairs[i].first;
            cd = positions[i];
        }
        else if (min_d <= pairs[i].second)
        {
            positions[i] = min_d;
            cd = positions[i];
        }
        else
        {
            // cout << "somehow returned FALSE\n";
            return false;
        }
    }
    // debug =3
    //  cout << "positions: ";
    //  for(int i = 0; i < n; i++){
    //      cout << positions[i] << " ";
    //  }
    //  cout << endl;
    //  cout << "dist: ";
    //  for(int i = 0; i < n-1; i++){
    //      dist[i] = positions[i+1] - positions[i];
    //      cout << dist[i] << " ";
    //  }
    //  cout << endl;
    return true;
}

int binsearch()
{
    ll low = 1, high = 2e9 + 7;
    ll best_d = 1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (check(mid))
        {
            best_d = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return best_d;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int maxn = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pairs.push_back(make_pair(a, b));
        maxn = max(maxn, b);
    }

    int ans = binsearch();
    if (ans == -1) {
        cout << "NIE\n";
        return 0;
    }
    cout << ans << endl;
    vector<int> positions(n, -1);
    positions[0] = pairs[0].first;

    int cd = pairs[0].first; // current distance
    for (int i = 1; i < n; i++)
    {
        int min_d = ans + cd;
        if (min_d < pairs[i].first)
        {
            positions[i] = pairs[i].first;
            cd = positions[i];
        }
        else if (min_d <= pairs[i].second)
        {
            positions[i] = min_d;
            cd = positions[i];
        }
    }

     for(int i = 0; i < n; i++){
         cout << positions[i] << " ";
     }
     cout << endl;

    return 0;

    // cout << check(4);
}