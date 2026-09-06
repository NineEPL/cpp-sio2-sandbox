#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> h(n);
    for (ll i = 0; i < n; i++) cin >> h[i];

    vector<pair<ll,ll> > ceny(n);

    for (ll i = 0; i < n; i++) {
        if (i == 0) {
            ceny[i].first = 0;
            ceny[i].second = max(0LL, h[i] - h[i+1]);
        } else if (i == n-1) {
            ceny[i].first = max(0LL, h[i] - h[i-1]);
            ceny[i].second = 0;
        } else {
            ceny[i].first = max(0LL, h[i] - h[i-1]);
            ceny[i].second = max(0LL, h[i] - h[i+1]);
        }
    }

    ll max_length = 1;


    ll left = 0, current_sum = 0;
    for (ll right = 0; right < n; right++) {
        if (right > 0) current_sum += max(0LL, h[right] - h[right-1]);
        while (current_sum > k) {
            current_sum -= max(0LL, h[left+1] - h[left]);
            left++;
        }
        max_length = max(max_length, right - left + 1);
    }

    ll right = n-1;
    current_sum = 0;
    for (ll left2 = n-1; left2 >= 0; left2--) {
        if (left2 < n-1) current_sum += max(0LL, h[left2] - h[left2+1]);
        while (current_sum > k) {
            current_sum -= max(0LL, h[right-1] - h[right]);
            right--;
        }
        max_length = max(max_length, right - left2 + 1);
    }

    cout << max_length << "\n";
    return 0;
}
