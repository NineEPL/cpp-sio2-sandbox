// spojneskladowe
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void dfs(ll v, vector<vector<ll> > &adj, vector<bool> &visited) {
    visited[v] = true;
    
    for (ll u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll> > adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 0; i < q; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        cout << (checkPath(adj, u, v) ? "T" : "N") << "\n";
    }
    return 0;
}

