#include<iostream>
//#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    long long n = s.size();
    long long arr[n+1];
    long long sum = 0;
    long long b;
    long long m;

    // -----------------Prefiksy ---------------
    if(int(s[0]) >=65 && int(s[0]) <= 90){
        arr[0] = 1;
    }
    else{
        arr[0] = -1;
    }
    for(long long i = 1;i < n; ++i){
        if(int(s[i]) >=int('A') && int(s[i]) <= int('Z')){
            arr[i] = 1 + arr[i-1] ;
        }
        else{
            arr[i] = -1 + arr[i-1] ;
        }
    }
    arr[n] = 0;
    /*
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;*/
    b = arr[0];
    m = arr[0];
    for(long long i = 1; i <= n;++i){
        b = max(b,arr[i]);
    }
    for(long long i = 1; i <= n;++i){
        m = min(m,arr[i]);
    }

// -----------------Tablica przechowująca ilość poszczegulnych liczb w prefiksach
    long long arr1[b-m + 1];


    for(long long i = 0; i < b-m+1; ++i){
        arr1[i] = 0;
    }
    /*
    for(int i = 0; i < n+1; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;*/
    //something bad here
    for(long long i = 0; i < n+1;++i){
        arr1[arr[i]+m*-1] += 1;
    }
    //cout << arr1[0] << " " << arr1[1] << " " << arr1[2] << "\n";
    //arr1[1] += 1; // ---------------Zero na początku
    for(long long i = 0; i <b-m+1; ++i){
        arr1[i] =(arr1[i]*(arr1[i]-1))/2;
    }
    for(long long i = 0; i < b-m+1; ++i){
        sum += arr1[i];
    }

    cout <<sum;
    return 0;
}