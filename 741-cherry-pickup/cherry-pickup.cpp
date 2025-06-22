class Solution {
public:
    int solve(vector<vector<int>>& grid, int r1, int c1, int r2, int c2, vector<vector<vector<vector<int>>>> &dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (r1 >= n || c1 >= m || r2 >= n || c2 >= m) return -1e8;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e8;
        if (r1 == n - 1 && c1 == m - 1) return grid[r1][c1];
        if (r2 == n - 1 && c2 == m - 1) return grid[r2][c2];
        if (dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
        int cherries = (r1 == r2 && c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
        int a = solve(grid, r1 + 1, c1, r2 + 1, c2, dp); 
        int b = solve(grid, r1, c1 + 1, r2, c2 + 1, dp); 
        int c = solve(grid, r1 + 1, c1, r2, c2 + 1, dp); 
        int d = solve(grid, r1, c1 + 1, r2 + 1, c2, dp); 
        cherries += max({a, b, c, d});
        return dp[r1][c1][r2][c2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));
        return max(0, solve(grid, 0, 0, 0, 0, dp));
    }
};
