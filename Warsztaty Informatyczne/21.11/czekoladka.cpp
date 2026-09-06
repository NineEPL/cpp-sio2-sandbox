#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    priority_queue<int> X;
    priority_queue<int> Y;
    int m, n;
    cin >> m >> n;
    X.push(0);
    Y.push(0);
    for(int i = 0; i <m+n-2; ++i){
        int temp;
        cin >> temp;
        if(i < m-1){
            X.push(temp);
        }
        else{
            Y.push(temp);
        }
    }
    //cout << X.size() << " " << Y.size() << endl;




    int xk = 1, yk = 1;
    int sum = 0;
    
    for(int i = 0; i < m+n-2 ; ++i){
        int mx = max(X.top(),Y.top());
        //cout << m <<endl;
        if(X.top() == mx){
            sum += X.top() * yk;
            xk += 1;
            X.pop();
            //cout <<endl<< mx << " * " << yk << " = " << sum << endl;
        }
        else if(Y.top() == mx){
            sum += Y.top() * xk;
            yk += 1;
            Y.pop();
            //cout <<endl<< mx << " * " << xk << " = " << sum << endl;
        }
        //cout <<endl<< xk << " " << yk << endl;

    }
    cout << sum;
    return 0;
/*    

*/
}