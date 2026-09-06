//Erik Lebiadzinski LAT
#include<iostream>
using namespace std;

int main()
{
    //int n, y;
    long long n,y, z;
    cin >> n>>y>>z;
    int c;
    int lat = 0;
    for(int i =0; i < n;++i){
        cin >> c;
        if(c>44){
            lat++;
        }
    }
    cout<<lat<<"\n";
    if(lat*y <= z){
        cout << "PRAWDA\n";
    }
    else{
        cout<<"FAŁSZ\n";
    }
}