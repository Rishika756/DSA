class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i  = 0;
        int j = 0;
        while(i<word1.length() || j<word2.length()){
            if(i<word1.length()){
                result = result+word1[i];
            }
            if(j<word2.length()){
                result = result+word2[j];
            }
            i++;
            j++;
        }
        return result;
    }
};