// ZadankoZGrafow
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int type, c;
    cin >> type >> c;

    int s = 7734; // seed
    // hell ^ LMAO i'm so funny
    mt19937 gen;
    gen.seed(s);

    for (int i = 0; i < c; ++i)
    {
        if (type == 1) // doing first subproblem cause i suck
        {

            int n; // n
            cin >> n;
            cout << n << " " << n - 1 << "\n"; // cause of tree, edges = n-1
            for (int j = 1; j < n; ++j)        // for each edge
            {
                int a = j;         // new vertex
                int b = gen() % j; // random existing vertex
                // cout << a + 1 << " " << b + 1 << "\n";  // i'll do swap instead
                if (gen() % 2)                             // swap or not
                    cout << a + 1 << " " << b + 1 << "\n"; // edge
                else
                    cout << b + 1 << " " << a + 1 << "\n";
            }
            cout << "\n"; // YUPPIE !!!!! I GOT 10 POINTS .__.
        }
        // ----------------------------------------------------------
        else if (type == 2) // I DONT WAANNA DO IT !C
        {
            // ok, making routes UUGH
            int n;
            cin >> n;
            cout << n << " " << n - 1 << "\n"; // cause of route (or path) idk XDD
            int arr[n];                        // array of vertices
            for (int k = 0; k < n; ++k)        // screw this shit
            {
                arr[k] = k + 1; // fill it up with vertices
            }
            shuffle(arr, arr + n, gen); // shuffle it
            for (int j = 1; j < n; ++j) // for each edge
            {
                cout << arr[j - 1] << " " << arr[j] << "\n"; // edge
                // makes sense, i guess
            }
            cout << "\n"; // IM GETTING SICK OF THIS SHIT
        }
    }

    return 0;
}
    