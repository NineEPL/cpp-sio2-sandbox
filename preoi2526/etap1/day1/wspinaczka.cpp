// #include <iostream>
// #include <vector>
// using namespace std;
// using ll = long long;
// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     ll x, y;
//     cin >> x >> y;
//     vector<vector<ll> > vek(x+1, vector<ll>(y));
//     vector<vector<ll> > dp(x+1, vector<ll>(y, 0));
//     for(ll i = 1; i <= x; i++){
//         for(ll j = 0; j < y; j++){
//             cin >> vek[i][j];
//         }
//     }
//     for(ll i = 1; i <= x; i++){
//         for(ll j = 0; j < y; j++){
//             ll qw = vek[i][j];
//             if(j==0){
//                 dp[i][j] = qw + max(dp[i-1][j], max(dp[i-1][j+1], dp[i-1][y-1]));
//             }
//             else if(j==y-1){
//                 dp[i][j] = qw + max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][0]));
//             }
//             else{
//                 dp[i][j] = qw + max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]));
//             }
//         }
//     }
//     ll ans = 0;
//     for(ll j = 0; j < y; j++){
//         ans = max(ans, dp[x][j]);
//     }
//     cout << ans << endl;

// }

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll malo = -1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x, y;
    cin >> x >> y;

    vector<vector<ll> > vek(x+1, vector<ll>(y));
    vector<vector<ll> > dp(x+1, vector<ll>(y, 0));

    for(ll i = x; i >= 1; i--){
        for(ll j = 0; j < y; j++){
            cin >> vek[i][j];
        }
    }

    for(ll j = 0; j < y; j++){
        dp[1][j] = vek[1][j];
    }

    for(ll i = 2; i <= x; i++){
        for(ll j = 0; j < y; j++){
            ll qw = vek[i][j];
            ll left = (j - 1 + y) % y;
            ll right = (j + 1) % y;
            dp[i][j] = qw + max(dp[i-1][j], max(dp[i-1][left], dp[i-1][right] ));
        }
    }

    ll ans = malo;
    for(ll j = 0; j < y; j++){
        ans = max(ans, dp[x][j]);
    }

    cout << ans << "\n";

    return 0;
}
