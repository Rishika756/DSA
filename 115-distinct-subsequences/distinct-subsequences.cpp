class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==t[j]){
            dp[i][j] = solve(s , t , i-1 , j-1 , dp) + solve(s , t , i-1 , j , dp);
        }
        else{
            dp[i][j] = solve(s , t , i-1 , j , dp);
        }
        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int m = s.length(); 
        int n = t.length();
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , -1));
        return solve( s, t, m-1 , n-1 , dp);
    }
};
