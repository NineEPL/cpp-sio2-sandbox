#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr;
    int n,op;
    int c,l=0;
    int n1, n2;
    cin >> n >> op;
    for(int i = 0; i < n; ++i){
        cin >> c;
        arr.push_back(c);
    }


    
    for(int i = 0; i < n; ++i){
        arr[i] = arr[i] + l;
        l = arr[i];
    }
    for(int i = 0; i < op; ++i){
        cin >> n1 >>n2;
        cout << arr[n1] << " " << arr[n2];

    }

    return 0;
}