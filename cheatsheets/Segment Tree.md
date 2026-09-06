# Segment Tree Explained Like You're 5 🎈

Imagine you have a row of toy boxes:

```
Box:   0  1  2  3  4  5  6  7
Toys:  3  2  4  5  1  6  2  7
```

And someone keeps asking:

> "How many toys are in boxes 2 to 6?"

You could count:

```
4 + 5 + 1 + 6 + 2 = 18
```

But what if there are **100,000 boxes** and **100,000 questions**?

Counting every time would be very slow.

Segment Tree is a clever way to remember sums of groups of boxes so we can answer quickly.

---

# The Big Idea

Instead of remembering only individual boxes:

```
3 2 4 5 1 6 2 7
```

we also remember:

```
[0..1] = 5
[2..3] = 9
[4..5] = 7
[6..7] = 9
```

and bigger groups:

```
[0..3] = 14
[4..7] = 16
```

and finally:

```
[0..7] = 30
```

So we build a TREE of ranges.

---

# What Does It Look Like?

Array:

```
3 2 4 5 1 6 2 7
```

Tree:

```
                    [0..7]=30
                   /         \
            [0..3]=14      [4..7]=16
             /     \         /     \
        [0..1]=5 [2..3]=9 [4..5]=7 [6..7]=9
          / \      / \      / \      / \
         3   2    4   5    1   6    2   7
```

Each parent stores information about its children.

Usually:

```
parent = left_child + right_child
```

for sum queries.

---

# Why Is It Fast?

Suppose we need:

```
sum(2,6)
```

Instead of:

```
4+5+1+6+2
```

we use stored values:

```
[2..3] = 9
[4..5] = 7
[6..6] = 2
```

Answer:

```
9 + 7 + 2 = 18
```

Only a few nodes!

---

# Complexity

Normal array:

| Operation      | Time |
| -------------- | ---- |
| Query sum(l,r) | O(N) |
| Update element | O(1) |

Segment Tree:

| Operation | Time     |
| --------- | -------- |
| Query     | O(log N) |
| Update    | O(log N) |
| Build     | O(N)     |

This is why Segment Trees appear everywhere in Olympiad problems.

---

# When Do We Use Segment Trees?

Whenever we have:

### 1. Many range queries

Example:

```
sum(10,100)
sum(500,900)
sum(2,1000)
```

---

### 2. Array changes

Example:

```
a[7] = 15
```

and afterwards queries continue.

---

### 3. Need fast answers

For:

```
N = 100000
Q = 100000
```

O(N) per query is too slow.

---

# What Can Segment Trees Store?

Not only sums.

They can store:

### Sum

```
1 2 3 4
=> 10
```

---

### Minimum

```
1 7 3 9
=> 1
```

---

### Maximum

```
1 7 3 9
=> 9
```

---

### GCD

```
12 18 24
=> 6
```

---

### Even custom information

Olympiad problems often store:

* max subarray sum
* number of zeros
* frequency counts
* etc.

---

# Implementation

We'll build the classic **sum segment tree**.

---

## Structure

We store tree in an array:

```cpp
vector<long long> tree(4*n);
```

Why `4*n`?

Because a segment tree never needs more than about 4N nodes.

Easy and safe.

---

# Build

This creates the tree.

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<long long> tree; // segment tree
vector<int> a;          // original array

