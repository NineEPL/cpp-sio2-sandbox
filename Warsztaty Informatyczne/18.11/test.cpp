#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; 
    cin >> n;
    vector<int> vec(n,0);  //wyzerowany vector o 'n' elementach
    for(int i = 0; i < n; ++i){
        cin >> vec[i];
    }

    
}

/*
vector<int> v;
v.size();           rozmiar vectora
v.push_front();     dodaje pierwszy element
v.push_back();      dodaje ostatni element
v.pop_back();       kasyjemy ostatni element
auto it = v.begin()
erase



*/

/*
    long long ach = vec[0].first;
    long long limit = vec[vec.size()-1].first;
    long long sum = 0;
    while(ach>=limit){
        long long mi,i = 0;
        long long m = 0;
        while(vec[i].first >= ach){
            if(m < vec[i].second){
                m = vec[i].second;
                mi = i;
            }
            ++i;
            //m = max(m,vec[i].second);
        }
        
        sum+=m;
        //cout << m << " "<< ach << " " << sum<<endl;
        vec[mi].second = 0;
        ach -= 1;
    }
    cout << sum;*/