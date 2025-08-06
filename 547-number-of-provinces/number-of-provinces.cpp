class Solution {
public:
    void dfs(vector<vector<int>>& adjList, vector<bool>& vis, int idx) {
        vis[idx] = true;
        for(int neighbor : adjList[idx]) {
            if(!vis[neighbor]) {
                dfs(adjList, vis, neighbor);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n + 1);  // 1-based indexing
        vector<bool> vis(n + 1, false);

        // Build adjacency list with 1-based indexing
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjList[i + 1].push_back(j + 1);
                }
            }
        }

        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                dfs(adjList, vis, i);
                cnt++;
            }
        }

        return cnt;
    }
};
