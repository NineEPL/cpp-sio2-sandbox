#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    string nawiasy;
    vector <int> pref;
    vector <pair<int,int> > nawi;
    cin >> n;
    cin >> nawiasy;
    if(nawiasy[0] = ')'){
        cout << "NIE" << endl;
    }
    else{
        pref.push_back(1);
    }
    for(int i = 1; i < nawiasy.size(); ++i){
        if(nawiasy[i] = '('){
            pref.push_back(1+pref[pref.size()-1]);
        }
        else{
            pref.push_back(pref[pref.size()-1]-1);
        }
    }
    for(int i = 0; i < pref.size(); ++i){
        int v1 = pref[i];
        int i1 = i;
        int i2;
        for(int j = i; j < pref.size(); ++j){
            if(pref[j]+1 == v1){
                i2 = j;
            }
        }

    }

}