#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pair <long long,long long> n;
    cin >> n.first >> n.second;
    long long sito[n.second+1];
    vector<long long> fst;
    vector<long long> czyn;
    long long rest;
    //sito -->
    for(long long i = 0; i <=n.second; ++i){
        sito[i] = 1;
    }
    for(long long i = 2; i <= n.second; ++i){
        if(sito[i]){
            fst.push_back(i);
            for(long long j = i *2; j <= n.second; j += i){
                sito[j] = 0;
            }
        }
    }// <-- sito
    for(long long i = n.first; i <= n.second; ++i){
            //for(unsigned long i = 0; i < n; ++i){
        if(i == 1){
            cout<<1<<endl;
        }
        else{
            rest = i;
            while(rest != 1){
                long long j = 0;
                while(rest % fst[j] != 0){
                    ++j;
                }
                rest /= fst[j];
                czyn.push_back(fst[j]);
            }
            cout << czyn[0];
            for(long long j = 1; j < czyn.size(); ++j){
                cout<<"*"<<czyn[j];
            }
            cout << "\n";
            czyn.erase(czyn.begin(),czyn.end());
        }
    
    }
    return 0;
}