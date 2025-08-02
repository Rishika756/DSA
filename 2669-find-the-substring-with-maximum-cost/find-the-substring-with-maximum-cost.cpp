class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char , int>mp;
        for(int i = 0 ; i<26 ; i++){
            mp[i+'a'] = i+1;
        }
        for(int i = 0 ; i<chars.size() ; i++){
            mp[chars[i]] = vals[i];
        }
        int end = 0 , res = 0 , currsum = 0;
        while(end < s.size()){
            currsum += mp[s[end++]];
            if(currsum<0){
                currsum = 0;
            }
            res = max(res , currsum);
        } 
        return res;
    }
};