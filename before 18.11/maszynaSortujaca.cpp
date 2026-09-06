#include <iostream>
#include <algorithm>
using namespace std;
bool por1(long long a, long long b)
{
    return a < b;
}
bool por2(long long a, long long b)
{
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, z, s, e;
    char w;
    cin >> n >> z;
    long long arr[n];

    for (long long i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    for (long long i = 0; i < z; ++i)
    {
        cin >> s >> e >> w;
        if (w == 'R')
        {
            sort(arr + s - 1, arr + e);
        }
        else
        {
            sort(arr + s - 1, arr + e, por2);
        }

        // debug -->
        /*
        for(long long i = 0; i < n; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;
        */
        // <-- debug
    }
    for (long long i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}