class Solution {
public:
    long long smallestNumber(long long num) {
        string s=to_string(num);
        if(s[0]=='-'){
             sort(s.begin()+1, s.end(), greater<char>());
             return stoll(s);
        }
        sort(s.begin(),s.end());
        if(s[0]!='0'){
            return stoll(s);
        }
        
        for(int i=1;i<s.length();i++){
            if(s[i]!='0'){
                swap(s[0],s[i]);
                return stoll(s);
            }
        }
        return 0;
    }
};