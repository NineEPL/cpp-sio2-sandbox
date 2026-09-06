#include<iostream>
#include<cmath>
using namespace std;
int main(){
    unsigned long long n;
    unsigned long long n1,n2;
    const long long c = 1000000007;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> n1 >> n2;
        cout << (unsigned long long)(pow(n1,n2))%c <<endl;
    }
}