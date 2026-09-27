#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
#include <map>
using namespace std;
// using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> one_pos(n+1, -1);
    vector<int> two_pos(n+1, -1);
    vector<int> three_pos(n+1, -1);

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        one_pos[t] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        two_pos[t] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        three_pos[t] = i;
    }//should've orginised it a bit better, but i'm lazy
    vector<pair<int,int> > trick;

    for(int i = 1; i <= n;i++){
        trick.push_back(make_pair((one_pos[i] - two_pos[i] + n) % n, (one_pos[i] - three_pos[i] + n) % n));
        //cout << trick[i].first << " " << trick[i].second << endl;
    }

    //cout << "reached new section" << endl;
    //vector<vector<int> >pair_counter(n+1, vector<int>(n+1, 0));
    map<pair<int,int>, int> pair_counter;
    int maxv =0;
    //cout << "reached loop" << endl;
    for(int i =0; i< n; i++){
        if(pair_counter.find(make_pair(trick[i].first,trick[i].second)) == pair_counter.end()){
            pair_counter[make_pair(trick[i].first,trick[i].second)] = 0;
        }
        pair_counter[make_pair(trick[i].first,trick[i].second)]++;
        maxv = max(maxv,pair_counter[make_pair(trick[i].first,trick[i].second)]);
        //cout << "something happened inside the loop" << endl;
    }
    //cout << "escaped the loop" << endl;
    cout << maxv << endl;



    // cout << "HELP!!" << endl;
    return 0;
}