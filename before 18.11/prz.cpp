#include<iostream>
using namespace std;
int arr[10006];
int arr1[10005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; ++i){
        cin >> arr1[i];
    }
    for(int i = 0; i < n-k; ++i){
        cin >> arr[i];
    }
    for(int i = 0; i < k; ++i){
        arr[i+n-k] = arr1[i];
    }
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }

    return 0;
}