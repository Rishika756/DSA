class Solution {
public:
void allsubsets(vector<int> &nums , vector<int> &ans , int i ,  vector<vector<int>> &result){
    if(i==nums.size()){
        result.push_back({ans});
        return;
    }
    ans.push_back(nums[i]);
    allsubsets(nums , ans , i+1 , result);
    ans.pop_back();
    allsubsets(nums , ans , i+1 , result);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ans;
        allsubsets(nums , ans , 0 , result);
        return result;
    }
};