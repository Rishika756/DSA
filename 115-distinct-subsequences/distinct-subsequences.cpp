class Solution {
public:
    int solve(string &s, string &t, int m, int n, vector<vector<int>> &dp){
        if(n == 0) return dp[m][n] = 1;
        if(m == 0) return dp[m][n] = 0;

        if(dp[m][n] != -1) return dp[m][n];

        if(s[m-1] == t[n-1]){
            return dp[m][n] = solve(s, t, m-1, n, dp) + solve(s, t, m-1, n-1, dp);
        }
        return dp[m][n] = solve(s, t, m-1, n, dp);
    }

    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));  
        return solve(s, t, m, n, dp);
    }
};
