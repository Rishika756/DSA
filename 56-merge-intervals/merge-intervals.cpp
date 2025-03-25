class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 0;
        int j = 0 ;
        if(n==0){
            return {};
        }
        if(n==1){
           return {intervals[0]};
        }
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        for( i = 1 ; i<n ; i++){
                
                    vector<int>&back = result.back();

                    if(intervals[i][0] <= back[1]){
                        back[1] = max(intervals[i][1] ,back[1]);
                    }else{
                        result.push_back(intervals[i]);
                    }
                
            
        }
        return result;
    }
};