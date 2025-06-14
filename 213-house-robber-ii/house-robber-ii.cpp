class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < n - 1; i++) {
            temp1.push_back(nums[i]);  
        }
        for (int i = 1; i < n; i++) {
            temp2.push_back(nums[i]);  
        }

        int loot1 = helper(temp1);
        int loot2 = helper(temp2);
        return max(loot1, loot2);
    }
};
