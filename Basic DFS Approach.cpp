// Problem: Given a directed graph, for each node, find all its ancestors in the graph.

class Solution {
public:
    // Helper function to perform depth-first search (DFS) for ancestor tracking.
    void dfs(int start, int i, unordered_map<int, vector<int>>& adj, unordered_map<int, set<int>>& pa, vector<bool>& visited) {
        visited[i] = true;  // Mark the current node as visited.
        
        // Visit all neighbors of the current node.
        for (int a : adj[i]) {
            if (visited[a] == false) {  // If the neighbor has not been visited yet.
                pa[a].insert(start);    // Add the starting node to the list of ancestors of the current node.
                dfs(start, a, adj, pa, visited);  // Recursively visit the neighbor.
            }
        }
    }

    // Main function to get the ancestors of each node in the graph.
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;   // Adjacency list for the graph.
        unordered_map<int, set<int>> pa;       // A map to store ancestors of each node.
        
        // Step 1: Construct the adjacency list from the edges.
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adj[from].push_back(to);  // Add an edge from 'from' to 'to'.
        }

        // Step 2: Perform DFS for each node to find all ancestors.
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);  // Reset the visited array for each node.
            dfs(i, i, adj, pa, visited);  // Start DFS from node 'i'.
        }

        // Step 3: Prepare the final answer, converting the set of ancestors into a vector.
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            while (pa[i].size()) {
                auto it = pa[i].begin();  // Get the first element in the set of ancestors.
                ans[i].push_back(*it);    // Add the ancestor to the result vector.
                pa[i].erase(it);          // Remove the ancestor from the set to avoid duplicates.
            }
        }

        // Return the final list of ancestors for each node.
        return ans;
    }
};
