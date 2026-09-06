#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> permutacje;
    for (int i = 1; i <= n; i++){
        permutacje.push_back(i);
    }

    int ans = 0;

    do{
        int cas = 0;
        for(int i = 0; i < n; i++){
            if(abs(permutacje[i]-i-1) == 1){
                cas++;
            }
        }
        if(cas == k){
            ans++;
        }
    }while (next_permutation(permutacje.begin(),permutacje.end()));
    cout << ans;
    return 0;
}