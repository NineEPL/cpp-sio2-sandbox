#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n,plak = 0;
    cin >> n;
    vector< pair<int,int> > vec;
    int a,b;
    cin >> a >> b;
    // vec.push_back({a,b});
    vec.push_back(make_pair(a, b));
    for(int i = 1; i < n; ++i){
        cin >> a >> b;
        vec.push_back(make_pair(a+ vec[i-1].first, b ));

    }
    /*
    cout << endl;
    for(int i = 0; i < n; ++i){
        cout << vec[i].first << vec[i].second << endl;
    }*/

    pair<int,int> border = make_pair(vec[0].first,vec[0].second);
    if(border.second > vec[1].second){
        plak += 1;
    }
    for(int i = 0; i < n; ++i){
        int j = 1;
        while(vec[i].second <= vec[i+j].second){
            j+=1;
        }
        //cout << j <<endl;
        
        if( vec[i].second != border.second || max(border.first,vec[i+j-1].first) != border.first){
            plak += 1;
            border.second =  vec[i].second;
            border.first = max(border.first,vec[i+j-1].first);
        }
        cout <<endl<< border.first << " " << border.second<<endl;
        
        
    }
    cout << plak;
    
}