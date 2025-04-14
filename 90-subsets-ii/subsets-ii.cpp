class Solution {
public:
    vector<vector<int>> result;

    void solve(int i, vector<int>& nums, vector<int>& temp) {
        result.push_back(temp);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) continue; 
            temp.push_back(nums[j]);
            solve(j + 1, nums, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end()); 
        solve(0, nums, temp);
        return result;
    }
};
