#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    long long arr[n];
    long long suma = 0;
    for(long long i = 0; i < n; ++i){
        cin >>arr[i];
    }
    suma += arr[n-1];
    for(long long i = n-2; i >= 0; --i){
        if(arr[i] > arr[i+1]){
            arr[i] = arr[i+1];
        }
        suma += arr[i];
    }
    /*
    for(long long i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;*/
    cout << suma;
}