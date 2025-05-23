class Solution {
public:
    string reverseWords(string s) {
    //     int n = s.size();
    //     string ans = "";

    //     int i = 0;
    //     while (i < n && s[i] == ' ') i++; 
    //     int j = n - 1;
    //     while (j >= 0 && s[j] == ' ') j--; 

    //     string temp = "";
    //     for (; i <= j; i++) {
    //         if (s[i] != ' ') {
    //             temp += s[i];
    //         } else if (!temp.empty()) {
    //             ans = temp + (ans.empty() ? "" : " ") + ans;
    //             temp = "";
    //         }
    //     }

    //     if (!temp.empty()) {
    //         ans = temp + (ans.empty() ? "" : " ") + ans;
    //     }

    //     return ans;
    // }
    int n = s.size();
    string ans = "";
    reverse(s.begin() , s.end());
    for(int i = 0 ; i<=n ; i++){
        string word = "";
        while(i<n && s[i]!=' '){
            word+= s[i];
            i++;
        }
        reverse(word.begin() , word.end());
        if(word.size()>0){
            ans += " " + word;
        }
    }
    return ans.substr(1);
    }
};