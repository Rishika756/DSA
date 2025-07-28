class Solution {
public:
    void helper(int open, int close, vector<string>& ans, string str) {
        if (open == 0 && close == 0) {
            ans.push_back(str);
            return;
        }

        if (open > 0) {
            helper(open - 1, close, ans, str + '(');
        }

        if (close > open) {
            helper(open, close - 1, ans, str + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, n, ans, "");
        return ans;
    }
};
