Imagine you have a bunch of tasks, and some tasks must happen before others.

For example:

🍞 Make a sandwich

1. Buy bread
2. Buy cheese
3. Put cheese on bread
4. Eat sandwich

You can't eat the sandwich before making it.
You can't make it before buying bread and cheese.

Topological sort is simply:

> "Find an order of doing things so that every task happens after all the things it depends on."

---

# The idea like you're 5

Let's draw arrows:

```
Buy bread  ----\
                > Make sandwich --> Eat
Buy cheese ----/
```

An arrow means:

> "Do me first!"

Bread says:
"Do me before making the sandwich."

Cheese says:
"Do me before making the sandwich."

A valid order is:

```
Bread
Cheese
Make sandwich
Eat
```

or

```
Cheese
Bread
Make sandwich
Eat
```

Both work.

Topological sort finds one of these valid orders.

---

# What problems does it solve?

Any time you have dependencies.

## School courses

```
Math 1 -> Math 2 -> Math 3
```

You must pass Math 1 before Math 2.

Topological sort tells you the order.

---

## Building software

Suppose file C needs file B.

```
A -> B -> C
```

Compile:

```
A
B
C
```

not

```
C
B
A
```

because C depends on B.

---

## Project management

```
Foundation -> Walls -> Roof
```

You can't build the roof first.

Topological sort gives a sensible construction order.

---

# The graph view

In competitive programming we represent this as a graph.

Example:

```
1 -> 2
1 -> 3
2 -> 4
3 -> 4
```

Picture:

```
    1
   / \
  v   v
  2   3
   \ /
    v
    4
```

Meaning:

* 1 before 2
* 1 before 3
* 2 before 4
* 3 before 4

Valid answer:

```
1 2 3 4
```

or

```
1 3 2 4
```

Both are correct.

---

# The key observation

Look for nodes with NO incoming arrows.

Why?

Because nobody says they must wait.

In our graph:

```
1 -> 2
1 -> 3
2 -> 4
3 -> 4
```

Incoming arrows:

```
1 : 0
2 : 1
3 : 1
4 : 2
```

Node 1 has zero incoming arrows.

Therefore we can safely do it first.

---

# Kahn's Algorithm (the common implementation)

This is the version used most often in OI/competitive programming.

## Step 1

Count incoming arrows (indegree).

```
1 : 0
2 : 1
3 : 1
4 : 2
```

---

## Step 2

Put all nodes with indegree 0 into a queue.

```
Queue = [1]
```

---

## Step 3

Take one node from queue.

```
Answer = [1]
```

Remove its outgoing edges:

```
1 -> 2
1 -> 3
```

New indegrees:

```
2 : 0
3 : 0
4 : 2
```

Add new zeros to queue.

```
Queue = [2,3]
```

---

## Step 4

Take 2.

```
Answer = [1,2]
```

Remove:

```
2 -> 4
```

Indegrees:

```
4 : 1
```

Not zero yet.

---

## Step 5

Take 3.

```
Answer = [1,2,3]
```

Remove:

```
3 -> 4
```

Indegrees:

```
4 : 0
```

Add 4.

---

## Step 6

Take 4.

```
Answer = [1,2,3,4]
```

Done.

---

# Why does this work?

Whenever a node reaches indegree 0:

```
all its prerequisites are already done
```

because the only way indegree becomes zero is if every incoming edge has been removed.

So we're always choosing tasks that are ready to be done.

---

# Detecting cycles

What if we have:

```
1 -> 2
2 -> 3
3 -> 1
```

Picture:

```
1 → 2
↑   ↓
3 ←-
```

Who has indegree 0?

```
1 : 1
2 : 1
3 : 1
```

Nobody.

Queue starts empty.

Algorithm gets stuck immediately.

Why?

Because everyone is waiting for someone else.

This is called a **cycle**.

Topological sort only works on a **DAG**:

**D**irected **A**cyclic **G**raph

which means:

* arrows have direction
* no loops

---

# C++ implementation

```cpp
vector<int> topoSort(int n, vector<vector<int>>& graph) {
    vector<int> indegree(n + 1, 0);

    for (int u = 1; u <= n; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for (int v : graph[u]) {
            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }

    if ((int)order.size() != n) {
        cout << "Cycle exists\n";
    }

    return order;
}
```

---

# OI / Competitive Programming intuition

When you see:

> "Task A must be done before Task B"

or

> "Course X is a prerequisite for Course Y"

or

> "Find an ordering satisfying all constraints"

your brain should immediately think:

```
constraint:
A before B

edge:
A -> B

answer:
topological sort
```

That's the entire trick.

The hard part is usually not the algorithm itself—it's recognizing that the problem is secretly asking for a topological sort.
