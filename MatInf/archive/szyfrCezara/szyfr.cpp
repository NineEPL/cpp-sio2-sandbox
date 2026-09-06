#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    char ref;
    string message;
    cin >> n >> ref >> message;
    map<char,int> m;
    pair<char,int> mv;
    mv.second = 0;

    for(int i = 0; i < message.size(); i++){
        if(m.find(message[i]) != m.end()){
            m[message[i]] = 0;
        }
        else{
            m[message[i]]++;
            if(mv.second < m[message[i]]){
                mv.second = m[message[i]];
                mv.first = message[i];
            }
        }
    }
    int przes = int(ref) - mv.first;
    //cout << "ref: " << ref<< " " << int(ref) << " mv: " << mv.first << endl;
    //cout << przes << endl;
    for(int i = 0; i < message.size(); i++){
        message[i] = 'A' + (message[i] - 'A' + przes) % 26;
        if(message[i] < 'A'){
            message[i] += 26;
        }
        else if(message[i] > 'Z'){
            message[i] -= 26;
        }
    }
    cout << message;
}