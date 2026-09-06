# Preorder and Postorder Traversal Explained Like You're 5 🎈

Imagine a **family tree**.

```
        Grandpa
       /       \
    Dad       Uncle
   /   \         \
 Me   Sis      Cousin
```

A tree in programming is just a bunch of nodes connected like this.

The question is:

> "In what order should we visit everyone?"

Different traversal methods give different answers.

---

# First: What does "visit" mean?

When we visit a node, we usually:

* print it
* count it
* store it
* process it somehow

Example:

```cpp
cout << node->value;
```

---

# Preorder Traversal

## Idea

When you arrive at a house:

1. Say hello to the person
2. Go left
3. Go right

So:

```
Node
├─ Left
└─ Right
```

becomes

```
Visit Node
Visit Left Subtree
Visit Right Subtree
```

### Formula

```text
PREORDER

Node
Left
Right
```

or

```text
N L R
```

---

## Example

Tree:

```
      A
     / \
    B   C
   / \
  D   E
```

### Step 1

Start at A.

```
Visit A
```

Result:

```
A
```

---

### Step 2

Go left to B.

```
Visit B
```

Result:

```
A B
```

---

### Step 3

Go left to D.

```
Visit D
```

Result:

```
A B D
```

---

### Step 4

D has no children.

Go back.

Visit E.

Result:

```
A B D E
```

---

### Step 5

Go back to A.

Go right to C.

Visit C.

Result:

```
A B D E C
```

---

## Preorder Result

```text
A B D E C
```

---

# Why does Preorder exist?

Because we process the parent FIRST.

Think:

> "I want to know about a folder before opening it."

This is useful for:

* copying directory structures
* saving trees
* generating expressions
* serialization

---

# Real Example: Folder Structure

```
Documents
├─ School
│  ├─ Math
│  └─ Physics
└─ Photos
```

Preorder:

```text
Documents
School
Math
Physics
Photos
```

Notice how parents appear before children.

---

# Postorder Traversal

Now imagine you're cleaning your room.

You cannot remove a box until you've removed everything inside it.

So:

1. Clean left child
2. Clean right child
3. Clean parent

---

## Formula

```text
POSTORDER

Left
Right
Node
```

or

```text
L R N
```

---

## Same Example Tree

```
      A
     / \
    B   C
   / \
  D   E
```

---

### Step 1

Go as far left as possible.

Reach D.

D has no children.

Visit D.

Result:

```
D
```

---

### Step 2

Go to E.

Visit E.

Result:

```
D E
```

---

### Step 3

Both children of B are done.

Visit B.

Result:

```
D E B
```

---

### Step 4

Go to C.

Visit C.

Result:

```
D E B C
```

---

### Step 5

Everything below A is done.

Visit A.

Result:

```
D E B C A
```

---

# Postorder Result

```text
D E B C A
```

---

# Why does Postorder exist?

Because children are processed BEFORE parents.

Useful when:

* deleting trees
* calculating subtree sizes
* dynamic programming on trees
* evaluating dependencies

---

## Example: Deleting a Tree

Suppose:

```
A
├─ B
│  ├─ D
│  └─ E
└─ C
```

You cannot delete:

```
A
```

first.

Otherwise B, C, D, E become "homeless."

Instead:

```text
Delete D
Delete E
Delete B
Delete C
Delete A
```

That's exactly Postorder.

---

# Visual Memory Trick

Imagine arriving at a house.

### Preorder

```text
Knock on door
Explore left room
Explore right room
```

So:

```text
ME -> LEFT -> RIGHT
```

---

### Postorder

```text
Explore left room
Explore right room
Leave house
```

So:

```text
LEFT -> RIGHT -> ME
```

---

# Recursive Implementation

First let's define a node.

```cpp
struct Node
{
    int value;

    Node* left;
    Node* right;

    Node(int v)
    {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};
```

---

# Preorder Code

```cpp
void preorder(Node* node)
{
    // Empty subtree
    if (node == nullptr)
        return;

    // 1. Process current node FIRST
    cout << node->value << " ";

    // 2. Traverse left subtree
    preorder(node->left);

    // 3. Traverse right subtree
    preorder(node->right);
}
```

Remember:

```text
Node
Left
Right
```

---

# Postorder Code

```cpp
void postorder(Node* node)
{
    // Empty subtree
    if (node == nullptr)
        return;

    // 1. Process left subtree
    postorder(node->left);

    // 2. Process right subtree
    postorder(node->right);

    // 3. Process current node LAST
    cout << node->value << " ";
}
```

Remember:

```text
Left
Right
Node
```

---

# Full Example

```cpp
#include <iostream>
using namespace std;

struct Node
{
    int value;

    Node* left;
    Node* right;

    Node(int v)
    {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node* node)
{
    // Nothing here
    if (node == nullptr)
        return;

    // Visit parent first
    cout << node->value << " ";

    // Then children
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node)
{
    // Nothing here
    if (node == nullptr)
        return;

    // Visit children first
    postorder(node->left);
    postorder(node->right);

    // Parent last
    cout << node->value << " ";
}

int main()
{
    /*
            1
          /   \
         2     3
        / \
       4   5
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder: ";
    preorder(root);

    cout << "\n";

    cout << "Postorder: ";
    postorder(root);

    return 0;
}
```

Output:

```text
Preorder: 1 2 4 5 3
Postorder: 4 5 2 3 1
```

---

# How to Recognize Them in OI/Competitive Programming

When you see:

### "Do something before visiting children"

```cpp
dfs(v)
{
    do_something(v);

    for(child)
        dfs(child);
}
```

That's **Preorder**.

Examples:

* printing tree
* assigning entry times
* serialization

---

### "Do something after visiting children"

```cpp
dfs(v)
{
    for(child)
        dfs(child);

    do_something(v);
}
```

That's **Postorder**.

Examples:

* subtree sizes
* DP on trees
* deletion
* aggregating answers from children

---

# One-Line Summary

* **Preorder (NLR)** = **Parent first, then children**
* **Postorder (LRN)** = **Children first, then parent**

A good mental model:

> **Preorder = entering a room and saying hello immediately.**
> **Postorder = cleaning every room before locking the house and leaving.**
