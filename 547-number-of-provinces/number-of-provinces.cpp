class Solution {
public:
    void dfs(vector<int> adj[], int u, vector<bool> &vis) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(adj, v, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected) {
        int V = isConnected.size();
        vector<bool> vis(V, false);
        vector<int> adj[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(adj, i, vis);
                count++;
            }
        }

        return count;
    }
};