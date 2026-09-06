#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin >> n;
    multiset<long long> beaten;
    //vector<pair<long long,long long>> way;
    for(long long i = 0; i < n;++i){
        long long a,b;
        cin >> a >> b;
        //way[i].first = a;
        //way[i].second = b;
        if(a == 1){
            beaten.insert(b);
        }
        else if(a==0 && i+1!=n){
            while(beaten.size() >= b){
                beaten.erase(beaten.begin());
            }
        }
        else{
            if(beaten.size() >= b){
                long long s = 0;
                for(auto it : beaten){
                    s += it;
                }
                cout << s;
            }
            else{
                cout << -1;
            }
        }
    }
}