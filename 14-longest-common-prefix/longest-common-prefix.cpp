class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        if(arr.empty()){
            return "";
        }
        string res = "";
        sort(arr.begin() , arr.end());
        string first = arr[0];
        string last = arr[arr.size()-1];
        for(int i = 0 ;i<first.length() && i<last.length() ; i++){
            if(first[i] == last[i]){
                res += first[i];
            }else{
                break;
            }
        }
        return res;
    }
};