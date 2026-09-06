#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int space(string str){
    return count(str.begin(),str.end(),' ');
}

int numbe(string str){
    int num = 0;
    bool alr = false;
    for(int i = 0; i < str.size(); ++i){
        if(int(str[i]) >= int('0') && int(str[i]) <= int('9')){
            if(alr == false){
                num += 1;
                alr = true;
            }
        }
        else{
            alr = false;
        }
    }
    return num;
}
int words(string str){
    int word = 0;
    bool alr = false;
        for(int i = 0; i < str.size(); ++i){
        if(int(str[i]) >= int('a') && int(str[i]) <= int('z')){
            if(alr == false){
                word += 1;
                alr = true;
            }
        }
        else{
            alr = false;
        }
    }
    return word;
}

int sentences(string str){
    int sent = 0;
    bool cont = false;
    for(int i = 0; i < str.size(); ++i){
        if(int(str[i]) >= int('a') && int(str[i]) <= int('z'))  cont = true;
        if(str[i] == '.' && cont == true){
            sent += 1;
            cont = false;
        }
    }
    return sent;
}

int palindromes(string str){
    int pals = 0;
    bool notpal = false;
    string word;
    for(int i = 0; i < str.size(); ++i){
        if(int(str[i]) >= int('a') && int(str[i]) <= int('z')) word += str[i];
        else if(word.size() != 0){
            for(int j = 0; j <= word.size()/2; ++j){
                if(word[j] != word[word.size()-1-j]){
                    notpal = true;
                    break;
                }
            }
            if(notpal == false){
                pals += 1;
            }
            word = "";
            notpal = false;
        }
    }
    return pals;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int todo[n];
    string str;
    for(int i = 0; i <n; ++i)    cin >> todo[i];
    getline(cin,str);
    getline(cin,str);
    for(int i = 0; i < str.size(); ++i) str[i] = tolower(str[i]);
    for(int i = 0; i < n; ++i){
        if(todo[i] == 1){
            cout << space(str) << " ";
        }
        else if(todo[i] == 2){
            cout << numbe(str) << " ";
        }
        else if(todo[i] == 3){
            cout << words(str) << " ";
        }
        else if(todo[i] == 4){
            cout << sentences(str) << " ";
        }
        else if(todo[i] == 5){
            cout << palindromes(str) << " ";
        }
    }

}