#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;

// now i shall build the beast itself!!
// multiple source bfs!!

const ll N = 1000005;

ll dist[N];
bool visited[N];

void Multisource_BFS(const vector<vector<ll> > &graph, queue<ll> &q)// slightly modified version from geeksforgeeks
{
    while (!q.empty())
    {
        ll k = q.front();
        q.pop();

        for (ll neighbor : graph[k])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                dist[neighbor] = dist[k] + 1;
                q.push(neighbor);
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
    vector<vector<ll> > classroom(n, vector<ll>(m));// our field
    queue<ll> q; //troublemakers
    // vector<pair<ll, ll>> coordinates_of_players; // there i will store xy coordinates of lazy ass people
    for (ll i = 0; i < n; i++)
    { // reading input
        for (ll j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            classroom[i][j] = x;
            ll id = i * m + j;
            if (x == 2) // adding our troublemakers
            {
                q.push(id);
                visited[id] = true;
                dist[id] = 0;
            }
        }
    }
    // // another debug
    // for(ll i = 0; i < n; i++){
    //     for(ll j = 0; j < m; j++){
    //         cout << classroom[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<ll> > adj(n * m);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (classroom[i][j] == 0)
                continue;

            ll cid = i * m + j;

            //sąsiad po prawej ??
            if (j + 1 < m && classroom[i][j + 1] != 0)
            {
                ll neighbour = i * m + (j + 1);
                adj[cid].push_back(neighbour);
                adj[neighbour].push_back(cid);
            }

            // sąsiad zdołu ??
            if (i + 1 < n && classroom[i + 1][j] != 0)
            {
                ll neighbour = (i + 1) * m + j;
                adj[cid].push_back(neighbour);
                adj[neighbour].push_back(cid);
            }
            // nie sprawdzam lewą i górę bo dodaje dwa na raz
        }
    }
    // vector<ll> coordinates_of_players_flattened;
    // for (ll i = 0; i < coordinates_of_players.size(); i++) // here i'll flatten coordinates of minecrafters
    // {
    //     coordinates_of_players_flattened.push_back(coordinates_of_players[i].first * n + coordinates_of_players[i].second);
    // }

    // small debug
    // for (ll i = 0; i < adj.size(); i++)
    // {
    //     cout << i + 1 << ": ";
    //     for (ll j = 1; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << ", ";
    //     }
    //     cout << endl;
    // }

    Multisource_BFS(adj, q);

    ll max_minutes = 0; // self explanatory
    bool revolution = true; //edge case

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (classroom[i][j] == 1)
            {
                ll id = i * m + j;
                if (!visited[id])
                {
                    revolution = false; // rewolucja nie dotarła do tej osoby
                    break;
                }
                max_minutes = max(max_minutes, dist[id]);
            }
        }
        if (!revolution)
            break;
    } // nuda, nawet nie chce mi się pisać

    if (!revolution)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << max_minutes << "\n";
    }// odpowiedź Yupie

    return 0;
}
