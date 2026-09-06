// imagine-dragons
// brute
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
    vector<vector<ll> > plain;
    for(ll i = 0; i < n; i++)
    {
        plain.push_back(vector<ll>());
        for(ll j = 0; j < n; j++){
            ll x;
            cin >> x;
            plain[i].push_back(x);
        }
    }
    ll rect_counter = 0;
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)// going through all polls
        {
            if(plain[i][j] == 1){
                vector<ll> goodx;
                vector<ll> goody;
                for(ll x = i+1; x < n; x++ )
                {
                    if(plain[x][j] == 1){
                        goodx.push_back(x);
                    }
                }
                for(ll y = j + 1; y < n; y++){
                    if(plain[i][y] == 1){
                        goody.push_back(y);
                    }
                }
                for(ll x : goodx){
                    for(ll y : goody){
                        if(plain[x][y] == 1){
                            rect_counter ++;

                        }
                    }
                }
            }
        }

    }
    cout << rect_counter;

    //P.S. i might not have a brain but ihave an idea
}