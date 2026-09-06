// Lowest Common Ancestor (LCA) using Binary Lifting
//
// Complexity:
// Preprocessing: O(N log N)
// Single LCA query: O(log N)
//
// Idea:
// Instead of moving one parent at a time:
//
// node -> parent -> grandparent -> ...
//
// we precompute jumps:
//
// jp[v][0] = 2^0-th ancestor (parent)
// jp[v][1] = 2^1-th ancestor (2 levels up)
// jp[v][2] = 2^2-th ancestor (4 levels up)
// jp[v][3] = 2^3-th ancestor (8 levels up)
// ...
//
// This lets us "teleport" upwards very quickly.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cmath>
using namespace std;

// Maximum number of nodes.
//
// (1 << 19) = 524288
//
// We use 19 because:
//
// 2^19 > 500000
//
// So any node can reach the root using at most
// 19 different powers of two.
const int maxn = (1 << 19);

// dist[v]
// = depth of vertex v
//
// Example:
//
//      1
//     / \
//    2   3
//   /
//  4
//
// dist[1] = 1
// dist[2] = 2
// dist[4] = 3
//
int dist[maxn];

// jp[v][i]
//
// "jump pointer"
//
// jp[v][i] means:
//
// If I start at node v and move
// 2^i levels upward,
// where do I land?
//
// Example:
//
// jp[10][0] = parent of 10
// jp[10][1] = grandparent of 10
// jp[10][2] = ancestor 4 levels above
// jp[10][3] = ancestor 8 levels above
//
int jp[maxn][19];

// Adjacency list representation of the tree.
vector<int> tree[maxn];

int n;

//////////////////////////////////////////////////////////
// DFS PREPROCESSING
//////////////////////////////////////////////////////////

void dfs(int v, int p)
{
    //----------------------------------------------------
    // Store depth
    //----------------------------------------------------
    //
    // Parent depth + 1
    //
    // Example:
    //
    // root depth = 1
    // child depth = 2
    // grandchild depth = 3
    //
    dist[v] = dist[p] + 1;

    //----------------------------------------------------
    // First jump pointer
    //----------------------------------------------------
    //
    // 2^0 = 1
    //
    // So jp[v][0] is simply the parent.
    //
    jp[v][0] = p;

    //----------------------------------------------------
    // Build larger jumps
    //----------------------------------------------------
    //
    // Formula:
    //
    // jp[v][i]
    // = ancestor 2^i above v
    //
    // To get there:
    //
    // first go 2^(i-1)
    // then another 2^(i-1)
    //
    // Example:
    //
    // jp[v][2]
    // = ancestor 4 above
    //
    // jump 2 above:
    // jp[v][1]
    //
    // then another 2 above:
    // jp[jp[v][1]][1]
    //
    for (int i = 1; i < 19; i++)
    {
        jp[v][i] = jp[jp[v][i - 1]][i - 1];
    }

    //----------------------------------------------------
    // DFS children
    //----------------------------------------------------
    for (int u : tree[v])
    {
        // Ignore edge back to parent
        if (u != p)
        {
            dfs(u, v);
        }
    }
}

//////////////////////////////////////////////////////////
// LCA QUERY
//////////////////////////////////////////////////////////

int lca(int a, int b)
{
    //----------------------------------------------------
    // STEP 1:
    // Make sure a is the deeper node.
    //----------------------------------------------------
    //
    // This makes later code easier.
    //
    if (dist[a] < dist[b])
        swap(a, b);

    //----------------------------------------------------
    // STEP 2:
    // Lift a until both nodes
    // are on the same depth.
    //----------------------------------------------------
    //
    // Example:
    //
    // depth(a) = 13
    // depth(b) = 5
    //
    // difference = 8
    //
    // Jump a upward by 8.
    //
    // We try largest jumps first.
    //
    for (int i = 18; i >= 0; i--)
    {
        //------------------------------------------------
        // If jumping 2^i upward still keeps us
        // at or above depth of b,
        // then perform the jump.
        //------------------------------------------------
        //
        // Example:
        //
        // depth(a)=20
        // depth(b)=8
        //
        // If jp[a][3] has depth 12,
        // then we can safely jump.
        //
        if (dist[jp[a][i]] >= dist[b])
        {
            a = jp[a][i];
        }
    }

    //----------------------------------------------------
    // If they became equal,
    // then b was ancestor of a.
    //----------------------------------------------------
    //
    // Example:
    //
    //     1
    //    /
    //   2
    //  /
    // 3
    //
    // LCA(3,2)=2
    //
    if (a == b)
        return a;

    //----------------------------------------------------
    // STEP 3:
    // Lift BOTH nodes upward together.
    //----------------------------------------------------
    //
    // Goal:
    // Keep them different,
    // but move them as high as possible.
    //
    // We try biggest jumps first.
    //
    for (int i = 18; i >= 0; i--)
    {
        //------------------------------------------------
        // If the 2^i ancestors differ,
        // then LCA is above them.
        //
        // So jump both.
        //------------------------------------------------
        //
        // Example:
        //
        // a -----\
        //          > LCA
        // b -----/
        //
        // If their 8-level ancestors
        // are different,
        // we can safely move up 8.
        //
        if (jp[a][i] != jp[b][i])
        {
            a = jp[a][i];
            b = jp[b][i];
        }
    }

    //----------------------------------------------------
    // Now:
    //
    // a and b are direct children
    // of the LCA.
    //
    // So parent of either one
    // is the answer.
    //----------------------------------------------------
    return jp[a][0];
}