Think of a graph like a bunch of cities connected by roads.

DFS and BFS are just **ways to walk through all cities**.

They do **NOT magically “return” something** by themselves.
Usually they:

* mark visited nodes,
* store order of visiting,
* calculate distances,
* check connectivity,
* etc.

The “template” is just the walking skeleton.

---

# 1. DFS — “go deep first”

DFS behaves like:

> “I see a road? GO THERE.
> Another road? GO THERE TOO.
> Keep going until stuck, then come back.”

Like exploring a maze by always going forward first.

---

## Standard DFS template

```cpp
vector<int> g[N];
bool vis[N];

void dfs(int v) {
    vis[v] = true;

    for (int u : g[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
}
```

---

# What each thing means

## `g`

```cpp
vector<int> g[N];
```

This is the graph.

Example:

```cpp
g[1] = {2, 3};
```

means:

* from node 1
* you can go to 2 and 3

---

## `vis`

```cpp
bool vis[N];
```

Means:

> “Did we already visit this node?”

Prevents infinite loops.

---

## `dfs(v)`

Means:

> “Start exploring from node v”

---

# What DFS “returns”

Usually:

## Nothing (`void`)

because DFS often just:

* marks visited nodes
* fills arrays
* counts things

---

Example:

```cpp
dfs(1);
```

After this:

```cpp
vis[i]
```

tells you which nodes are reachable from 1.

---

# Example graph

```text
1 -- 2
|
3
```

Code:

```cpp
g[1] = {2,3};
g[2] = {1};
g[3] = {1};
```

Run:

```cpp
dfs(1);
```

Visit order might be:

```text
1 -> 2 -> 3
```

---

# 2. BFS — “spread layer by layer”

BFS behaves like:

> “Visit all neighbors first,
> then neighbors of neighbors.”

Like ripples in water.

---

## Standard BFS template

```cpp
vector<int> g[N];
bool vis[N];

void bfs(int start) {
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : g[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        }
    }
}
```

---

# Queue explanation

Queue = line of people.

FIFO:

> first in → first out

---

# BFS order

Same graph:

```text
1 -- 2
|
3
```

BFS from 1:

```text
1 -> 2 -> 3
```

But on bigger graphs BFS differs a lot.

---

# BIG DIFFERENCE

## DFS

Goes:

```text
1 -> 2 -> 5 -> 8 ...
```

deep deep deep

---

## BFS

Goes:

```text
distance 0 from start
distance 1 from start
distance 2 from start
```

layer by layer

---

# Why BFS is super important

BFS naturally finds:

# shortest path in unweighted graph

because it explores by distance.

---

# BFS with distances

```cpp
vector<int> g[N];
int dist[N];

void bfs(int start) {
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : g[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}
```

---

After:

```cpp
bfs(1);
```

`dist[x]` = shortest number of edges from 1 to x.

---

# What beginners misunderstand most

## DFS/BFS are not “the solution”

They are just:

# ways to traverse a graph

The real problem is usually:

* what info do we store?
* what do we calculate during traversal?

---

# Common things stored during DFS/BFS

## Parent

```cpp
parent[u] = v;
```

Means:

> “we came to u from v”

Useful for reconstructing paths.

---

## Distance

```cpp
dist[u]
```

Shortest distance from source.

(BFS only guarantees shortest in unweighted graphs.)

---

## Component number

```cpp
comp[u]
```

Which connected component node belongs to.

---

# Mental model

---

## DFS

```text
go deep
then backtrack
```

Uses:

* recursion
* stack mentality

Great for:

* components
* cycles
* trees
* topological sort

---

## BFS

```text
expand evenly
```

Uses:

* queue

Great for:

* shortest paths
* minimum moves
* wave spreading

---

# Tiny cheat sheet

| Thing          | DFS                | BFS               |
| -------------- | ------------------ | ----------------- |
| Structure      | stack/recursion    | queue             |
| Style          | deep               | layer-by-layer    |
| Shortest path? | ❌                  | ✅                 |
| Memory         | usually smaller    | can be bigger     |
| Typical use    | structure problems | distance problems |

---

# The MOST important realization

This line:

```cpp
for (int u : g[v])
```

means:

> “try every neighbor of current node”

That single loop is basically the entire heart of graph traversal.
