I think by **F&U** you mean **Find & Union**, also called **Disjoint Set Union (DSU)** or **Union-Find**.

It's one of the most useful data structures in competitive programming because it can quickly answer:

> "Are these two things in the same group?"

and

> "Merge these two groups together."

---

# Imagine You're 5 Years Old

Let's say there are 8 kids in a playground.

At the beginning, nobody knows each other:

```
1   2   3   4   5   6   7   8
```

Everybody is in their own friend group.

Now:

```
Union(1,2)
```

means:

> "Make 1 and 2 friends."

Groups become:

```
(1,2)   3   4   5   6   7   8
```

Then:

```
Union(2,3)
```

Now:

```
(1,2,3)   4   5   6   7   8
```

Then someone asks:

```
Find(1) == Find(3) ?
```

Meaning:

> "Do 1 and 3 belong to the same friend group?"

Answer:

```
YES
```

because both are in:

```
(1,2,3)
```

---

# The Main Idea

Instead of storing all members of a group, DSU stores:

> Who is the parent of each node?

Think of every group as a tree.

Example:

```
1
|
2
|
3
```

Stored as:

```
parent[1] = 1
parent[2] = 1
parent[3] = 2
```

To find which group 3 belongs to:

```
3 → 2 → 1
```

Root = 1

So group leader is:

```
1
```

---

# Operations

DSU has only two important operations.

## Find(x)

Finds the leader (root) of x's group.

Example:

```
1
|
2
|
3
```

Find(3):

```
3 → 2 → 1
```

returns:

```
1
```

---

## Union(a,b)

Connects two groups.

Before:

```
1      4
|      |
2      5
```

Union(2,5)

After:

```
1
|
2
|
4
|
5
```

Now everyone belongs to one group.

---

# Why Is It Useful?

Because many problems ask:

### 1. Are two nodes connected?

Example:

Cities connected by roads.

```
A --- B --- C

D --- E
```

Question:

```
Is A connected to C?
```

DSU:

```
Find(A) == Find(C)
```

YES.

---

### 2. Build Networks

Used in:

* Internet cables
* Electric grids
* Road systems

---

### 3. Kruskal's Algorithm

One of the most famous graph algorithms.

Used for:

> Minimum Spanning Tree (MST)

DSU quickly checks:

```
Will adding this edge create a cycle?
```

---

### 4. Social Networks

```
Alice friends Bob
Bob friends Charlie
```

Question:

```
Are Alice and Charlie in the same friend circle?
```

DSU answers instantly.

---

# Naive Implementation

The simplest version.

```cpp
#include <iostream>
using namespace std;

const int N = 100005;

// parent[i] stores parent of node i
int parent[N];

/////////////////////////////////////////////////
// Find leader of a set
/////////////////////////////////////////////////
int Find(int x)
{
    // If node is its own parent,
    // it is the root of the tree.
    if(parent[x] == x)
        return x;

    // Otherwise keep climbing upward.
    return Find(parent[x]);
}

/////////////////////////////////////////////////
// Merge two sets
/////////////////////////////////////////////////
void Union(int a, int b)
{
    // Find leaders of both sets.
    int rootA = Find(a);
    int rootB = Find(b);

    // If already in same set,
    // nothing to do.
    if(rootA == rootB)
        return;

    // Make one root point to another.
    parent[rootB] = rootA;
}

int main()
{
    int n = 5;

    // Initially everybody is alone.
    for(int i = 1; i <= n; i++)
        parent[i] = i;

    Union(1, 2);
    Union(2, 3);

    if(Find(1) == Find(3))
        cout << "Same group\n";
    else
        cout << "Different groups\n";
}
```

Works, but can become slow.

---

# Problem With Naive DSU

Suppose we create:

```
1
|
2
|
3
|
4
|
5
|
6
|
7
```

Finding 7 requires:

```
7 → 6 → 5 → 4 → 3 → 2 → 1
```

Lots of work.

---

# Optimization 1: Path Compression

The genius trick.

Before:

```
1
|
2
|
3
|
4
|
5
```

When we do:

```
Find(5)
```

we walk:

```
5 → 4 → 3 → 2 → 1
```

After reaching 1, we immediately rewrite all parents:

```
1
|\
| \
2  3
|  |
4  5
```

Actually even flatter:

```
    1
  / | \ \
 2  3 4 5
```

Now every future Find is almost instant.

---

## Path Compression Code

```cpp
int Find(int x)
{
    // Root found
    if(parent[x] == x)
        return x;

    ////////////////////////////////////////////////////
    // Path compression:
    //
    // Save the root directly in parent[x]
    // so next time we jump straight there.
    ////////////////////////////////////////////////////
    return parent[x] = Find(parent[x]);
}
```

This single line is the magic.

```cpp
parent[x] = Find(parent[x]);
```

---

# Optimization 2: Union By Size

Another trick.

When merging:

```
small tree
+
big tree
```

Attach:

```
small → big
```

Never:

```
big → small
```

This prevents tall trees.

---

Example:

Bad:

```
1-2-3-4-5-6-7
```

Good:

```
      1
   / / \ \
  2 3  4 5
```

Much flatter.

---

# Full Competitive Programming Version

```cpp
#include <iostream>
using namespace std;

const int N = 100005;

int parent[N];
int sz[N];   // size of each component

/////////////////////////////////////////////////
// Find with path compression
/////////////////////////////////////////////////
int Find(int x)
{
    // Root found
    if(parent[x] == x)
        return x;

    // Compress path
    return parent[x] = Find(parent[x]);
}

/////////////////////////////////////////////////
// Union by size
/////////////////////////////////////////////////
void Union(int a, int b)
{
    // Find leaders
    a = Find(a);
    b = Find(b);

    // Already connected
    if(a == b)
        return;

    //////////////////////////////////////////////////
    // Ensure 'a' is larger component
    //////////////////////////////////////////////////
    if(sz[a] < sz[b])
        swap(a, b);

    //////////////////////////////////////////////////
    // Attach smaller tree to larger tree
    //////////////////////////////////////////////////
    parent[b] = a;

    //////////////////////////////////////////////////
    // Update size
    //////////////////////////////////////////////////
    sz[a] += sz[b];
}

int main()
{
    int n = 10;

    //////////////////////////////////////////////////
    // Initially:
    // Every node is its own parent
    // Every component has size 1
    //////////////////////////////////////////////////
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    Union(1, 2);
    Union(2, 3);
    Union(5, 6);

    cout << (Find(1) == Find(3)) << "\n"; // 1
    cout << (Find(1) == Find(5)) << "\n"; // 0
}
```

---

# Complexity

Without optimizations:

```
Find  = O(N)
Union = O(N)
```

Very bad.

With:

* Path Compression
* Union By Size (or Rank)

Complexity becomes:

```
Find  ≈ O(1)
Union ≈ O(1)
```

More precisely:

```
O(α(N))
```

where α is the **inverse Ackermann function**.

For every practical input size on Earth:

```
α(N) ≤ 5
```

So competitive programmers simply treat DSU as:

```
O(1)
```

---

# Exam/Contest Mental Model

When you see:

* "merge groups"
* "friend circles"
* "connected components"
* "are u and v connected?"
* "Kruskal MST"
* "dynamic connectivity"

immediately think:

> "This is probably a DSU / Union-Find problem."

The entire structure is basically just:

```cpp
Find(x);      // Who is your leader?
Union(a,b);   // Make two groups become one
```

and the two magic optimizations:

```cpp
Path Compression
Union by Size/Rank
```

which make it ridiculously fast.
