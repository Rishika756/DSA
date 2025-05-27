class Solution {
public:
    string longestPrefix(string s2) {
        int n = s2.size();
        vector<int> lps(n, 0);
        int len = 0, i = 1;

        while (i < n) {
            if (s2[i] == s2[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return s2.substr(0, lps[n - 1]);
    }
};
