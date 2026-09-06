#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
using namespace std;
using ll = long long;
// osiagalnoscwierzcholkow

void dfs(map<ll, list<ll> > &graph, vector<bool> &visited, ll node)
{
    visited[node] = true;
    for (auto neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            dfs(graph, visited, neighbour);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    map<ll, list<ll> > graph;
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    dfs(graph, visited, 1);
    for (int j = 1; j <= n; j++)
    {
        if (visited[j])
        {
            cout << "TAK\n";
        }
        else
        {
            cout << "NIE\n";
        }
    }

    return 0;
}