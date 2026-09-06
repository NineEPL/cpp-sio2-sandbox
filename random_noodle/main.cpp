#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll sum1 = 0, sum2 = 0;
    string word1, word2;
    vector<pair<string, string> > words;
    
    for (ll i = 0; i < 5; i++)
    {
        string w1, w2;
        cin >> w1 >> w2;
        words.push_back(make_pair(w1, w2));
    }
    for (ll i = 0; i < 5; i++)
    {
        word1 = words[i].first;
        word2 = words[i].second;
        for (int j = 0; j < word1.length(); j++)
        {
            sum1 += int(word1[j]);
        }
        for (int j = 0; j < word2.length(); j++)
        {
            sum2 += int(word2[j]);
        }

        cout << abs(sum2 - sum1) << endl;
    }

    return 0;
}