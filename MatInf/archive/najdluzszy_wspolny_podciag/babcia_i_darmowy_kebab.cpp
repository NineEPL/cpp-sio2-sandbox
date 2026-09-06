#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int lcs(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();

    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // string lcs_str_reversed = "";
    // for(int i = m, j = n; i > 0 && j > 0;){
    //     if(s1[i-1] == s2[j-1]){
    //         lcs_str_reversed += s1[i-1];
    //         i--;
    //         j--;
    //     }
    //     else if(dp[i-1][j] > dp[i][j-1])
    //         i--;
    //     else
    //         j--;
    // }
    // reverse(lcs_str_reversed.begin(), lcs_str_reversed.end());
    cout << dp[m][n] << "\n";
    // //cout << lcs_str_reversed << "\n";
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    lcs(a, b);
    //cout << lcs(a, b) << "\n";


    //cout << "HELP!!!" << endl;
    return 0;
}