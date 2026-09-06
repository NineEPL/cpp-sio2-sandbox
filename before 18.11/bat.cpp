#include <iostream>
using namespace std;
int main(){
    unsigned long n;
    cin >> n;
    long long arr[n];
    long long biggest, smallest;
    cin >> arr[0];
    for(unsigned long i = 1; i < n; ++i){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    /*
    for(int i = 0;i <n; ++i){
        cout << arr[i] << " ";
    }
    cout <<endl;*/
    smallest = 0;
    if(arr[0] < smallest){
            smallest = arr[0];
        }
    biggest = arr[0];
    for(unsigned long i = 1; i < n; ++i){
        if(arr[i]-smallest > biggest){
            biggest = arr[i]-smallest;
        }
        if(arr[i] < smallest){
            smallest = arr[i];
        }

        /*
        cout << "smallest: " << smallest<<endl;
        cout << "best_res: " << biggest<<endl;
        cout << "current: "<<arr[i]<<endl;
        */
        
    }
    cout << biggest;
    return 0;
}