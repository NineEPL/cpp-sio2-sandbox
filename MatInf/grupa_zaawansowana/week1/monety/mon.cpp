#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;
//int duzo = 1000000 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> pref;        // sumy prefiksowe
    //vector<int> mapa(-1, n); // chyba haszowanie albo cos
    vector<int> arr;         // poprostu zeby to wszystko wczytać

    string ciag;
    cin >> ciag;
    if (ciag[0] == 'R')
    {
        arr.push_back(0);
        pref.push_back(k * -1);
    }
    else
    {
        arr.push_back(1);
        pref.push_back(1);
    }
    for (int i = 1; i < n; i++)
    {
        if (ciag[i] == 'R')
        {
            arr.push_back(0);
            pref.push_back(pref[i-1]-k);
        }
        else
        {
            arr.push_back(1);
            pref.push_back(pref[i-1]+1);
        }
    }

    cout << "HELP!!" << endl;
    return 0;
}