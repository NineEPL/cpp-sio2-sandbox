#include<iostream>
using namespace std;

long long nwd(long long a, long long b){
    while (b!=0)
    {
        long long c = b;
        b = a%b;
        a = c;
    }
    return a;
    
}

int main(){
    long long x,y;
    cin >> x >> y;
    cout <<((x*y)- (x + y - 1) + (nwd(x,y)-1)) /2;
}