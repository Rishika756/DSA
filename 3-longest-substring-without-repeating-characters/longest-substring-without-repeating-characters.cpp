class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen;
        int i = 0 ; int j = 0 ; int maxlength = 0;
        while(j<s.size()){
            if(seen.find(s[j]) == seen.end()){
                seen.insert(s[j]);
                int length = j-i+1;
                maxlength = max(maxlength , length);
                j++;
            }else{
                seen.erase(s[i]);
                i++;
            }
        }
        return maxlength;
    }
};