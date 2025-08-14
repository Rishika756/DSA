class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int , int>mp;
        int maxfreq = 0;
        for(int num : nums){
            maxfreq = max(maxfreq , ++mp[num]);
        }
        int result = 0;
        for(auto it : mp){
            if(it.second == maxfreq){
                result += it.second;
            }
        }
        return result;
    }
};