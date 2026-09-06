#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 500000;
    int d = 0;
    int ul=n*2+1,dl = 0;
    string res;
    cout << n<<endl;
    cin >> res;
    while(res != "OK"){
        if(res == "WIEKSZA"){
            dl = n;
            n += (ul-dl)/2;
        }
        else{
            ul = n;
            n -= (ul-dl)/2+1;
        }
        d += 1;
        cout << n<<endl;
        cin >> res;
    }

    //cout << d;
    return 0;
}