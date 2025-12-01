class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        for(int num: nums){
            if(seen.find(num) != seen.end()){
                return num;
            }else{
                seen.insert(num);
            }
        }
        return -1;
    }
};