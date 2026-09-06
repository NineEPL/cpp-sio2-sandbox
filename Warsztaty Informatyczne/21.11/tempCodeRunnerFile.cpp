#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool comp(pair<long long,long long> p1, pair<long long,long long> p2){
    return p1 > p2;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long m,n;
    cin >> m >> n;
    vector<pair<long long,long long> > vec;
    for(long long i = 0; i <n; ++i){
        long long temp1, temp2;
        cin >> temp1 >> temp2;
        vec.push_back(make_pair(temp2,temp1));
    }
    sort(vec.begin(),vec.end());

    priority_queue<long long> Q;
    long long sum = 0;
    //long long limit = vec[0].first;
    //cout <<endl <<limit <<endl;
    long long j = 0;

    for(long long i = 1; i <= m; ++i){
        while(vec[j].first<=i  &&  j< vec.size()-1){
            //cout << endl << vec[j].first << " " << vec[j].second<<endl;
            Q.push(vec[j].second);
            j++;
        }

        if(!Q.empty()){
            
            sum += Q.top();
            //cout << endl<<Q.top() << " " << sum<<endl;
            Q.pop();
        }

    }
    cout << sum;
    


    return 0;


}
/*

5
3 2
1 3
2 1
2 4
1 1

*/