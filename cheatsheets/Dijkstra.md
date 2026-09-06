# Dijkstra's Algorithm Explained Like You're 5

Imagine you're in a city made of toy roads.

🏠 You start at your house.

🏪 There are shops, parks, schools, and ice cream stores.

Each road has a number showing how long it takes to walk there.

Your goal:

> "What's the fastest way to get from my house to every other place?"

That's exactly what Dijkstra does.

---

# The Main Idea

Imagine you're pouring water from your house.

The water spreads through roads.

Roads that are shorter fill up faster.

Whenever water reaches a place for the first time, it has found the shortest possible path there.

Dijkstra works almost exactly like that.

---

# Example

```
      (4)
   A ------ B
   |        |
 (2)|      (1)
   |        |
   C ------ D
      (5)
```

Numbers are travel costs.

Start at A.

---

## Step 1

Distance table:

| Node | Distance from A |
| ---- | --------------- |
| A    | 0               |
| B    | ∞               |
| C    | ∞               |
| D    | ∞               |

∞ means:

> "I don't know how to get there yet."

---

## Step 2

Look at neighbors of A.

A → B costs 4

A → C costs 2

Update:

| Node | Distance |
| ---- | -------- |
| A    | 0        |
| B    | 4        |
| C    | 2        |
| D    | ∞        |

---

## Step 3

Choose the closest unvisited node.

That's C (distance 2).

Mark C as done.

```
A ✓
C ✓
```

Now check roads from C.

C → D costs 5

Distance to D:

```
A -> C -> D

2 + 5 = 7
```

Update:

| Node | Distance |
| ---- | -------- |
| A    | 0        |
| B    | 4        |
| C    | 2        |
| D    | 7        |

---

## Step 4

Closest unfinished node is B (4).

Mark B as done.

Check neighbor D:

```
A -> B -> D

4 + 1 = 5
```

Current distance to D is 7.

5 is better.

Update D:

| Node | Distance |
| ---- | -------- |
| A    | 0        |
| B    | 4        |
| C    | 2        |
| D    | 5        |

---

## Step 5

Take D.

Done.

Final shortest distances:

```
A -> A = 0
A -> B = 4
A -> C = 2
A -> D = 5
```

---

# The Secret Logic

Dijkstra always does:

1. Find closest unfinished node.
2. Mark it as finished.
3. Try improving distances to neighbors.
4. Repeat.

---

# Why Does It Work?

Suppose Dijkstra picks node X because it's currently the closest.

Could there secretly be a shorter path later?

No.

Because any future path would have to go through nodes that are already farther away.

So once a node becomes the smallest unfinished node:

> Its distance is guaranteed correct forever.

This is the key observation.

---

# Real-Life Uses

## Google Maps

Road lengths:

```
Warsaw -> Krakow = 300 km
Warsaw -> Lodz = 120 km
```

Find shortest route.

---

## GPS Navigation

Fastest path.

---

## Internet Routing

Routers use similar algorithms to send packets.

---

## Video Games

NPC finding shortest path.

---

## Logistics

Delivery routes.

---

## Flight Planning

Cheapest route between airports.

---

# Graph Representation

Dijkstra works on a graph.

Example:

```
1 --4-- 2
|       |
2       1
|       |
3 --5-- 4
```

Store it like:

```cpp
vector<pair<int,int>> graph[n];
```

Each pair:

```cpp
(neighbor, cost)
```

Example:

```cpp
graph[1].push_back({2, 4});
```

means:

```
1 -> 2 costs 4
```

---

# Naive Version

Each time:

```
Find smallest distance manually.
```

Complexity:

```
O(V²)
```

Good for small graphs.

---

# Fast Version (Priority Queue)

Instead of searching manually:

Use a min-heap.

C++:

```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```

Now finding smallest node costs:

```
O(log V)
```

Total complexity:

```
O((V + E) log V)
```

This is the version used in contests.

---

# Full Competitive Programming Implementation

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n = 5; // number of nodes

    // graph[u] contains:
    // {neighbor, edge_cost}
    vector<vector<pair<int,int>>> graph(n + 1);

    // Add edges
    graph[1].push_back({2, 4});
    graph[1].push_back({3, 2});

    graph[2].push_back({4, 1});

    graph[3].push_back({4, 5});

    // Infinity value
    const int INF = 1e9;

    // dist[i] = shortest known distance to node i
    vector<int> dist(n + 1, INF);

    // Start node
    int start = 1;

    // Distance to start is 0
    dist[start] = 0;

    // Min-heap:
    //
    // pair:
    // {distance, node}
    //
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // Start by pushing source node
    pq.push({0, start});

    while (!pq.empty())
    {
        // Get closest node currently known
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();

        // IMPORTANT!
        //
        // Sometimes an old worse distance remains
        // inside the priority queue.
        //
        // Example:
        // D got distance 10
        // later improved to 5
        //
        // Both entries stay in queue.
        //
        // Ignore outdated one.
        //
        if (currentDistance > dist[currentNode])
            continue;

        // Try every outgoing edge
        for (auto edge : graph[currentNode])
        {
            int neighbor = edge.first;
            int edgeCost = edge.second;

            // New possible path:
            //
            // source
            //   ->
            // currentNode
            //   ->
            // neighbor
            //
            int newDistance =
                dist[currentNode] + edgeCost;

            // Relaxation step
            //
            // Found shorter path?
            //
            if (newDistance < dist[neighbor])
            {
                // Update best distance
                dist[neighbor] = newDistance;

                // Put improved distance into heap
                pq.push({
                    newDistance,
                    neighbor
                });
            }
        }
    }

    cout << "Shortest distances:\n";

    for (int i = 1; i <= n; i++)
    {
        cout << "Node "
             << i
             << ": ";

        if (dist[i] == INF)
            cout << "unreachable";
        else
            cout << dist[i];

        cout << "\n";
    }

    return 0;
}
```

---

# The Most Important Line

This is the heart of Dijkstra:

```cpp
if (newDistance < dist[neighbor])
{
    dist[neighbor] = newDistance;
}
```

This operation is called **relaxation**.

Meaning:

> "I found a better way to reach this node."

Almost every shortest-path algorithm is built around this idea.

---

# When Dijkstra DOESN'T Work

If there are negative edges:

```
A -> B = 5
A -> C = 2
B -> C = -10
```

Dijkstra can make wrong decisions.

For negative weights use:

* Bellman-Ford
* SPFA (carefully)
* Floyd-Warshall (all-pairs)

---

# Contest Cheat Sheet

If you see:

* shortest path
* minimum cost route
* weighted graph
* all weights ≥ 0

Your brain should immediately think:

**Dijkstra**.

Template to remember:

```cpp
dist[start] = 0;
pq.push({0, start});

while (!pq.empty())
{
    take closest node;

    if (outdated)
        continue;

    for (all neighbors)
    {
        if (better path found)
        {
            update distance;
            push into pq;
        }
    }
}
```

That's 95% of Dijkstra problems in competitive programming.
