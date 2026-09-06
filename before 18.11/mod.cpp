#include <iostream>
#include <vector>
using namespace std;
int main(){
    int arr[19];
    bool isin = false;
    vector<int> mod;
    for(int i = 0; i < 19; ++i){
        cin >> arr[i];
        isin = false;
        for(int j = 0; j < mod.size(); ++j){
            if(arr[i] == mod[j]){
                isin = true;
            }
        }
        if(!isin){
            mod.push_back(arr[i]);
        }
        
    }
    cout<<mod.size();
    return 0;
}