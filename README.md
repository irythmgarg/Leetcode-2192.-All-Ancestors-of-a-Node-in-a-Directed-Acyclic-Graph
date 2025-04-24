# Leetcode-2192.-All-Ancestors-of-a-Node-in-a-Directed-Acyclic-Graph
# Get Ancestors of Each Node - Multiple Approaches

This repository provides three different approaches to solve the problem of finding all **ancestors** of each node in a **Directed Acyclic Graph (DAG)**.

---

## Problem Statement
Given a DAG with `n` nodes labeled from `0` to `n - 1`, and a list of directed edges, return a list where each element `i` contains all ancestors of node `i` in **ascending order**.

---

## 🔍 Approaches Covered

### ✅ Approach 1: DFS with Forward Graph (Original Version)
- Build the graph as usual.
- For each node, perform DFS and mark all reachable nodes.
- Insert the source node into each reachable node's ancestor set.
- **Time Complexity:** O(n^2) worst case

### ✅ Approach 2: DFS with Reversed Graph
- Reverse the graph direction.
- For each node, perform DFS and collect reachable nodes.
- This essentially finds ancestors by checking which nodes can reach the current node.
- **Time Complexity:** O(n^2) worst case

### ✅ Approach 3: Topological Sort + Propagation (Kahn’s Algorithm)
- Perform topological sort using Kahn’s algorithm.
- Propagate ancestor information from each node to its neighbors.
- Leverages the DAG property and ensures a more optimal propagation.
- **Time Complexity:** O(V + E + A), where A is the total number of ancestor relations

---

## 🧠 Comparison
| Approach | Graph Build | Traversal | Data Structure | Space | Time |
|----------|-------------|-----------|----------------|-------|------|
| DFS (Forward) | Normal     | DFS       | `set + visited`| O(n²) | O(n²)|
| DFS (Reverse) | Reversed   | DFS       | `set + visited`| O(n²) | O(n²)|
| Topological    | Normal     | Kahn's + Propagation | `set`        | O(n²) | O(V + E + A) |

---

## ✅ Example
**Input:**
```cpp
n = 6
edges = [[0,3],[0,4],[1,3],[2,4],[2,5]]
```
**Output:**
```cpp
[
 [],     // Node 0 has no ancestors
 [],     // Node 1 has no ancestors
 [],     // Node 2 has no ancestors
 [0,1],  // Node 3 has ancestors 0 and 1
 [0,2],  // Node 4 has ancestors 0 and 2
 [2]     // Node 5 has ancestor 2
]
```

---

## 🤝 Contributions
Feel free to fork, add new methods or optimizations, and make pull requests!

---


Happy Coding! 🚀

