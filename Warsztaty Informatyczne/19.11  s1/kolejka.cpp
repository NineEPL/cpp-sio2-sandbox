#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> kol;
    int n , x;
    char d;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> d;
        if(d == '+'){
            cin >> x;
            kol.push(x);
        }
        else{
            cout << kol.front() << endl;
            kol.pop();
        }
    }
}