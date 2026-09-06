#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std; 
using ll = long long; 

ll timer = 1; 


void dfs(ll node, const vector<vector<ll> >& adj, vector<bool>& visited, vector<ll>& tin, vector<ll>& tout) { 
    visited[node] = true; 
    tin[node] = timer++; 
    
    for (ll neighbor : adj[node]) { 
        if (!visited[neighbor]) { 
            dfs(neighbor, adj, visited, tin, tout); 
        } 
    } 
    
    tout[node] = timer++; 
} 

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    
    ll n,q; 
    cin >> n >> q;
    
    vector<vector<ll> > adj(n); 
    

    for (ll i = 0; i < n - 1; i++) { 
        ll u, v; 
        cin >> u >> v; 
        u--; v--; 
        
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    } 
    

    vector<bool> visited(n, false); 
    vector<ll> tin(n, 0); 
    vector<ll> tout(n, 0); 
    
    dfs(0, adj, visited, tin, tout); 
    
    for (ll i = 0; i < q; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        
        if (tin[u] <= tin[v] && tout[u] >= tout[v]) {
            cout << "TAK\n"; 
        } else {
            cout << "NIE\n"; 
        }
    }
    
    return 0; 
}