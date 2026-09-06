#include<iostream>
#include<cmath>
#include<map>
//#include<pair>
using namespace std;

//const long long MOD = 1000000009;

long long nwd(long long a, long long b){
    int buf;
    while(b != 0){
        buf = b;
        b = a % b;
        a = buf;
    }
    return a;
}

map <pair<long long,long long>,short> cash_map;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin >> n;
    for(long long i = 0; i < n; i++){
        long long a,b;
        cin >> a >> b;
        pair<long long,long long> key = make_pair(a,b);
        if(cash_map[key] != 0){
            cout << cash_map[key] << endl;
            continue;
        }
        long long nwd_ab = nwd(a,b);
        long long possible = 1; // tile 1*1

        if(nwd_ab != 1){ 
            possible += 1; // tile nwd_ab * nwd_ab
        }
        //long long sqrt_nwd_ab = sqrt(nwd_ab);
        for(long long j = 2; j * j <= nwd_ab; j++){ 
            //cout  << "debug: "<< j << " " << nwd_ab << " ";
            if(nwd_ab % j == 0){
                possible += (j * j == nwd_ab) ? 1 : 2;
                //if(j * j == nwd_ab) possible -= 1;
                
            }
        }
        //cout << "result: " << possible << endl;
        cash_map[key] = possible;
        cout << possible  << endl;

    }

}