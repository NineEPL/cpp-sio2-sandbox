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
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        cout << a * b << "\n";
    }
}