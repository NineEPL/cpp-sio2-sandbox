#include <iostream>
#include <vector>
using namespace std;

long long nwd(long long a, long long b)
{
    while (b != 0)
    {
        long long c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, a, b, nv;
    const int alln_limit = 1e6;
    cin >> n;
    vector<long long> fst;
    // -------------------------------śito---------------------------
    long long alln[alln_limit+1]; // śito początek
    for (unsigned long i = 0; i <= alln_limit; ++i)
    {
        alln[i] = 1;
    }
    for (unsigned long i = 2; i <= alln_limit; ++i)
    {
        if (alln[i] == 1)
        {
            fst.push_back(i);
            for (unsigned long j = i * 2; j <= alln_limit; j += i)
            {
                alln[j] = 0;
            }
        }
    } // śito koniec

    //-------------------debug-------------------------------------
    /*
    for(int i = 0; i < fst.size(); ++i){
        cout << fst[i] << " ";
    }
    */

    // ------------------głowna pętla-----------------------------

    unsigned long j;
    for (unsigned long i = 0; i < n; ++i)
    {
        cin >> a >> b;
        nv = nwd(a, b);
        while (nv != 1)
        {
            j = 0;
            while (nv % fst[j] != 0)
            {
                ++j;
            }
            nv /= fst[j];
            a /= fst[j];
            if (b % (fst[j] * fst[j]) == 0)
            {
                b /= fst[j] * fst[j];
            }
            else
            {
                b /= fst[j];
            }
        }
        cout << a << " " << b << endl;
    }
}
