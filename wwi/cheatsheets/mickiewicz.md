Imagine you have a toy tree made of wooden sticks and beads.

The problem asks us to find the **biggest stick** on the path between any two beads! If we pick the same bead twice, the answer is just `0`.

Since there are a lot of questions, we use a trick called **Binary Lifting** (also called LCA / Lowest Common Ancestor). It lets us jump up the tree in power-of-two steps ($1, 2, 4, 8, \dots$) so we can find the biggest stick super fast!

---

### Python Code (With Tons of Comments)

```python
import sys

# Increase recursion depth just in case the tree is like a long straight line
sys.setrecursionlimit(1000000)

def solve():
    # Read all input at once from standard input
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)
    
    # Read the number of beads (vertices)
    n = int(next(iterator))

    # adj[u] will store pairs: (neighbor, weight_of_stick)
    adj = [[] for _ in range(n + 1)]
    
    # Read the n - 1 sticks connecting the beads
    for _ in range(n - 1):
        u = int(next(iterator))
        v = int(next(iterator))             
        w = int(next(iterator))
        adj[u].append((v, w))
        adj[v].append((u, w))

    # LOG2 is the maximum number of jumps up we ever need to consider (2^19 > 500,000)
    LOG2 = 20

    # depth[u] will store how far bead 'u' is from the root bead (bead 1)
    depth = [0] * (n + 1)

    # up[u][j] stores the (2^j)-th parent of bead 'u'
    up = [[0] * LOG2 for _ in range(n + 1)]

    # max_edge[u][j] stores the maximum stick weight on the path from 'u' to its (2^j)-th parent
    max_edge = [[0] * LOG2 for _ in range(n + 1)]

    # We use DFS (Depth-First Search) to fill in immediate parents and depths
    # We use a stack instead of recursion to avoid crashing memory on huge trees
    stack = [(1, 0, 0, 0)]  # (current_node, parent_node, stick_weight_to_parent, current_depth)
    
    # Post-order tracking to compute binary lifting table after visiting children
    visited_order = []

    while stack:
        u, p, w, d = stack.pop()
        depth[u] = d
        up[u][0] = p
        max_edge[u][0] = w
        visited_order.append(u)

        for v, weight in adj[u]:
            if v != p:  # Don't go back up to parent
                stack.append((v, u, weight, d + 1))

    # Fill in the binary lifting tables using Dynamic Programming!
    # A jump of size 2^j is just two jumps of size 2^(j-1).
    for j in range(1, LOG2):
        for u in range(1, n + 1):
            parent = up[u][j - 1]
            up[u][j] = up[parent][j - 1]
            # The max stick in a 2^j jump is the max of the first half and second half
            max_edge[u][j] = max(max_edge[u][j - 1], max_edge[parent][j - 1])

    # Helper function to answer one query: find max stick between 'u' and 'v'
    def query(u, v):
        # Rule 1: If it's the exact same bead, distance/max stick is 0
        if u == v:
            return 0

        ans = -float('inf')

        # Step 1: Make sure 'u' is the deeper node in the tree
        if depth[u] < depth[v]:
            u, v = v, u

        # Step 2: Lift 'u' up so both beads are at the same depth level
        for j in range(LOG2 - 1, -1, -1):
            if depth[u] - (1 << j) >= depth[v]:
                ans = max(ans, max_edge[u][j])
                u = up[u][j]

        # If 'v' was an ancestor of 'u', we are already done!
        if u == v:
            return ans

        # Step 3: Lift both nodes up together until right below their common parent
        for j in range(LOG2 - 1, -1, -1):
            if up[u][j] != up[v][j]:
                ans = max(ans, max_edge[u][j])
                ans = max(ans, max_edge[v][j])
                u = up[u][j]
                v = up[v][j]

        # Take the final jump to their common parent
        ans = max(ans, max_edge[u][0])
        ans = max(ans, max_edge[v][0])

        return ans

    # Process all queries until we encounter -1
    output = []
    while True:
        try:
            u = int(next(iterator))
            if u == -1:
                break
            v = int(next(iterator))
            output.append(str(query(u, v)))
        except StopIteration:
            break

    # Print all results separated by new lines
    print('\n'.join(output))

if __name__ == '__main__':
    solve()

```