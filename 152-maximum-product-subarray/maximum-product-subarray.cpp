class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftpro = 1;
        int rightpro = 1;
        int ans = nums[0];
        for(int i = 0 ; i<nums.size() ; i++){
            leftpro = leftpro==0?1 : leftpro;
            rightpro = rightpro==0?1 : rightpro;
        
        leftpro *= nums[i];
        rightpro *= nums[nums.size()-1-i];

        ans = max(ans , max(leftpro , rightpro));
        }
        return ans ; 

    }
};

