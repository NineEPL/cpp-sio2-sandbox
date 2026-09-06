#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long arr[1500000];
    vector<int> fst;
    for(unsigned long i = 0; i <1500000; ++i){
        arr[i] = 1;
    }
    unsigned long i = 2;
    while(fst.size() <= n ){
            //for(long long i = 2; i <= 1500000; ++i){
        if(arr[i]){
            fst.push_back(i);
            for(long long j = i *2; j < 1500000; j += i){
                arr[j] = 0;
            }
        }
        ++i;
    }
    for(unsigned long i = 0; i < n; ++i){
        cout << fst[i]<< " ";
    }

    return 0;
}