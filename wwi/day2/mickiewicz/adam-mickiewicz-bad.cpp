//adam-mickiewicz
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;
const ll MAXN = 1e6 + 5; //clang is a bitch and it doesn't like me using 1e6+5 as array size, so i made it a const
vector<pair<ll, ll> > adj[MAXN]; // that's gonna be a graph, i guess
ll depth[MAXN];                 // depth ._.
ll jumpu[MAXN][19];             // that's gonna be a jump table for lca
ll maxL[MAXN][19];              // tricki part about lengthts
// 19 steps

// okay now i need freaky dfs to fill up jumpu and maxL
void dfs(ll v, ll parent, ll edgetoparent)
{
    jumpu[v][0] = parent;       // first step
    maxL[v][0] = edgetoparent;  // first step pt2
    for (ll i = 1; i < 19; ++i) // for each step
    {
        jumpu[v][i] = jumpu[jumpu[v][i - 1]][i - 1];                    // jump to the next step, like fwog kwa
        maxL[v][i] = max(maxL[v][i - 1], maxL[jumpu[v][i - 1]][i - 1]); // max length to the next step
    }
    for (auto [u, w] : adj[v]) // for each edge
    {
        if (u != parent) // if it's not the parent
        {
            depth[u] = depth[v] + 1; // depth of u is depth of v + 1
            dfs(u, v, w);            // dfs to u
        }
    } // that should work right?
}

ll requesto(ll a, ll b) // here im gonna "try" handle all requestos
{
    if (a == b)
        return 0; // that was in the problem description, wasn't it?
    ll ans = 0;
    if (depth[a] < depth[b])     // if a is shallower than b
        swap(a, b);              // swap them
    for (ll i = 18; i >= 0; --i) // oki, here i want to make them be on the same lvl
    {
        if (depth[a] - (1 << i) >= depth[b]) // everyone does this binary shifting thing so i'm gonna too
        {
            ans = max(ans, maxL[a][i]); // max length to the next step
            a = jumpu[a][i];            // jump to the next step
        }
    }

    if (a == b)     // if they are the same now, then one was an ancestor of the other
        return ans; // which means - return the answer

    // okay now lifting part
    for (ll i = 18; i >= 0; --i) // now we're binary jumping them up until they meet at the lca
    {
        if (jumpu[a][i] != jumpu[b][i]) // if they are not the same
        {
            ans = max(ans, max(maxL[a][i], maxL[b][i])); // max length to the next step
            a = jumpu[a][i];                             // jump to the next step
            b = jumpu[b][i];                             // jump to the next step pt2
        }
    }

    ans = max(ans, max(maxL[a][0], maxL[b][0])); // max length to the next step
    return ans;                                  // return the answer
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    for (ll i = 0; i < n - 1; ++i) // reading the tree, nothing lleresting here
    {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w)); // my shitty clang only accepts make_pair lmao
    }

    depth[1] = 0; // depth of root is 0
    dfs(1, 1, 0); // start dfs from root

    // build lifting table
    for (ll i = 1; i < 19; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            jumpu[j][i] = jumpu[jumpu[j][i - 1]][i - 1];
            maxL[j][i] = max(maxL[j][i - 1], maxL[jumpu[j][i - 1]][i - 1]); // i hope i did'nt screw this up
        }
    }
    while (true)
    {
        ll a;
        cin >> a;

        if (a == -1) // checking out -1
            break;

        ll b;
        cin >> b;
        cout << requesto(a, b) << "\n";
    }
    // tbh i'm sick of writing this comments
    return 0;
}