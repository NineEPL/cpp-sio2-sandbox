//babelki.cpp
#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void update(int pos, vector<int>& tree){
    int i = pos + tree.size()/2;

    tree[i]++;   

    while(i > 1){
        i /= 2;
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

int query(int l, int r, vector<int>& tree){
    if(l > r) return 0;

    l += tree.size()/2;
    r += tree.size()/2;

    int sum = 0;

    while(l <= r){
        if(l % 2 == 1) sum += tree[l++];
        if(r % 2 == 0) sum += tree[r--];
        l /= 2;
        r /= 2;
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<ull> arr(n);

    for(int i=0;i<n;i++)
        cin >> arr[i];

    vector<ull> comp = arr;

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    vector<int> rank(n);

    for(int i=0;i<n;i++)
        rank[i] = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin();

    int m = comp.size();

    int base = 1;
    while(base < m) base *= 2;

    vector<int> tree(2 * base, 0);

    ll ans = 0;

    for(int i=0;i<n;i++){
        ans += query(rank[i] + 1, m - 1, tree);
        update(rank[i], tree);
    }

    cout << ans << "\n";
}