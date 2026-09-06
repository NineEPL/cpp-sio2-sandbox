#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,b,rest,j;
    
    cin >> n;
    long long arr[n];
    vector<long long> fst;
    for(unsigned long i = 0;i < n;++i){
        cin >> arr[i];
    }
    b = arr[0];
    for(unsigned long i = 1; i < n;++i){
        b = max(b,arr[i]);
    }
    long long alln[b+1]; // śito początek
    for(unsigned long i = 0; i <=b;++i){
        alln[i] = 1;
    }
    for(unsigned long i = 2;i<=b;++i){
        if(alln[i] == 1){
            fst.push_back(i);
            for(unsigned long j = i*2; j <= b; j+= i){
                alln[j] = 0;
            }
        }
    }//śito koniec
    /*
    for(unsigned long i = 0; i < fst.size(); ++i){//śito debug
        cout << fst[i]<<" ";
    }
    cout << endl;*/

    for(unsigned long i = 0; i < n; ++i){
        if(arr[i] == 1){
            cout << endl;
        }
        else{
            rest = arr[i];
            while(rest != 1){
                j = 0;
                while(rest % fst[j] != 0){
                    ++j;
                }
                rest /= fst[j];
                cout << fst[j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}