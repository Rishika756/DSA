class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int ts = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            left += nums[i];
            int right = ts - left;
            if ((left % 2) == (right% 2)) {
                count++;
            }
        }

        return count;
    }
};
