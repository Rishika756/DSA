class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int n = nums.size();
        int idx1 = -1, idx2 = -1;  // initialize to -1 in case not found
        int i = 0, j = n - 1;

        while (i <= j) {
            if (nums[i] == target && idx1 == -1) {
                idx1 = i;
            } else if (idx1 == -1) {
                i++;
            }

            if (nums[j] == target && idx2 == -1) {
                idx2 = j;
            } else if (idx2 == -1) {
                j--;
            }

            if (idx1 != -1 && idx2 != -1) {
                break;
            }
        }

        return {idx1, idx2};
    }
};