class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0; 
        int maxi = INT_MIN; // Use INT_MIN instead of LONG_MIN

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum < 0) {
                sum = 0;
            }
        }

        return maxi;
       
    }
};