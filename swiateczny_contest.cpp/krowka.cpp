#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n;
    vector<long long> sm;
    cin >> n;
    for(long long i = 0; i < n; ++i){
        long long a;
        cin >> a;
        sm.push_back(a);
    }
    if(n == 1){
        cout << sm[0];
        return 0;
    }
    else if(n==2){
        cout << sm[0]+sm[1];
        return 0;
    }
    else if(n==3){
        cout << max(sm[0]+sm[2],max(sm[0]+sm[1],sm[1]+sm[2]));
        return 0;
    }

    long long p3,p2,p1;
    p3 = 0;
    p2 = sm[0];
    p1 = sm[0]+sm[1];
    for(long long i = 2; i < n; ++i){
        //cout << sm[i]<<endl;
        //cout << p1 << " " << p2+sm[i] <<" " << p3 + sm[i]+sm[i-1] << endl;
        long long c = max(p1,max(p2+sm[i],p3 + sm[i]+sm[i-1]));
        p3 = p2;
        p2 = p1;
        p1 = c;
        //cout << p3 << " " << p2 << " " << p1 << endl;
    }
    cout << p1;

    return 0;
}