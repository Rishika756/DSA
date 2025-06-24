class Solution {
public:
    bool checkValidString(string s) {
        int minopen = 0; 
        int maxopen = 0;
        for (char it : s) {
            if (it == '(') {
                minopen++;
                maxopen++;
            } else if (it == ')') {
                minopen = max(0, minopen - 1);
                maxopen--;
            } else { 
                minopen = max(0, minopen - 1);
                maxopen++;
            }
            if (maxopen < 0) return false;
        }
        return minopen == 0;
    }
};
