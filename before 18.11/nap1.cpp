//Eryk Lebiadzinski nap1
#include <iostream>
using namespace std;
int main(){
    int cycles;
    cin >> cycles;
    for(int j = 0; j < cycles;++j){
        int n,c;
        cin >> n;
        int zuzia[int(n/2)+(n%2)];
        int antek[int(n/2)];
        for(int i = 0; i < n;++i){
            if(i%2){
                cin>>zuzia[i/2];
            }
            else{
                cin>>antek[int(i/2)+1];
            }
        }
        for(int i = 0; i < (int(n/2)+(n%2)); ++i){
            cout << antek[i] << " ";
        }
        cout<<endl;
        for(int i = 0; i < (int(n/2)); ++i){
            cout << zuzia[i] << " ";
        }
    }
    return 0;
}