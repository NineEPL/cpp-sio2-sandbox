#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    int n;
    cin >> n;
    vector<pair <int,int> > nawi;
    bool found = false,c = false, ins = false;

    cin >> str;
    int i1 = 0, i2, er = 0, nin = 0;
    while(str.size()!=0){
        c = false;
        if(str[0] != '('){
            cout << "NIE"<<endl;
            c = true;
            break;
        }
        else{
            str.erase(0,1);
            i1 = er + 1;
            er++;
            found = false;
            nin = 0;
            for(int j = 0; j < str.size(); ++j){
                if(str[j] == ')' && !ins){
                    str.erase(j,1);
                    i2 = er + 1 + nin;
                    er++;
                    nawi.push_back(make_pair(i1,i2));
                    found = true;
                    break;
                }
                else if(str[j] == ')'){
                    nin++;
                    ins = false;
                }
                else{
                     ins = true;
                     nin++;
                }
                
            }
            
            if(found == false){
                cout << "NIE"<<endl;
                c = true;
                break;
            }
        }
    }
        
    if(c == false){
        cout << "TAK" << endl;
        for(int i = 0; i < nawi.size(); i++){
            cout << nawi[i].first << " " << nawi[i].second << endl;
        }
    }

    
    return 0;
}