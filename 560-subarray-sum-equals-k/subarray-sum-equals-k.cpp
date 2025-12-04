class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long , int>pfsum;
        pfsum[0] = 1;
        long long sum = 0;
        int count = 0;
        for(int x : nums){
            sum += x;
            auto it = pfsum.find(sum-k);
            if(it != pfsum.end()){
                count += it->second;
            }
            pfsum[sum]++;
        }
        return count;
    }
};
