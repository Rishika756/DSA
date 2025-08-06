class Solution {
public:
void dfs(vector<vector<int>>&ans , vector<vector<int>>& image , int row , int col , int &color , int &icolor , vector<int>&drow, vector<int>&dcol){
    ans[row][col] = color;
    int n = image.size();
    int m = image[0].size();
    for(int i = 0 ; i<4 ; i++){
        int nr = row + drow[i];
        int nc = col + dcol[i];
        if(nr >=0 && nr<n && nc >= 0 && nc < m && image[nr][nc] == icolor && ans[nr][nc] != color){
            dfs(ans, image, nr, nc, color, icolor, drow, dcol);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int icolor = image[sr][sc];
        vector<vector<int>>ans = image;
        vector<int>drow = {-1 , 0 , 1 , 0};
        vector<int>dcol = {0 , 1 , 0 , -1};
        dfs(ans , image , sr , sc , color , icolor , drow , dcol);
        return ans;
    }
};