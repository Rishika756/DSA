class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int li = 0;
        int ri = nums.size() -1;
        while(li<ri){
            if(nums[li] + nums[ri] < k){
                li++;
            }
            else if(nums[li] + nums[ri] > k){
                ri--;
            }
            else{
                li++;
                ri--;
                ans++;
            }
        }
        return ans;


    }
};