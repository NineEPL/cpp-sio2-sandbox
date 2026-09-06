#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string expression;
    cin >> expression;
    //cout <<"expression: "<< expression << endl;
    for(int i = 0; i < expression.size(); ++i){
        if(expression[i] == ' '){
            expression.erase(i, 1);
            --i;
        }
    }
    //cout <<"expression after deleting spaces: "<< expression << endl;
    stack<int> numbers;
    stack<char> operators;
    int number = 0;
    bool readingNumber = false;
    for(int i = 0; i < expression.size();++i){
        if(expression[i] >= '0' && expression[i] <= '9'){
            cout << "expression[i] is a number: " << expression[i] << " " << number*10 +(expression[i] - '0')<< endl;
            number = number*10 + (expression[i] - '0');
            readingNumber = true;
        }
        else{
            cout << "expression[i] is a operator: " << expression[i] << endl;
            if(readingNumber){
                numbers.push(number);
                number = 0;
                readingNumber = false;
            }
            operators.push(expression[i]);

        }
    }
    if(readingNumber){
        numbers.push(number);
    }
    // //debug
    // cout << "numbers: ";
    // for(int i = 0; i < numbers.size();){
    //     cout << numbers.top() << " ";
    //     numbers.pop();
    // }
    // cout << endl << "operators: ";
    // for(int i = 0; i < operators.size();){
    //     cout << operators.top() << " ";
    //     operators.pop();
    // }

    return 0;
}