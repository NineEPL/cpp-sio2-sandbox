#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(int a, int b){
    return a > b;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    for(int i = 0; i <n; ++i){
        int t;
        cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end(), comp);
    for(int i = 0; i < n; ++i){
        cout << vec[i] << " ";
    }
}