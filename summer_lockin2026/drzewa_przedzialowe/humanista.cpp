#include <iostream>
#include <vector>
using namespace std;

void build(vector<int> &tree, int base)
{
    for (int i = base - 1; i >= 1; i--)
        tree[i] = tree[2 * i] ^ tree[2 * i + 1];
}

void update(int pos, vector<int> &tree, vector<int> &a, int base)
{
    int v = base + pos;
    tree[v] = a[pos];

    while (v > 1)
    {
        v /= 2;
        tree[v] = tree[2 * v] ^ tree[2 * v + 1];
    }
}

int query(int l, int r, vector<int> &tree, int base)
{
    l += base;
    r += base;

    int ans = 0;

    while (l <= r)
    {
        if (l % 2 == 1)
            ans ^= tree[l++];

        if (r % 2 == 0)
            ans ^= tree[r--];

        l /= 2;
        r /= 2;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int base = 1;
    while (base < n)
        base *= 2;

    vector<int> a(n);
    vector<int> tree(2 * base, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tree[base + i] = a[i];
    }

    build(tree, base);

    while (q--)
    {
        string type;
        int l, r;
        cin >> type >> l >> r;

        if (type == "czytaj")
        {
            cout << query(l - 1, r - 1, tree, base) << '\n';
        }
        else 
        {
            swap(a[l - 1], a[r - 1]);

            update(l - 1, tree, a, base);
            update(r - 1, tree, a, base);
        }
    }

    return 0;
}