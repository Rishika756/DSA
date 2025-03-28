class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        
        for (char c : s) {
            if (c == '(') {
                st.push(')');
            } else if (c == '[') {
                st.push(']');
            } else if (c == '{') {
                st.push('}');
            } 
            else {
                if (st.empty() || st.top() != c) {
                    return false;  
                }
                st.pop(); 
            }
        }
        
        return st.empty(); 
    }
};