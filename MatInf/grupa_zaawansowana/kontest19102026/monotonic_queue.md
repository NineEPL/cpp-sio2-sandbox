````
# Monotonic Queue (Kolejka Monotoniczna) — C++ Cheatsheet

A monotonic queue is a data structure that maintains elements in sorted order while allowing efficient insertion and removal from both ends.

It is useful for finding minimums, maximums, and optimal subarrays in **O(n)** time.

---

## 1. Intuition: Explain It Like I'm 5

Imagine you're looking for the tallest child in a moving line of 3 children.

If a new child is taller than some children behind the current tallest, those shorter children can never be the tallest while the new child is still in the window.

So we remove them!

**The main idea:** Keep only candidates that could still become the answer. Throw away candidates that are already dominated by better ones.

There are two main types:

- **Decreasing deque:** Values decrease from front to back. The front contains the maximum.
- **Increasing deque:** Values increase from front to back. The front contains the minimum.

We usually use `deque<int>` and store **indices**, not values, so we can track positions and remove expired elements.

---

## 2. Basic C++ Template

```cpp
#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

// Decreasing deque: maximum at the front.
// Increasing deque: minimum at the front.

// Remove from the front:
dq.pop_front();

// Remove from the back:
dq.pop_back();

// Add to the back:
dq.push_back(index);

// Read the best candidate:
int best = a[dq.front()];
````

### How to maintain the order

For maximum:

```
while (!dq.empty() && a[dq.back()] <= a[i]) {
    dq.pop_back();
}
dq.push_back(i);
```

For minimum:

```
while (!dq.empty() && a[dq.back()] >= a[i]) {
    dq.pop_back();
}
dq.push_back(i);
```

Why remove smaller/larger elements?

A new element that is at least as good and appears later dominates an older candidate. The older candidate cannot improve the answer while the new one is still available.

# 3. Use Case: Sliding Window Maximum / Minimum

## Problem

Given an array `a` of length `n` and a window size `k`, find the maximum or minimum of every consecutive subarray of length `k`.

Example:

```
a = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3

Maximums: [3, 3, 5, 5, 6, 7]
Minimums: [-1, -3, -3, -3, 3, 3]
```

A brute-force solution takes `O(n * k)` time.

A monotonic deque solves it in O(n).

## Algorithm

For each index `i`:

1. Remove indices that are outside the current window.
2. Remove dominated candidates from the back.
3. Add `i` to the deque.
4. Once the window is complete, the front contains the answer.

For a window ending at `i`, its valid indices are:

```
i - k + 1, ..., i
```

Therefore, remove expired indices with:

```
while (!dq.empty() && dq.front() <= i - k) {
    dq.pop_front();
}
```

## Generic C++ Template

`Maximum = true` finds maximums; `Maximum = false` finds minimums.

```
#include <bits/stdc++.h>
using namespace std;

template <bool Maximum>
vector<int> slidingWindowExtremum(
    const vector<int>& a, int k
) {
    int n = (int)a.size();

    if (k <= 0 || k > n) return {};

    deque<int> dq;  // Stores indices
    vector<int> ans;

    for (int i = 0; i < n; i++) {

        // 1. Remove expired indices.
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. Remove dominated candidates.
        while (!dq.empty()) {
            int j = dq.back();

            if constexpr (Maximum) {
                if (a[j] > a[i]) break;
            } else {
                if (a[j] < a[i]) break;
            }

            dq.pop_back();
        }

        // 3. Add the current index.
        dq.push_back(i);

        // 4. Record the answer for a complete window.
        if (i >= k - 1) {
            ans.push_back(a[dq.front()]);
        }
    }

    return ans;
}

int main() {
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    auto mx = slidingWindowExtremum<true>(a, k);
    auto mn = slidingWindowExtremum<false>(a, k);

    for (int x : mx) cout << x << ' ';
    cout << '\n';

    for (int x : mn) cout << x << ' ';
    cout << '\n';
}
```

Output:

```
3 3 5 5 6 7
-1 -3 -3 -3 3 3
```

## Complexity

- Time: `O(n)`
- Auxiliary space: `O(k)`

Each index enters the deque once and leaves it at most once, so the total number of operations is linear.

# 4. Use Case: Shortest Subarray with Sum at Least K

## Problem

Given an integer array `a` and an integer `K`, find the length of the shortest non-empty contiguous subarray whose sum is at least `K`.

Return `-1` if no such subarray exists.

Example:

```
a = [84, -37, 32, 40, 95]
K = 167

