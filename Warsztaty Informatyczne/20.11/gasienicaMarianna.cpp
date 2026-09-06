#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n , x, s = 0, best_score = n;
    cin >> n >> x;
    bool b = false;
    best_score = n;
    vector<int> vec;
    for(int i = 0; i < n;++i){
        int c;
        cin >> c;
        if(c == 0 && b ==false){

        }
        else {
            vec.push_back(c);
            b = true;
            //cout << c;
        }
    }

    


    
    
    int beg =0,end = 0;
    for(int i = 0; i < vec.size();++i){
        //cout << beg << " " << end << "   ";
        if(vec[i] == 1){
            s += 1;
        }
        if(s == x){
            best_score = min(best_score, end-beg-x+1);
            int skr = 0;
            while(skr < 2){
                if(vec[beg] == 1){
                    skr += 1;
                }
                beg += 1;
                
            }
            s-=1;
            beg -= 1;
        }
        end += 1;
        //cout << best_score << endl;

    }
    if(best_score == n){
        cout << "NIE";
    }
    else{
        cout << best_score;
    }


}

/*

9 3             
1 0 1 0 1 1 0 0 1

10 3
0 0 0 1 0 0 0 1 1 0

*/