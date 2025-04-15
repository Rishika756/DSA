class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                gola = i;
                break;
            }
        }
        if(gola != -1) {
            int swapping = -1;
            for(int j = n - 1; j > gola; j--) {
                if(nums[j] > nums[gola]) {
                    swapping = j;
                    break;
                }
            }
            swap(nums[gola], nums[swapping]);
        }
        reverse(nums.begin() + gola + 1, nums.end());
    }
};