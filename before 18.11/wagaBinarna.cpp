#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool sort_statement(pair< long long,long long>a,pair< long long,long long> b){
    if (a.first/pow(2,a.second) == b.first/pow(2,b.second)){
        return a < b;
    }
    else{
        return a.first/pow(2,a.second)<b.first/pow(2,b.second);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    pair<long long,long long> arr[n];
    for(unsigned long i = 0; i < n; ++i){
        cin >> arr[i].first >> arr[i].second;
        //arr[i].first /= pow(2,arr[i].second);
    }
    sort(arr,arr+n,sort_statement);
    for(unsigned long i = 0; i < n; ++i){
        cout << arr[i].first << " " << arr[i].second <<endl;
    }

}