class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];

    bool solve(vector<int>& stones, int csi, int pj) {
        if (csi == n - 1) {
            return true;
        }
        if (t[csi][pj] != -1) {
            return t[csi][pj];
        }

        bool result = false;
        for (int nj = pj - 1; nj <= pj + 1; nj++) {
            if (nj > 0) {
                int nextStone = stones[csi] + nj;
                if (mp.find(nextStone) != mp.end()) {
                    result = result || solve(stones, mp[nextStone], nj);
                }
            }
        }
        return t[csi][pj] = result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] != 1) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        memset(t, -1, sizeof(t));
        return solve(stones, 1, 1); 
    }
};
