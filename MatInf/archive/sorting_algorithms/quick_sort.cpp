#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll partition(vector<ll> &a, ll low, ll high){
    ll pivot = a[low];
    ll leftwall = low;
    for (ll i = low + 1; i <= high; i++){
        if (a[i] < pivot){
            leftwall++;
            swap(a[i], a[leftwall]);
        }
    }

    swap(a[low], a[leftwall]);
    return leftwall;
}

vector<ll> quick_sort(vector<ll> &a, ll low, ll high){
    if(low < high){
        ll pivot_location = partition(a, low, high);
        quick_sort(a, low, pivot_location);
        quick_sort(a, pivot_location + 1, high);
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    a = quick_sort(a, 0, n - 1);
    for(ll i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}

//3 7 12 21 33 45 56 67 89 90
