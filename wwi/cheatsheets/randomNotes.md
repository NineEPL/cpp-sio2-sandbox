This is actually a very sneaky task. Let's first understand **what the judge wants**, then why your solution gets WA.

---

# Step 1: What is a tree? (ELI5)

Imagine you have `n` dots.

A **tree** is a graph that:

1. Connects all dots together.
2. Has exactly `n-1` edges.
3. Has **no cycles**.

Example for `n=5`:

```
1
|
2
|\
3 4
|
5
```

Edges:

```
1-2
2-3
2-4
3-5
```

There are 5 vertices and 4 edges.

---

# Step 2: What does subtask 1 ask?

Type `1`:

> Generate a tree with `n` vertices.

That's it.

It doesn't have to be random.
It doesn't have to be beautiful.

Even this always works:

```
1-2
2-3
3-4
...
n-1 - n
```

which is just a path.

---

# Step 3: What is your code trying to do?

You do:

```cpp
for (int i = 1; i < n; ++i)
{
    int a = i;
    int b = gen() % i;

    cout << a + 1 << " " << b + 1 << "\n";
}
```

Let's see what happens.

Suppose:

```
n = 5
```

### i = 1

```cpp
a = 1
b = gen()%1 = 0
```

edge:

```
2 1
```

---

### i = 2

```cpp
a = 2
b = random(0..1)
```

maybe:

```
3 1
```

---

### i = 3

```cpp
a = 3
b = random(0..2)
```

maybe:

```
4 2
```

---

### i = 4

```cpp
a = 4
b = random(0..3)
```

maybe:

```
5 1
```

Result:

```
2-1
3-1
4-2
5-1
```

This is actually a valid tree!

---

# Step 4: Why does this method always create a tree?

This is a famous random-tree construction.

When processing vertex `i+1`:

```cpp
b = random previous vertex
```

You connect the new vertex to an old one.

Since the new vertex was not connected before:

* you never create a cycle
* every new vertex gets attached to the existing tree

After `n-1` edges:

* connected
* no cycles

Therefore it's always a tree.

So the **graph generation logic is correct**.

---

# Step 5: Then why WA?

Look carefully at the output format.

The statement says:

> Each graph description should start with:

```
n m
```

where

* `n` = vertices
* `m` = edges

Then come the edges.

Your code prints only edges:

```cpp
cout << a + 1 << " " << b + 1 << "\n";
```

but never prints

```cpp
cout << n << " " << n-1 << "\n";
```

The judge expects something like:

```
5 4
2 1
3 1
4 2
5 1
```

but your program prints:

```
2 1
3 1
4 2
5 1
```

So the judge reads:

```
2 = n
1 = m
```

and everything becomes nonsense.

Immediate WA.

---

# Step 6: Another subtle problem

The statement says:

> Each graph description should be separated by one empty line.

You do:

```cpp
cout << "\n";
```

after every graph.

That's okay.

But remember to print:

```cpp
n n-1
```

before the edges.

---

# Minimal accepted version for subtask 1

```cpp
if(type == 1)
{
    for(int test = 0; test < c; test++)
    {
        int n;
        cin >> n;

        cout << n << " " << n-1 << "\n";

        for(int i = 1; i < n; i++)
        {
            int parent = gen() % i;

            cout << i+1 << " " << parent+1 << "\n";
        }

        cout << "\n";
    }
}
```

---

# Hint for the entire task

The trick is that most graph types can be built from very simple patterns:

| Type                     | Easy construction                          |
| ------------------------ | ------------------------------------------ |
| 1 Tree                   | connect each new vertex to random previous |
| 2 Path                   | `1-2-3-...-n`                              |
| 3 Star                   | connect every vertex to `1`                |
| 4 Arbitrary graph        | generate random edges, store in set        |
| 5 Clique                 | all pairs `(i,j)`                          |
| 6 Clique minus few edges | start with clique, remove edges            |
| 7 Dense graph            | randomly choose about half of clique edges |
| 8 DAG                    | only allow edges `u < v`                   |
| 9 Binary tree            | parent of `i` is `i/2`                     |
| 10 k components          | first build k trees, then add extra edges  |

A useful observation:

**Type 1, 2, 3, and 9 are basically free points**. You can implement all four in under 20 minutes once you understand how trees work.

The harder ones are 4, 6, 7, and especially 10 because you must carefully control the exact number of edges.
