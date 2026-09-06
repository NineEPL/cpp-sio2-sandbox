# LCA (Lowest Common Ancestor) explained like you're 5 years old

Imagine a **family tree**.

```
        Grandpa (1)
        /       \
     Dad(2)    Uncle(3)
     /   \        \
  Me(4) Sis(5) Cousin(6)
```

Suppose:

* I'm node `4`
* My sister is node `5`

If we walk upward:

```
4 -> 2 -> 1
5 -> 2 -> 1
```

The **first common parent** is `2`.

So:

```
LCA(4,5) = 2
```

---

For:

```
4 -> 2 -> 1
6 -> 3 -> 1
```

First common parent:

```
1
```

So:

```
LCA(4,6) = 1
```

---

# What does LCA mean?

**Lowest Common Ancestor**

* Common = ancestor of both nodes
* Lowest = closest to them

Not highest.

Example:

```
        1
      /   \
     2     3
    / \
   4   5
```

For `4` and `5`:

Common ancestors:

```
2
1
```

Lowest one:

```
2
```

Therefore:

```
LCA(4,5)=2
```

---

# Why do we care?

LCA appears EVERYWHERE in competitive programming.

Typical tasks:

### Distance between nodes

```
distance(a,b)
```

Formula:

```
depth[a] + depth[b] - 2 * depth[LCA(a,b)]
```

---

### Path queries

Questions like:

> Sum values from node A to B

or

> Maximum edge on path A to B

Usually the path passes through the LCA.

---

### Family trees

Find closest common ancestor.

---

### Organization charts

Find lowest common manager.

---

### File systems

Find closest common folder.

---

# Brute Force Idea

Suppose:

```
4 and 6
```

We can:

1. Walk from 4 to root.
2. Mark all ancestors.
3. Walk from 6 upward.
4. First marked node = answer.

Works.

But:

```
O(height)
```

per query.

For:

```
n = 100000
q = 100000
```

too slow.

---

# Better Idea: Binary Lifting

This is the standard OI/CP solution.

---

## Observation

Normally:

```
parent[v]
```

gives:

```
2^0 = 1 step up
```

What if we store:

```
up[v][1]
```

= 2 steps up?

And:

```
up[v][2]
```

= 4 steps up?

And:

```
up[v][3]
```

= 8 steps up?

etc.

---

Example

```
up[v][0] = parent

up[v][1] = grandparent

up[v][2] = 4th ancestor

up[v][3] = 8th ancestor
```

This is exactly like binary search.

Instead of moving:

```
1 + 1 + 1 + 1 + 1 ...
```

we jump:

```
32 + 16 + 8 + 4 + 2 + 1
```

---

# Preprocessing

Suppose:

```
up[v][k]
```

means:

> ancestor of v that is 2^k levels above

Then:

```
up[v][0] = parent[v]
```

Easy.

---

For larger jumps:

```
up[v][1]
```

means:

2 levels above.

We can do:

```
up[v][1] = up[ up[v][0] ][0]
```

---

Similarly:

```
up[v][2]
```

means 4 levels above.

```
up[v][2] =
    up[ up[v][1] ][1]
```

---

General formula:

```cpp
up[v][k] =
    up[ up[v][k-1] ][k-1];
```

Very important.

---

# Example

Suppose:

```
up[7][3]
```

means:

```
8 levels above 7
```

We split:

```
8 = 4 + 4
```

So:

```cpp
up[7][3]
=
up[
    up[7][2]
][2];
```

---

# Finding LCA

Suppose:

```
u = 8
v = 13
```

First:

### Make depths equal

Maybe:

```
depth[8]=10
depth[13]=6
```

Difference:

```
4
```

Lift node 8 upward by 4.

Now both are at same depth.

---

Example:

```
       1
      / \
     2   3
    / \
   4   5
```

Query:

```
LCA(4,5)
```

Depths already equal.

---

Now we lift BOTH nodes.

Starting from largest jump.

If their ancestors differ:

```cpp
up[u][k] != up[v][k]
```

then we jump both.

Why?

Because we know LCA is higher.

---

Eventually:

```
u = 4
v = 5
```

becomes

```
u = 4
v = 5
```

(no jumps possible)

Their parents:

```
2
2
```

same.

Answer:

```
2
```

---

# Full Complexity

Preprocessing:

```
O(N log N)
```

One query:

```
O(log N)
```

Memory:

```
O(N log N)
```

Perfect for:

```
N = 100000
N = 200000
```

---

# Standard C++ Template (heavily commented)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

// log2(200000) < 18
// 20 is enough, 21 for safety
const int LOG = 21;

vector<int> graph[MAXN];

// up[v][k]
// = ancestor of v that is 2^k levels above
int up[MAXN][LOG];

int depth[MAXN];

