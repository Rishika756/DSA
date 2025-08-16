class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> prefixCount;
        prefixCount[0] = 1;          

        long long sum = 0;
        int count = 0;

        for (int x : nums) {
            sum += x;
            auto it = prefixCount.find(sum - k);
            if (it != prefixCount.end()) {
                count+= it->second;  
            }
            prefixCount[sum]++;       
        }
        return count;
    }
};
