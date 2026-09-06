#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<bool> odw;
void dfs(int v, vector<vector<int> > &graf, vector<int> &spojne, int kt)
{
    odw[v] = 1;
    spojne[v] = kt;
    for (auto x : graf[v])
    {
        if (!odw[x])
        {
            dfs(x, graf, spojne, kt);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > graf(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    vector<int> spojne(n, 0);
    int kt = 1;
    for (int i = 0; i < n; i++)
    {
        if (spojne[i] <= 0)
        {
            odw = vector<bool>(n, 0);
            dfs(i, graf, spojne, kt);

            kt++;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (spojne[a] == spojne[b])
        {
            cout << "T" << '\n';
        }
        else
        {
            cout << "N" << '\n';
        }
    }
    return 0;
}