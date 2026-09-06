#include<iostream>
using namespace std;
int main(){
    long long a,b;
    cin >> a >> b;
    if(a%2 == b%2) cout << long((long((b-a)/2)+1) /2)*2 + long((b-a)/4) *2;
    else cout << long((b-a+1)/4) *4;
}