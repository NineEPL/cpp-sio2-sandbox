#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int lcs(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    vector<int> v1(n + 1, 0);
    
    int res = 0;
    for (int i = 1; i <= m; i++) {
      
        vector<int> v2(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                v2[j] = v1[j - 1] + 1;
                res = max(res, v2[j]);
            } else {
                v2[j] = 0;
            }
        }
      
        v1 = v2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    //lcs(a, b);
    cout << lcs(a, b) << "\n"; 


    //cout << "HELP!!!" << endl;
    return 0;
}