Answer: 3
Subarray: [32, 40, 95]
Sum: 167
```

Important: The array can contain negative numbers, so an ordinary sliding window does not work reliably.

We use prefix sums and a monotonic deque instead.

## Step 1: Prefix Sums

Define:

```
P[0] = 0;
P[i + 1] = P[i] + a[i];
```

The sum of the subarray `[j, i)` is:

\\[ \operatorname{sum}(j,i)=P[i]-P[j] \\]

We want:

\\[ P[i]-P[j]\ge K \\]

Rearranging:

\\[ P[j]\le P[i]-K \\]

For each right endpoint `i`, we want the largest valid `j`, because that gives the shortest subarray.

## Step 2: Maintain an Increasing Deque

The deque stores indices of prefix sums in increasing order of their values.

There are two rules.

### Rule A: Pop from the front when a valid subarray is found

```
while (!dq.empty() && P[i] - P[dq.front()] >= K) {
    ans = min(ans, i - dq.front());
    dq.pop_front();
}
```

Why?

The current subarray is valid. Record its length and discard the left endpoint.

Any future right endpoint would produce a longer subarray using that same left endpoint, so it cannot improve the answer.

### Rule B: Pop dominated prefix sums from the back

```
while (!dq.empty() && P[i] <= P[dq.back()]) {
    dq.pop_back();
}
```

Why?

Suppose `P[i] <= P[j]` and `j < i`.

For any future right endpoint `r`:

- `P[r] - P[i] >= P[r] - P[j]`.
- The subarray starting at `i` is shorter because `i > j`.

Therefore, `j` is dominated and can never produce a better answer.

## Complete C++ Implementation

```
#include <bits/stdc++.h>
using namespace std;

int shortestSubarray(const vector<int>& a, long long K) {
    int n = (int)a.size();

    // Prefix sums.
    vector<long long> P(n + 1, 0);

    for (int i = 0; i < n; i++) {
        P[i + 1] = P[i] + a[i];
    }

    deque<int> dq;  // Indices of prefix sums
    int ans = n + 1;

    for (int i = 0; i <= n; i++) {

        // Rule A: Find valid subarrays ending at i.
        while (!dq.empty() &&
               P[i] - P[dq.front()] >= K) {

            ans = min(ans, i - dq.front());
            dq.pop_front();
        }

        // Rule B: Remove dominated prefix sums.
        while (!dq.empty() &&
               P[i] <= P[dq.back()]) {
            dq.pop_back();
        }

        // Current prefix sum becomes a candidate.
        dq.push_back(i);
    }

    return (ans == n + 1 ? -1 : ans);
}

int main() {
    vector<int> a = {84, -37, 32, 40, 95};
    long long K = 167;

    cout << shortestSubarray(a, K) << '\n';
    // Output: 3
}
```

## Complexity

- Time: `O(n)`
- Space: `O(n)` for the prefix sums and deque.

Use `long long` for prefix sums to avoid integer overflow.

# 5. Common Mistakes

### 1. Storing values instead of indices

Indices let us determine whether an element has left the sliding window.

### 2. Using the wrong comparison

| Problem           | Remove from back when  |
| ----------------- | ---------------------- |
| Sliding maximum   | `a[dq.back()] <= a[i]` |
| Sliding minimum   | `a[dq.back()] >= a[i]` |
| Shortest subarray | `P[dq.back()] >= P[i]` |

### 3. Forgetting negative numbers

The ordinary two-pointer sliding window relies on predictable changes in the sum. Negative numbers break this assumption.

For shortest subarray sum problems, use prefix sums and a monotonic deque.

### 4. Forgetting to handle invalid windows

For sliding windows, validate `k`:

```
if (k <= 0 || k > n) return {};
```

### 5. Integer overflow

Use `long long` for prefix sums and sum comparisons.

# 6. OI Quick Reference

| Problem                      | Stored elements    | Order                  | Pop front when            | Pop back when                      |
| ---------------------------- | ------------------ | ---------------------- | ------------------------- | ---------------------------------- |
| Sliding maximum              | Array indices      | Decreasing values      | Index expires             | New value is greater or equal      |
| Sliding minimum              | Array indices      | Increasing values      | Index expires             | New value is smaller or equal      |
| Shortest subarray sum `>= K` | Prefix-sum indices | Increasing prefix sums | A valid subarray is found | New prefix sum is smaller or equal |

## The Three Rules to Remember

1. Maximum: Keep decreasing values; the front is the maximum.
2. Minimum: Keep increasing values; the front is the minimum.
3. Shortest subarray with sum at least `K`: Use increasing prefix sums. Pop the front when a valid subarray is found and the back when a prefix sum is dominated.

The central idea: A monotonic deque discards candidates that can never improve the answer. Each element is added and removed at most once, giving an `O(n)` algorithm.

```
```