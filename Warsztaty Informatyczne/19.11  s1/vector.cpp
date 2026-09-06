#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> kol;
    int n , x;
    char d;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> d;
        if(d == '+'){
            cin >> x;
            kol.push_back(x);
        }
        else if(d == '-'){
            //cout << kol.front() << endl;
            kol.pop_back();
        }
        else if(d == '='){
            cout << kol.size()<<endl;
        }
        else{
            cin >> x;
            cout<<kol[kol.size()-x]<<endl;
        }
    }
}