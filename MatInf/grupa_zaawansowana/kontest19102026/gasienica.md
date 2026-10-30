# 🐛 Algorytm Gąsienica — Two Pointers / Sliding Window (C++)

## 1. Intuition — how does it work?

Imagine a caterpillar crawling along an array. It has two pointers:

- `L` (left) — the tail of the caterpillar; marks the beginning of the current window.
- `R` (right) — the head of the caterpillar; explores new elements.

The elements between `L` and `R` form a window (continuous subarray).

The idea is simple:

1. Move `R` forward to expand the window.
2. If the window violates a condition, move `L` forward until the condition is satisfied again.
3. Update the answer using the current window.
4. Repeat.

Remember: grow → shrink → process.

Example:

Array: `[2, 1, 3, 2, 4]`

Find the longest subarray with sum `<= 6`.

- `[2, 1, 3]` has sum `6`, length `3`.
- Adding `2` makes the sum `8`, so move `L` forward.
- The window becomes `[1, 3, 2]`, with sum `6`.
- The maximum length is `3`.

## 2. Basic template — C++

```
int L = 0;

for (int R = 0; R < n; R++) {
    // 1. Add a[R] to the window.

    while (/* window is invalid */) {
        // 2. Remove a[L] from the window.
        L++;
    }

    // 3. Process the valid window [L, R].
}
```

This is the general pattern. The way you add, remove, and process elements depends on the problem.

## 3. Example — longest subarray with sum

using namespace std;

int main() { vector\<int> a = {2, 1, 3, 2, 4}; int n = a.size(); long long K = 6;

int L = 0; long long sum = 0; int best = 0;

for (int R = 0; R < n; R++) { // Expand the window. sum += a[R];

// Shrink while the window is invalid. while (sum > K) { sum -= a[L]; L++; }

// Current window [L, R] is valid. best = max(best, R - L + 1); }

cout << best << '\n'; // 3 }

````

### Key operations

| Code | Meaning |
|---|---|
| `sum += a[R]` | Add the new element |
| `while (sum > K)` | Check whether the window is invalid |
| `sum -= a[L]` | Remove the leftmost element |
| `L++` | Move the left pointer |
| `R - L + 1` | Calculate the window length |
| `best = max(best, ...)` | Update the answer |

**Why `while`, not `if`?**

Removing one element may not be enough to restore the condition. Keep shrinking until the window becomes valid.

---

## 4. Common applications

### A. Longest valid subarray

Examples:
- Longest subarray with sum `<= K`.
- Longest subarray containing at most `K` distinct values.
- Longest substring without repeating characters.

### B. Shortest valid subarray

Examples:
- Shortest subarray with sum `>= K`, when the array contains positive numbers.
- Shortest window containing all required characters.

For shortest-window problems, update the answer **while the window is valid**, often before shrinking it.

### C. Counting subarrays

For certain conditions, the number of valid subarrays ending at `R` can be calculated from the current window length.

For example, if all elements are non-negative and the condition is `sum <= K`, the number of valid subarrays ending at `R` is:

```cpp
count += R - L + 1;
````

This works because every suffix of the current valid window is also valid.

### D. Two pointers on sorted arrays

A related technique uses pointers at opposite ends of a sorted array:

```
int L = 0, R = n - 1;

while (L < R) {
    int sum = a[L] + a[R];

    if (sum == K) {
        // Found a pair.
        break;
    }
    else if (sum < K) {
        L++;
    }
    else {
        R--;
    }
}
```

This is two pointers, but not a sliding window: the pointers move inward rather than maintaining a growing continuous window.

## 5. Important limitations

### When does the sum-based sliding window work?

For the standard sum-based template, non-negative elements are the key assumption.

- Expanding the window cannot decrease its sum.
- Shrinking the window cannot increase its sum.

This monotonicity makes it safe to discard elements from the left as soon as the sum exceeds `K`.

With negative elements, this logic may fail. Consider prefix sums, a monotonic deque, or another approach instead.

Also, not every sliding-window problem uses a sum. You may need to maintain:

- A frequency array or map.
- A count of distinct elements.
- A set of characters.
- Other information that can be updated efficiently as elements enter and leave.

## 6. Complexity

For the standard sliding-window template:

- Time: \\(O(n)\\)
- Extra space: \\(O(1)\\) if maintaining only a few variables; more if using a map or frequency array.

Why is it \\(O(n)\\), even with a nested `while` loop?

- `R` moves forward at most \\(n\\) times.
- `L` also moves forward at most \\(n\\) times.
- Neither pointer moves backward.

Therefore, both loops perform at most \\(O(n)\\) total pointer movements.

## 7. Problem-solving checklist

When reading a problem, ask:

1. Does it involve a continuous subarray or substring?
2. Can I maintain the window's properties efficiently?
3. Can I tell when the window is invalid?
4. Can I restore validity by moving `L` forward?
5. Is the condition monotonic enough for this strategy to be correct?

If so, sliding window may be the right approach.

## TL;DR

```
1. Move R forward.
2. Add the new element to the window.
3. While the window is invalid:
       Remove a[L].
       Move L forward.
4. Process the valid window.
5. Repeat.
```

Mental model: `R` explores, `L` repairs, and the window stores the current candidate answer.