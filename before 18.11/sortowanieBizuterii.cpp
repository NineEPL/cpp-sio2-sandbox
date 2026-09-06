#include<iostream>
#include<algorithm>
using namespace std;

bool sta(string a, string b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    else{
        return a < b;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    string arr[n];
    for(long long i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr,arr+n,sta);
    //cout << endl;
    for(long long i = 0; i < n; ++i){
        cout << arr[i] << endl;
    }
    return 0;
}