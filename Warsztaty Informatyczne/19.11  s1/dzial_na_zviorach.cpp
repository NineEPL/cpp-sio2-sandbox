#include<iostream>
#include<set>
using namespace std;
int main(){
    set<long long> st;
    long long n , x;
    char c;
    cin >> n;
    for(long long i = 0; i < n; ++i){
        cin >> c;
        if(c == '+'){
            cin >> x;
            st.insert(x);
        }
        else if(c=='-'){
            cin >> x;
            st.erase(x);
        }
        else if(c=='f'){
            cin >> x;
            auto b = st.lower_bound(x);
            if(b == st.end()){
                cout << "BRAK" << endl;
            }
            else cout << *b << endl;
        }
        else if(c=='s'){
            cout << st.size() << endl;
        }
        else{
            for(auto it : st){
                cout << it << " ";
            }
            cout << endl;
        }

    }
    return 0;
}