// najkrotszesciezki.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
const ll INF = 1000000000;
vector<vector<pair<ll, ll> > > adj;

void dijkstra(ll s, vector<ll> & d, vector<ll> & p) {
    ll n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push(make_pair(d[to], to));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    adj.resize(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    vector<ll> d, p;
    dijkstra(0, d, p);

    for (ll i = 0; i < n; i++)
    {
        if (d[i] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << d[i] << endl;
        }
    }

    return 0;
}