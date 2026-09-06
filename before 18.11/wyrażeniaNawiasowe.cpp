#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    while(s.size() != 0){
        if(s[0]!='('){
            cout << "FALSE";
            break;
        }
        else{
            int i = 1;
            while(i<s.size()){
                if(s[i] == ')'){
                    s.erase(i);
                    s.erase(0);
                }
                break;
            }
        }
    }
    if(s.size() == 0){
        cout << "PRAWDA";
    }
}