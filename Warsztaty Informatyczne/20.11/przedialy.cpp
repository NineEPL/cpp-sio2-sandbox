#include<iostream>
#include<set>
using namespace std;

bool norm(pair<int,int> p1, pair<int,int> p2){
    return p1.second+1 >= p2.first;
}

int main(){
    int przed = 1;
    int n;
    cin >> n;
    set<pair<int,int> > st;
    for(int i = 0; i < n; ++i){
        int a,b;
        cin >> a >>b;
        st.insert(make_pair(a,b));
    }
/*
    for(auto it : st){
        cout << it.first << "/" << it.second << endl;
    }
    cout << endl;*/

    pair<int,int> lpr = *st.begin();
    //cout << lpr.first <<" "<< lpr.second << endl;
    //przed = 1;
    for(auto it : st ){
        //cout << lpr.first << " " << lpr.second <<" / " << it.first<<" " << it.second << " = " << norm(lpr,it) << endl;
        if(norm(lpr,it) == false){
            przed += 1;
            
            //cout << przed <<" ";
        }
        if(lpr.second <= it.second)     lpr = it;
    }
    cout << przed;
    return 0;
}

/*
4
-9 -7 
-8 -6
-3 -2
9 9


4
-2 2
6 6
0 3
5 5

*/