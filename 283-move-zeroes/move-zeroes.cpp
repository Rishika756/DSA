class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int isp = 0;
        // for(int i = 0 ; i<nums.size() ; i++){
        //     if(nums[i]!=0){
        //         nums[isp] = nums[i];
        //         isp++;
        //     }
        // }
        // while(isp < nums.size()){
        //     nums[isp++] = 0;
        // }
        int isp = 0;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            if(nums[i]!=0){
                nums[isp] = nums[i];
                isp++;
            }
        }
        while(isp<n){
            nums[isp++] = 0;
        }
    }
};