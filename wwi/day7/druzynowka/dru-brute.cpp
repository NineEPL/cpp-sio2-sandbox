// druzynowka-BRUTE
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for (int i = 0; i < m; i++)
    {
        int type, a, b, value;
        cin >> type >> a >> b >> value;
        if (type == 1)
        {
            for (int i = a; i <= b; i++)
            {
                arr[i] = max(arr[i], value);
            }
        }
        else
        {
            for (int i = a; i <= b; i++)
            {
                arr[i] = min(arr[i], value);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}