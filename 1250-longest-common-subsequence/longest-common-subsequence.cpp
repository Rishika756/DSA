class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n = text1.size() + 1;
      int m = text2.size() + 1;
      vector<vector<int>> grid(n, vector<int>(m, 0));

      for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            if(text1[i-1] == text2[j-1]){
                grid[i][j] = 1 + grid[i-1][j-1];
            }else{
                grid[i][j] = max(grid[i-1][j] , grid[i][j-1]);
            }
        }
      }
      return grid[n-1][m-1];  
    }
};