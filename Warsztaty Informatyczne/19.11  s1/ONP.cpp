#include <iostream>
#include <vector>
using namespace std;

long long to_long (string str){
    long long n = 0, dec = 1;
    for(long long i = 0; i < str.size(); ++i){
        n+=((long long)(str[str.size()-1-i])-48) * dec;
        dec *= 10;
    }
    return n;

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin >> n;
    long long res = 0;
    vector<long long> vec; 
    ////cout << to_long long("21234") + 1;
    for(long long i = 0; i <n; ++i){
        string temp;
        cin >> temp;
        if(temp == "+"){
           long long c = vec[vec.size()-1] + vec[vec.size()-2];

           //cout << vec[vec.size()-1] << " + " << vec[vec.size()-2] << " = " << c << endl;
           vec.pop_back(); vec.pop_back();vec.push_back(c);
        }
        else if(temp == "-"){
           long long c = vec[vec.size()-2] - vec[vec.size()-1];

           //cout << vec[vec.size()-2] << " - " << vec[vec.size()-1] << " = " << c << endl;

           vec.pop_back(); vec.pop_back();vec.push_back(c);
        }
        else if(temp == "*"){
           long long c = vec[vec.size()-2] * vec[vec.size()-1];

           //cout << vec[vec.size()-2] << " * " << vec[vec.size()-1] << " = " << c << endl;

           vec.pop_back(); vec.pop_back();vec.push_back(c);
        }
        else if(temp == "/"){
           long long c = vec[vec.size()-2] / vec[vec.size()-1];

           //cout << vec[vec.size()-2] << " / " << vec[vec.size()-1] << " = " << c << endl;

           vec.pop_back(); vec.pop_back();vec.push_back(c);
        }
        else{
            vec.push_back(to_long(temp));

            //cout << vec.back() << endl;
        }
    }
    cout << vec.back();
}