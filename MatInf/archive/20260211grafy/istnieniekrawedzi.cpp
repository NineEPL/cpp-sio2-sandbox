#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

// istnieniekrawedzi

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<bool> > graph(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;
        if (graph[a][b]) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
    return 0;
}