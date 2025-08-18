class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        string result = "";
        while (!pq.empty()) {
            int currcount = pq.top().first;
            char currchar = pq.top().second;
            pq.pop();
            if (result.size() >= 2 && result[result.size()-1] == currchar && result[result.size()-2] == currchar) {
                if (pq.empty()) break; 
                int nextcount = pq.top().first;
                char nextchar = pq.top().second;
                pq.pop();
                result.push_back(nextchar);
                nextcount--;
                if (nextcount > 0) {
                    pq.push({nextcount, nextchar});
                }
                pq.push({currcount, currchar}); 
            } else {
                result.push_back(currchar);
                currcount--;
                if (currcount > 0) {
                    pq.push({currcount, currchar});
                }
            }
        }
        return result;
    }
};
