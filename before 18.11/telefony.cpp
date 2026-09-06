#include<iostream>
#include<algorithm>
using namespace std;
bool stat(pair<long long,long long> a, pair<long long,long long> b){
    return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    pair <long long,long long> arr[n];
    for(long long i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].second = (int(arr[i].first/1000) * 1000) + ((arr[i].first - int(arr[i].first/10) *10) * 100) + (int((arr[i].first - int(arr[i].first / 100)*100) / 10) * 10) + (int((arr[i].first - int(arr[i].first / 1000)*1000) / 100) * 1);
        //cout << arr[i].second << " " << (int(arr[i].first/1000) * 1000) << " " << ((arr[i].first - int(arr[i].first/10) *10) * 100) << " " << (int((arr[i].first - int(arr[i].first / 100)*100) / 10) * 10) << " " << (int((arr[i].first - int(arr[i].first / 1000)*1000) / 100) * 1) << endl;
    }
    sort(arr, arr+n, stat);
    for(long long i = 0; i < n; ++i){
        cout << arr[i].first << " ";
    }
    
}