//-----------------------------------------------------
// Build tree
//
// node = current tree node
// l,r = range represented by node
//-----------------------------------------------------
void build(int node, int l, int r)
{
    // Leaf node
    // Represents exactly one element
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    // Build left half
    build(node * 2, l, mid);

    // Build right half
    build(node * 2 + 1, mid + 1, r);

    // Parent stores sum of children
    tree[node] =
        tree[node * 2] +
        tree[node * 2 + 1];
}
```

---

# Query

Find:

```
sum(queryL, queryR)
```

---

There are 3 situations.

### 1. Completely outside

```
Node range:  [0..3]
Query range: [5..7]
```

No overlap.

Return:

```
0
```

---

### 2. Completely inside

```
Node range:  [4..5]
Query range: [2..7]
```

Already covered.

Use stored value.

---

### 3. Partial overlap

Need to go deeper.

---

Code:

```cpp
//-----------------------------------------------------
// Query sum on range [ql, qr]
//
// node = current tree node
// l,r = range represented by node
//-----------------------------------------------------
long long query(
    int node,
    int l,
    int r,
    int ql,
    int qr)
{
    // Completely outside
    if (r < ql || l > qr)
        return 0;

    // Completely inside
    if (ql <= l && r <= qr)
        return tree[node];

    // Partial overlap
    int mid = (l + r) / 2;

    long long leftSum =
        query(node * 2,
              l,
              mid,
              ql,
              qr);

    long long rightSum =
        query(node * 2 + 1,
              mid + 1,
              r,
              ql,
              qr);

    return leftSum + rightSum;
}
```

---

# Update

Suppose:

```
a[3] = 20
```

Old array:

```
3 2 4 5 1 6 2 7
```

New array:

```
3 2 4 20 1 6 2 7
```

We update:

1. the leaf
2. all parents above it

Only O(log N) nodes.

---

Code:

```cpp
//-----------------------------------------------------
// Update position pos to newValue
//-----------------------------------------------------
void update(
    int node,
    int l,
    int r,
    int pos,
    int newValue)
{
    // Found the leaf
    if (l == r)
    {
        tree[node] = newValue;
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
    {
        update(
            node * 2,
            l,
            mid,
            pos,
            newValue);
    }
    else
    {
        update(
            node * 2 + 1,
            mid + 1,
            r,
            pos,
            newValue);
    }

    // Recalculate parent
    tree[node] =
        tree[node * 2] +
        tree[node * 2 + 1];
}
```

---

# Complete Template

This is the version I'd memorize for OI.

```cpp
vector<long long> tree;
vector<int> a;

void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    tree[node] =
        tree[node * 2] +
        tree[node * 2 + 1];
}

long long query(
    int node,
    int l,
    int r,
    int ql,
    int qr)
{
    if (r < ql || l > qr)
        return 0;

    if (ql <= l && r <= qr)
        return tree[node];

    int mid = (l + r) / 2;

    return query(node * 2,
                 l,
                 mid,
                 ql,
                 qr)
         +
           query(node * 2 + 1,
                 mid + 1,
                 r,
                 ql,
                 qr);
}

void update(
    int node,
    int l,
    int r,
    int pos,
    int value)
{
    if (l == r)
    {
        tree[node] = value;
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(node * 2,
               l,
               mid,
               pos,
               value);
    else
        update(node * 2 + 1,
               mid + 1,
               r,
               pos,
               value);

    tree[node] =
        tree[node * 2] +
        tree[node * 2 + 1];
}
```

Usage:

```cpp
int n;
cin >> n;

a.resize(n);

for (int i = 0; i < n; i++)
    cin >> a[i];

tree.resize(4 * n);

build(1, 0, n - 1);

// sum from index 2 to 7
cout << query(1, 0, n - 1, 2, 7);

// set a[5] = 100
update(1, 0, n - 1, 5, 100);
```

---

# How To Recognize Segment Tree Problems

When you see:

* Array of size up to `100000` or `200000`
* Many queries (`Q`)
* Queries ask about a range `[L,R]`
* Elements change over time

Think:

> "Can I answer range queries and updates in O(log N)?"

If yes:

> **Segment Tree**

---

# Mental Model For OI

Don't think:

> "It's a tree."

Think:

> "It's a hierarchy of intervals."

```
[0..15]
├─ [0..7]
│  ├─ [0..3]
│  └─ [4..7]
└─ [8..15]
   ├─ [8..11]
   └─ [12..15]
```

Each node knows something about its interval.

That's the entire Segment Tree idea. Once this clicks, advanced versions (lazy propagation, max segment tree, GCD segment tree, etc.) become much easier to learn.
