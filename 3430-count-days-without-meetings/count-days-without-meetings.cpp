class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        int lastend = 0 ; 
        int count = 0;
        for(auto meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];

            if(start > lastend){
                count += start - lastend -1;
            }
            lastend = max(end , lastend);
        }
        if(lastend < days){
            count += days-lastend;
        }
        return count;
    }
};