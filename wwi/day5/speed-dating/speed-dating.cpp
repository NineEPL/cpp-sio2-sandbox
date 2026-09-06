// speed-dating
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cmath>
using namespace std;
using ll = long long;



void updateBIT(vector<int>& BITree, int n, int index, int val) { //geeks for geeks !! UGH!!
    index = index + 1; // Convert 0-indexed to 1-indexed

    while (index <= n) {
        BITree[index] += val;
        index += index & (-index); // Move to next ancestor
    }
}

/**
 * Returns the prefix sum of the original array from index 0 to 'index'.
 */
int getSum(vector<int>& BITree, int index) {
    int sum = 0;
    index = index + 1; // Convert 0-indexed to 1-indexed

    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index); // Move to parent node
    }
    return sum;
}

//useless here :> 

// /** 
//  * Initializes the BIT and populates it using the input array.
//  */
// int* constructBITree(vector<int>& arr, int n) {
//     int* BITree = new int[n + 1]{0}; 

//     for (int i = 0; i < n; i++) {
//         updateBIT(BITree, n, i, arr[i]);
//     }

//     return BITree;
// }

int range_sum(vector<int>& treewo, int l, int r)
{
    if (l>r) return 0;
    return getSum(treewo, r)  - getSum(treewo,l - 1); // sybau
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> first(n+1,-1); // forgot i went with 0 based indexes
    vector<int> treewo (2*n+1,0);
    ll ans = 0; // zettai redo
    for(int i = 0; i < 2*n; i++)
    {
        int v;
        cin >> v;
        //cout << "v: "<< v << endl;
        if(first[v] == -1){
            first[v] = i;
            updateBIT(treewo, 2*n, i, 1);
        }
        else{
            ans += range_sum(treewo, first[v] + 1, i -1);
            updateBIT(treewo, 2*n, first[v], -1);
        }
        //debug
        // cout << "first after " << i <<": ";
        // for(int j = 0; j < n; j++)
        // {
        //     cout << first[j] << " ";
        // }
        // cout << endl;

    }

    cout << ans << "\n";
    return 0;



}