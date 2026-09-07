#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // hate windows, especially sliding ones

    ll n;
    cin >> n;
    vector<ll> peak(n,0);
    for(int i = 0; i < n; i++){
        cin >> peak[i];
        //cout << peak[i] << endl;
    }
    int maxn = 0;
    bool swit = false;
    int left = 0;
    int curr = 0;
    for(int right = 0; right < peak.size(); right++){
        
        int lastPeak = peak[right];
        if(lastPeak < peak[right-1]){
            swit = true;
        }
        if(swit == true && lastPeak > peak[right-1]){
            
            left = right-2;
            curr = 1;
            swit = false;


        }
        if(lastPeak == peak[right-1]){
            left = right-2;
            curr = 0;
            swit = false;
        }
        curr++;
        maxn = max(maxn,curr);
        //cout << "left: "<<left << "  right: " << right << "  last peak: " << lastPeak << "  second to last: " << peak[right-1] << "  maxn: " << maxn << "  curr: " << curr << "  switch: "<< swit << endl ;
        
    }
    cout << maxn;
    return 0;
}