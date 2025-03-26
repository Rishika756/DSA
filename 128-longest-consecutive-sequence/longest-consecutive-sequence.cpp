class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        unordered_set<int>seen;
        if(nums.size()==0) return 0;
        for(int num : nums){
            seen.insert(num);
        }
        for(auto it:seen){
            int count = 1;
            int x = it;
            if(seen.find(x-1)==seen.end()){
                while(seen.find(x+1)!=seen.end()){
                    x=x+1;
                    count++;
                } 
                longest=max(longest,count);
            }
        }
        return longest;
    }
};