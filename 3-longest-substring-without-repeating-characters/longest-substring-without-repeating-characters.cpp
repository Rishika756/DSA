class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> seen;
        int length = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            while (seen.find(s[right]) != seen.end()) { 
                seen.erase(s[left]); 
                left++;
            }
            seen.insert(s[right]); 
            length = max(length, right - left + 1);
        }
        return length;
    
    }
};