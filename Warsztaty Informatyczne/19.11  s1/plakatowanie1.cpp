#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    stack<int> st;
    st.push(0);
    int res = 0;
    for(int i = 0; i < n; ++i){
        pair<int,int> temp;
        cin >> temp.first >> temp.second;
        if(temp.second > st.top()){
            st.push(temp.second);
        }
        else if(temp.second == st.top()){

        }
        else{
            while(st.top() > temp.second){
                res += 1;
                st.pop();
            }
            
            if(st.top() != temp.second){
                st.push(temp.second);
            }

        }
        
    }
    res += st.size()-1;
    cout << res;
}