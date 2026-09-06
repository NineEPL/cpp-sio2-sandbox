// adam-mickiewicz
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;

const int maxn = (1 << 19);
const int minus_duzo = -2000000000;
int dist[maxn];
int jumpu[maxn][19];
int maxv[maxn][19]; // i don't wanna do it
vector<pair<int, int> > treewo[maxn];

void dfs(int v, int parent, int edge) // i guess i still need edge variable
{
    //generating maxv and jumpu
    dist[v] = dist[parent] + 1;
    jumpu[v][0] = parent;
    maxv[v][0] = edge;
    for (int i = 1; i < 19; i++)
    {
        jumpu[v][i] = jumpu[jumpu[v][i - 1]][i - 1];
        maxv[v][i] = max(maxv[v][i - 1], maxv[jumpu[v][i - 1]][i - 1]);
    }
    for (auto cedge : treewo[v])
    {
        int s = cedge.first;
        int weight = cedge.second;
        if (s != parent)
        {
            dfs(s, v, weight);
        }
    }
}

int lca(int a, int b)
{
    //actually it's more of a req handler than just lca
    if (a == b)
        return 0;
    int ans = minus_duzo;
    if (dist[a] < dist[b])
    {
        swap(a, b);
    }

    // making sure theyre on the same lvl
    for (int i = 18; i >= 0; i--)
    {
        if (dist[jumpu[a][i]] >= dist[b])
        {
            ans = max(ans, maxv[a][i]);
            a = jumpu[a][i];
        }
    }
//common ancestor case
    if (a == b)
    {
        return ans;
    }
    //getting those two up
    for (int i = 18; i >= 0; i--)
    {
        if (jumpu[a][i] != jumpu[b][i])
        {
            ans = max(ans, max(maxv[a][i], maxv[b][i]));
            a = jumpu[a][i];
            b = jumpu[b][i];
        }
    }

    //return jumpu[a][0];
    ans = max(ans, max(maxv[a][0], maxv[b][0]));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    //reading treewo
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        treewo[a].push_back(make_pair(b, w));
        treewo[b].push_back(make_pair(a, w));
    }
    // // debug
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "i " << i << ": ";

    //     for (int j = 0; j < treewo[i].size(); j++)
    //     {
    //         cout << "(" << treewo[i][j].first << ", " << treewo[i][j].second << ") ";
    //     }
    //     cout << endl;
    // }
    dfs(1, 1, minus_duzo);

    int a ,b;
    while(true)
    {
        cin >> a;
        if(a == -1)
        {
            break;
        }
        cin >> b;
        cout << lca(a,b) << "\n";
    }

    return 0;
}