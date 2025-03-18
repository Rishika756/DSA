class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minwindow = INT_MAX;
        int currentsum = 0;

        int low = 0 , high = 0;
        while(high<nums.size()){
            currentsum += nums[high];
            high++;
            while(currentsum >= target){
                int windowsize = high  - low;
                minwindow = min(windowsize , minwindow);

                currentsum -= nums[low];
                low++;
            }
        }
        return minwindow == INT_MAX ? 0 : minwindow;
    }
};