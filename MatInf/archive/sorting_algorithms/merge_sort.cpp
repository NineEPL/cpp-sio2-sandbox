#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void merge(vector<ll> &arr, ll left, ll mid, ll right)
{

    ll n1 = mid - left + 1;
    ll n2 = right - mid;

    vector<ll> L(n1), R(n2);

    for (ll i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (ll j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    ll i = 0, j = 0;
    ll arri = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[arri] = L[i];
            i++;
        }
        else
        {
            arr[arri] = R[j];
            j++;
        }
        arri++;
    }

    while (i < n1)
    {
        arr[arri] = L[i];
        i++;
        arri++;
    }

    while (j < n2)
    {
        arr[arri] = R[j];
        j++;
        arri++;
    }
}

void merge_sort(vector<ll> &arr, ll left, ll right)
{

    if (left >= right)
        return;

    ll mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, 0, n - 1);
    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}