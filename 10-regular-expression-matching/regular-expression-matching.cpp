class Solution {
public:
bool solve(int i , int j , string &s , string&p , vector<vector<int>>dp){
    if(i<0 && j<0) return true;
    if(j<0) return false;
    if(i<0){
        while(j>=0){
            if(p[j]=='*') j -= 2;
            else return false;
        }
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == p[j] || p[j]=='.'){
        return dp[i][j] = solve(i-1 , j-1 , s , p , dp);
    }
    if(p[j] == '*'){
        if (j == 0) return dp[i][j] = false;
        if (p[j - 1] == s[i] || p[j - 1] == '.') {
                return dp[i][j] = solve(i - 1, j, s, p, dp) || solve(i, j - 2, s, p, dp);
            } else {
                return dp[i][j] = solve(i, j - 2, s, p, dp);
            }
    }
    return dp[i][j] = false;
}
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        return solve(n-1 , m-1 , s , p , dp);
    }
};