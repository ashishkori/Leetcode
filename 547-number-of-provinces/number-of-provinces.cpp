class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        if (visited[i]) return;  // Already visited
        visited[i] = true;
        int n = isConnected.size();
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j]) {
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;  // New province found
                dfs(isConnected, visited, i);
            }
        }
        return ans;
    }
};