///////////////////////////////////////////////////////////
// DFS
//
// Calculates:
// 1. depth[]
// 2. up[][0] (parent)
//
// Then builds larger jumps using:
//
// up[v][k] = up[ up[v][k-1] ][k-1]
///////////////////////////////////////////////////////////
void dfs(int v, int parent)
{
    // immediate parent
    up[v][0] = parent;

    // build binary lifting table
    for (int k = 1; k < LOG; k++)
    {
        up[v][k] =
            up[ up[v][k - 1] ][k - 1];
    }

    // visit children
    for (int to : graph[v])
    {
        if (to == parent)
            continue;

        depth[to] = depth[v] + 1;

        dfs(to, v);
    }
}

///////////////////////////////////////////////////////////
// Lift node v by x levels
//
// Example:
//
// x = 13
//
// binary:
// 13 = 8 + 4 + 1
//
// So we use jumps:
// 2^3, 2^2, 2^0
///////////////////////////////////////////////////////////
int lift(int v, int x)
{
    for (int k = 0; k < LOG; k++)
    {
        if (x & (1 << k))
        {
            v = up[v][k];
        }
    }

    return v;
}

///////////////////////////////////////////////////////////
// Lowest Common Ancestor
///////////////////////////////////////////////////////////
int lca(int u, int v)
{
    ///////////////////////////////////////////////////////
    // STEP 1
    // Make depths equal
    ///////////////////////////////////////////////////////

    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];

    u = lift(u, diff);

    ///////////////////////////////////////////////////////
    // If they became the same node,
    // that node is the answer.
    ///////////////////////////////////////////////////////

    if (u == v)
        return u;

    ///////////////////////////////////////////////////////
    // STEP 2
    //
    // Try largest jumps first.
    //
    // If ancestors differ,
    // move both upward.
    ///////////////////////////////////////////////////////

    for (int k = LOG - 1; k >= 0; k--)
    {
        if (up[u][k] != up[v][k])
        {
            u = up[u][k];
            v = up[v][k];
        }
    }

    ///////////////////////////////////////////////////////
    // Now:
    //
    // u and v are directly below LCA
    //
    // so parent is answer.
    ///////////////////////////////////////////////////////

    return up[u][0];
}

int main()
{
    int n;
    cin >> n;

    // tree has n-1 edges
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // assume root = 1
    depth[1] = 0;

    dfs(1, 0);

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << '\n';
    }
}
```

---

# How to remember it for OI

Think of LCA as a **three-step recipe**:

### Step 1

Make both nodes stand on the same floor.

```cpp
u = lift(u, depth[u]-depth[v]);
```

---

### Step 2

From biggest jump to smallest:

```cpp
if (up[u][k] != up[v][k])
{
    u = up[u][k];
    v = up[v][k];
}
```

Keep jumping while they're in different "families".

---

### Step 3

When they are just below the answer:

```cpp
return up[u][0];
```

Return their parent.

That's the entire binary lifting LCA algorithm in one sentence:

> "Lift the deeper node, jump both upward while their ancestors differ, then return their common parent."













Imagine you have a huge family tree, and you want to find the **closest shared relative** (like a parent, grandparent, or great-grandparent) between you and your cousin.

In computer science, **LCA** stands for **Lowest Common Ancestor**. In competitive programming, it’s a way to find the closest "shared parent" node between two points on a tree-shaped network.
---

## What is LCA Used For?

Think of a tree structure like a map of roads that never form loops:

* **Finding Shared Roots:** It helps you find where two paths merge together.
* **Calculating Distance:** If you know the LCA of two points, you can easily figure out how many steps or how much time it takes to travel between them.
* **Path Queries:** It lets you quickly check properties of the path between any two points (like finding the heaviest edge or the minimum weight along that path).

---

## 🟢 Green Flags: When Should You Use LCA?

Here are the big clues in a problem that scream, **"Use LCA!"**

* **"It's a Tree":** The problem mentions a connected graph with $N$ nodes and $N-1$ edges (or explicitly calls it a tree).
* **Lots of Path Queries:** The problem asks you to answer questions about the path between point $A$ and point $B$ hundreds of thousands of times ($Q$ queries).
* **Distances on a Tree:** You need to calculate the distance between two nodes quickly using the formula:

$$\text{Distance}(A, B) = \text{Depth}(A) + \text{Depth}(B) - 2 \times \text{Depth}(\text{LCA}(A, B))$$


* **Upward Moves:** You need to jump "up" the tree toward the root from two different places to see where they collide.

---

## How It Works (The 5-Year-Old Version)

Imagine two squirrels sitting on different branches of a big oak tree. They both want to meet at the branch point where their two twigs connect, without climbing down to the main trunk if they don't have to.

1. If one squirrel is higher up than the other, it climbs down until they are both at the **same height**.
2. Then, both squirrels climb down **at the exact same time, step by step**, until they land on the exact same branch!

That branch where they meet is the **LCA**. In code, we use a trick called *Binary Lifting* so the squirrels can take giant superhero leaps instead of tiny steps, making it super fast!