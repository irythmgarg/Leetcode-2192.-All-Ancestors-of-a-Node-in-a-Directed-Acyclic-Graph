// Problem: For a Directed Acyclic Graph (DAG), find all ancestors of each node.
// This approach uses Topological Sorting (Kahn's Algorithm) followed by ancestor propagation.

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;         // Adjacency list representation
        vector<int> indegree(n, 0);                  // Indegree array for Kahn's algorithm
        vector<int> topological;                     // Stores nodes in topological order

        // Step 1: Build the graph and compute indegrees
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            adj[from].push_back(to);
            indegree[to]++;
        }

        // Step 2: Perform Kahn's Algorithm (BFS) for topological sorting
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);  // Push nodes with no incoming edges
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topological.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Use topological order to propagate ancestors
        vector<set<int>> ans(n);  // Using set to keep unique ancestors

        for (int node : topological) {
            for (int neighbor : adj[node]) {
                ans[neighbor].insert(node);                            // Add current node as ancestor
                ans[neighbor].insert(ans[node].begin(), ans[node].end()); // Add ancestors of current node
            }
        }

        // Step 4: Convert each set to a vector
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = vector<int>(ans[i].begin(), ans[i].end());
        }

        return result;
    }
};
