#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const long long lim = 1e6+5;
    long long n;
    long long a, b;//bad = 0;
    cin >> n;
    long long arr[lim];
    long long num[lim];
    num[0] = 0;
    num[1] = 0;
    vector<long long> fst;
    for (unsigned long i = 0; i < lim; ++i) arr[i] = 1; // fills whole array with ones
    for (unsigned long i = 2; i < lim; ++i)
    {
        if (arr[i]) 
        {
            num[i] = num[i-1] + 1;
            // fst.push_back(i);
            for (long long j = i * 2; j < lim; j += i)
            {
                arr[j] = 0;
            }
        }
        else{
            num[i] = num[i -1];
        }
    }

    
    for (unsigned long i = 0; i < n; ++i)
    {
        cin >> a >> b;
        //bad = 0;

        cout << num[b] - num[a-1] << endl;
    }
    /*
    cout << endl;
    for(long long i = 0; i < fst.size(); ++i){
        cout << fst[i] << " ";
    }*/
}