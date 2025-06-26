class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string result = "";
        sort(strs.begin() , strs.end());
        string first = strs[0];
        string second = strs[strs.size()-1];
        for(int i = 0 ; i<first.length() && i<second.length() ; i++){
            if(first[i]!=second[i]){
                break;
            }else{
                result += first[i];
            }
        }
        return result;

    }
};