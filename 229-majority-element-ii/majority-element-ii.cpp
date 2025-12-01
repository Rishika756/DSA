class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return{};
        unordered_map<int , int>freq;
        vector<int>res;
        for(int num:nums){
            freq[num]++;
        }
        for(auto &pair : freq){
            if(pair.second>n/3){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};