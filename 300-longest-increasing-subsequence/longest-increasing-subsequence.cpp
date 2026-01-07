class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 1);  

        for(int i = 1 ; i < n; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j]){
                    if(arr[j] + 1 > arr[i]){
                        arr[i] = arr[j] + 1;
                    }
                }
            }
        }

        int maxLen = 0;
        for(int i = 0 ; i < n ; i++){
            maxLen = max(maxLen, arr[i]);
        }
        return maxLen;
    }
};
