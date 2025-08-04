class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(2*n);
        for(int i = 0 ; i<temp.size() ; i++){
            temp[i]  = nums[i%n];
        }
        int totalones = accumulate(nums.begin() , nums.end() , 0);
        int maxones= 0;
        int countones  = 0;
        int i = 0;
        int j = 0;
        while(j<2*n){
            if(temp[j] == 1){
            countones++;
            }
            if(j-i+1 > totalones){
            countones -= temp[i];
            i++;
            }
            maxones = max(maxones , countones);
            j++;
        }
        return totalones - maxones;
    }
};