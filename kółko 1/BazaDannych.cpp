#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int> pesel;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int key;
        int cn;
        cin >> key >> cn;
        if(pesel.find(key) == pesel.end()){
            pesel.insert( {key,cn} );
        }
        else{
            pesel[key] += cn;
        }
        if(pesel[key] < 0){
            cout << "NIE" << endl;
            pesel[key] -= cn;
        }
        else{
            cout << pesel[key] << endl;
        }
    }
}