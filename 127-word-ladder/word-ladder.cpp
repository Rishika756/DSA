class Solution {
public:
    int ladderLength(string beginword, string end, vector<string>& wordList) {
        queue<pair<string , int>>q;
        q.push({beginword , 1});
        unordered_set<string>st(wordList.begin() , wordList.end());
        st.erase(beginword);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == end) return steps;
            for(int i = 0 ; i<word.size() ; i++){
            char ori = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word , steps+1});
                    }
                }
                word[i] = ori;
            }
        }
        return 0;
    }
};