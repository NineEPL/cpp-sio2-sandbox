#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> lang(n);
    int whole = 0;
    // oki, tu wczytujemy
    for (int i = 0; i < n; i++)
    {
        cin >> lang[i];
        whole += lang[i];
        //cout << lang[i] << " ";
    }
    // cout << endl << whole << endl;

    int maXD = 0; //max distance
    int curr_d = 0;
    int tail = 0; // gąsienicaaaaaaaaaaaaaaaaaaa
    //początek gąsienicy
    for (int i = 0; i < n; i++)
    {
        // presuwamy ogon póki dodanie kolejnego odcinka nie przekroczy połowy obwodu
        // bo dalej to nie ma sensu
        while ((curr_d + lang[tail]) <= whole / 2)
        {
            curr_d += lang[tail];// wydłużamy o odcinek
            tail++;//przesuwamy ogon
            tail %= n; // koło
        }
        maXD = max(maXD, curr_d);// dosyć oczywiste

        int next = whole - (curr_d + lang[tail]); // sprawdzamy sąsiada
        maXD = max(maXD, next);//same
        curr_d -= lang[i]; // odcamy pierwszy odcinekkkkkkkkkkkkkkkkkkk (klawiatura mi się popsuła T-T)
    }

    //cout << "HELP!!" << endl;
    cout << maXD << endl;
    return 0;
}