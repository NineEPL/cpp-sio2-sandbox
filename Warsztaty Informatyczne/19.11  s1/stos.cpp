#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> stos;
    int n , x;
    char d;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> d;
        if(d == '+'){
            cin >> x;
            stos.push(x);
        }
        else{
            cout << stos.top() << endl;
            stos.pop();
        }
    }
}