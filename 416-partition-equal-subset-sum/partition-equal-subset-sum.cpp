class Solution {
public:
bool helper(int i , int t , int s ,vector<int>& nums , vector<vector<int>>&dp){
    if(s>t) return false;
    if(i == nums.size()) return s == t;
    if(dp[i][s] != -1) return dp[i][s];
    bool take = helper(i+1 , t , s+nums[i] , nums , dp);
    bool ntake = helper(i+1 , t , s , nums , dp);
    return dp[i][s] = take || ntake;
}
    bool canPartition(vector<int>& nums) {
        int ts = accumulate(nums.begin() , nums.end() , 0);
        if(ts%2 != 0) return false;
        int t = ts/2;
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(t+1 , -1));
        return helper(0 , t , 0 , nums , dp);
    }
};