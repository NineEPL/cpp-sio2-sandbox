#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    cin >> arr[0];
    for(int i = 1; i<n; ++i){ // sumy prefekcyjne
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    int b = arr[0];
    for(int i = 1; i < n; ++i){ // ktora jest największa
        if(arr[i]> b){
            b = arr[i];
        }
    }
    for(int i = n ; i >=0 ; --i){ // wypisuje dzień
        if(arr[i] == b){
            cout<<i+1;
            break;
        }
    }
    return 0;
}