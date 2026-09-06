#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n , best_score = 0;
    cin >> n ;
    vector<long long> vec;
    for(long long i = 0; i < n;++i){
        long long c;
        cin >> c;
        vec.push_back(c);
        //cout << c <<"_";
    }
    sort(vec.begin(),vec.end());
    


    
    
    long long beg = 0;
    //long long l = 2;
    //cout << beg << " " << end << "   " << best_score << endl;
    for(long long end = 1; end < vec.size();end++){
        if(vec[beg] + vec[beg+1] > vec[end]){
            best_score = max(best_score, end - beg + 1);
        }
        else{
            while(vec[beg] + vec[beg+1] <= vec[end]){
                beg++;
            }
        }  

    }
    cout << best_score;


}

/*
10
7
1
2
8
10
6
1
7
9
9



*/