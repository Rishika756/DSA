class Solution {
public:
    string decodeString(string s) {
        stack<int> numberStack;
        stack<string> stringStack;
        string currentString = "";
        int currentNumber = 0;

        for(char c:s){
            if(isdigit(c)){
                currentNumber = currentNumber * 10 + (c -'0');
            }else if(c == '['){
                numberStack.push(currentNumber);
                stringStack.push(currentString);
                currentString = "";
                currentNumber = 0;
            }else if(c == ']'){
                int repeatedTimes = numberStack.top(); numberStack.pop();
                string previousString = stringStack.top(); stringStack.pop();
                string repeatedString = "";
                for (int i = 0; i < repeatedTimes; ++i) {
                    repeatedString += currentString;
                }
                currentString = previousString + repeatedString;

            }else {
                currentString += c;
            }
        }
        return currentString;
    }
};