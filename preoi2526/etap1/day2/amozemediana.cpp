// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// using ll = long long;

// bool condition(ll guessIdx, vector<vector<ll> > &matrix, vector<ll> &values, ll n) {
//     ll guessVal = values[guessIdx];

//     // dp[i][j] = max number of >=guessVal elements along a path to (i, j)
//     vector<vector<ll> > dp(n, vector<ll>(n, 0));

//     dp[0][0] = (matrix[0][0] >= guessVal);

//     // first row
//     for (ll j = 1; j < n; j++) {
//         dp[0][j] = dp[0][j - 1] + (matrix[0][j] >= guessVal);
//     }

//     // first column
//     for (ll i = 1; i < n; i++) {
//         dp[i][0] = dp[i - 1][0] + (matrix[i][0] >= guessVal);
//     }

//     // rest
//     for (ll i = 1; i < n; i++) {
//         for (ll j = 1; j < n; j++) {
//             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (matrix[i][j] >= guessVal);
//         }
//     }

//     return dp[n - 1][n - 1] >= n;
// }

// ll binsearch(vector<vector<ll> > &matrix, vector<ll> &values, ll n) {
//     ll left = 0;
//     ll right = values.size() - 1;

//     while (left < right) {
//         ll mid = (left + right) / 2;
//         if (condition(mid, matrix, values, n)) {
//             right = mid;
//         } else {
//             left = mid + 1;
//         }
//     }

//     return left;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll n;
//     cin >> n;
//     vector<vector<ll> > matrix(n, vector<ll>(n));
//     vector<ll> values(n * n);

//     for (ll i = 0; i < n; i++) {
//         for (ll j = 0; j < n; j++) {
//             cin >> matrix[i][j];
//             values[n * i + j] = matrix[i][j];
//         }
//     }

//     sort(values.begin(), values.end());
//     ll idx = binsearch(matrix, values, n);
//     cout << values[idx] << "\n";

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool condition(ll guessIdx, vector<vector<ll> > &matrix, vector<ll> &values, ll n) {
    ll guessVal = values[guessIdx];

    vector<vector<ll> > dp(n, vector<ll>(n, -1));
    dp[0][0] = (matrix[0][0] >= guessVal);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            ll best = -1;
            if (i > 0) best = max(best, dp[i - 1][j]);
            if (j > 0) best = max(best, dp[i][j - 1]);
            if (best >= 0) {
                dp[i][j] = best + (matrix[i][j] >= guessVal);
            }
        }
    }
    return dp[n - 1][n - 1] >= n; 
}

ll binsearch(vector<vector<ll> > &matrix, vector<ll> &values, ll n) {
    ll left = 0;
    ll right = values.size() - 1;

    while (left < right) {
        ll mid = (left + right + 1) / 2;
        if (condition(mid, matrix, values, n)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<vector<ll> > matrix(n, vector<ll>(n));
    vector<ll> values(n * n);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> matrix[i][j];
            values[n * i + j] = matrix[i][j];
        }
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    ll idx = binsearch(matrix, values, n);
    cout << values[idx] << "\n";

    return 0;
}
