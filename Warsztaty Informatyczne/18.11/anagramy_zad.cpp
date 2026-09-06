#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s1,s2;
    cin >> s1 >> s2;

    //abcb
    //cabb

    vector<int> wyst(256,0);
    for(int i = 0; i < s1.size(); ++i){
        wyst[int(s1[i])]++;
    }
    for(int i = 0; i < s2.size(); ++i){
        wyst[int(s2[i])]--;
    }
}