# Binary Search — Explained Like You're 5 🧸

Imagine you're playing a guessing game.

I pick a number from **1 to 100**.

You could guess:

* 1
* 2
* 3
* 4
* ...

This might take **100 guesses** 😭.

But there's a smarter way.

You ask:

> "Is it bigger than 50?"

If I say **yes**, you instantly throw away numbers 1–50.

Now only 51–100 remain.

Then ask:

> "Is it bigger than 75?"

Again, half disappears.

Every question removes **half of the remaining possibilities**.

That's Binary Search.

---

# The Core Idea

Binary = 2

Binary Search means:

> Keep cutting the search space into 2 halves.

Instead of checking every element:

```
1 2 3 4 5 6 7 8 9 10
```

you jump to the middle:

```
            5
```

If your target is bigger:

```
6 7 8 9 10
```

If smaller:

```
1 2 3 4
```

Repeat.

---

# Why Is It So Fast?

Suppose you have:

```
1,000,000 numbers
```

Normal search:

```
up to 1,000,000 checks
```

Binary Search:

```
1,000,000
500,000
250,000
125,000
...
```

Only about:

```
log₂(1,000,000) ≈ 20
```

checks.

That's crazy fast.

---

# When Can We Use Binary Search?

**IMPORTANT**

The data must be sorted.

Good:

```
1 3 5 8 10 15 20
```

Bad:

```
10 2 15 1 20 5
```

Because when you throw away half, you need to know that everything on one side is smaller or larger.

---

# Visual Example

Find:

```
target = 15
```

Array:

```
[1, 3, 5, 8, 10, 15, 20]
```

Indices:

```
 0  1  2  3   4   5   6
```

### Step 1

Middle:

```
index = 3
value = 8
```

8 < 15

Throw away left half.

```
[10, 15, 20]
```

---

### Step 2

Middle:

```
index = 5
value = 15
```

Found!

---

# Standard Binary Search Template

```cpp
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& a, int target)
{
    // left boundary of current search area
    int left = 0;

    // right boundary of current search area
    int right = a.size() - 1;

    // while we still have something to search
    while (left <= right)
    {
        // middle element
        // safer than (left + right)/2
        int mid = left + (right - left) / 2;

        // target found
        if (a[mid] == target)
        {
            return mid;
        }

        // target is bigger
        // throw away left half
        if (a[mid] < target)
        {
            left = mid + 1;
        }

        // target is smaller
        // throw away right half
        else
        {
            right = mid - 1;
        }
    }

    // not found
    return -1;
}

int main()
{
    vector<int> a = {1,3,5,8,10,15,20};

    cout << binarySearch(a, 15);

    return 0;
}
```

---

# What Does Binary Search Return?

Usually:

```cpp
return index;
```

Example:

```
[1,3,5,8,10,15,20]
```

Searching for:

```
15
```

returns:

```
5
```

because:

```
a[5] = 15
```

If not found:

```cpp
return -1;
```

---

# Binary Search Variants

Competitive programming often needs more than:

> "Does this number exist?"

Sometimes we need:

* first occurrence
* last occurrence
* lower bound
* upper bound

---

# Lower Bound

Find first element:

```
>= x
```

Example:

```cpp
[1,2,2,2,5,7]
```

Find first:

```
>= 2
```

Answer:

```
index 1
```

---

### Implementation

```cpp
int lowerBound(vector<int>& a, int x)
{
    int left = 0;
    int right = a.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        // mid is large enough
        // answer may be here or further left
        if (a[mid] >= x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}
```

---

# Upper Bound

Find first element:

```
> x
```

Example:

```cpp
[1,2,2,2,5,7]
```

Find first:

```
> 2
```

Answer:

```
index 4
```

---

```cpp
int upperBound(vector<int>& a, int x)
{
    int left = 0;
    int right = a.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (a[mid] > x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}
```

---

# Binary Search on the Answer 🔥

This is the version used all the time in OI/ICPC.

The idea is:

> We don't search for a value in an array.
>
> We search for the answer itself.

---

## Example: Cookie Factory 🍪

You have machines.

Machine speeds:

```
2
3
7
```

Meaning:

* machine 1 makes 1 cookie every 2 seconds
* machine 2 makes 1 cookie every 3 seconds
* machine 3 makes 1 cookie every 7 seconds

Question:

> How many seconds are needed to make 10 cookies?

---

# Brute Force

Check:

```
1 second?
2 seconds?
3 seconds?
4 seconds?
...
```

Too slow.

---

# Observation

If 20 seconds is enough...

then:

```
21 seconds
22 seconds
23 seconds
```

are also enough.

If 10 seconds is NOT enough...

then:

```
9
8
7
...
```

aren't enough either.

This creates:

```
false false false false false
true  true  true  true  true
```

Example:

```
1 sec   -> false
2 sec   -> false
3 sec   -> false
...
12 sec  -> false
13 sec  -> true
14 sec  -> true
15 sec  -> true
```

We want:

> first true

And Binary Search loves finding first true.

---

# Visual

```
FFFFFFFFFFFTTTTTTTTTTT
           ^
       answer
```

Find the border.

---

# Generic Template

```cpp
long long left = 0;
long long right = 1e18;

while (left < right)
{
    long long mid = left + (right - left) / 2;

    if (check(mid))
    {
        // mid works
        // maybe there is a smaller answer
        right = mid;
    }
    else
    {
        // mid doesn't work
        left = mid + 1;
    }
}

cout << left;
```

---

# The Magic Function: check()

Everything depends on this.

For the cookie example:

```cpp
bool check(long long time)
{
    long long cookies = 0;

    for (int speed : machines)
    {
        // how many cookies this machine makes
        cookies += time / speed;
    }

    return cookies >= target;
}
```

---

# How To Recognize Binary Search on Answer

Whenever you see:

> Find minimum X such that ...

or

> Find maximum X such that ...

your brain should scream:

```
BINARY SEARCH!!!
```

Especially if:

* answer is a number
* brute force is too slow
* answers form

```
FFFFTTTT
```

or

```
TTTTFFFF
```

pattern

---

# Mental Checklist for OI

When reading a problem ask:

### 1. Am I searching for a number?

Example:

```
minimum time
maximum distance
minimum cost
largest value
```

↓

### 2. Can I check a candidate answer?

Example:

```
Can I verify if 100 seconds is enough?
```

↓

### 3. Does it become monotonic?

```
FFFFTTTT
```

or

```
TTTTFFFF
```

↓

### 4. Binary Search on Answer

---

# Difference Between The Two

| Normal Binary Search    | Binary Search on Answer                   |
| ----------------------- | ----------------------------------------- |
| Search array            | Search answer                             |
| Needs sorted array      | Needs monotonic condition                 |
| Looking for value       | Looking for smallest/largest valid answer |
| Compare with array[mid] | Compare with check(mid)                   |
| Returns position/value  | Returns optimal answer                    |

Think of it like this:

* **Normal binary search** = "Where is the toy?"
* **Binary search on answer** = "What's the smallest box that can fit the toy?"

Both work by repeatedly cutting possibilities in half. 🚀
