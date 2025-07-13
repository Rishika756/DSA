class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, 
             int newcolor, int initialcolor, vector<int>& delrow, vector<int>& delcol) {
        ans[row][col] = newcolor;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                image[nrow][ncol] == initialcolor && ans[nrow][ncol] != newcolor) {
                dfs(nrow, ncol, ans, image, newcolor, initialcolor, delrow, delcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, color, inicolor, delrow, delcol);
        return ans;
    }
};
