class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomleft, vector<vector<int>>& topright) {
        long long maxi = 0;
        int n = bottomleft.size();
        for(int i = 0 ; i<n;  i++){
            for(int j = i+1 ; j<n ; j++){
                int x1 = max(bottomleft[i][0] , bottomleft[j][0]);
                int y1 = max(bottomleft[i][1] , bottomleft[j][1]);
                int x2 = min(topright[i][0] , topright[j][0]);
                int y2 = min(topright[i][1] , topright[j][1]); 
                if(x1<x2 && y1<y2){
                    long long side = min(x2-x1 , y2-y1);
                    maxi = max(maxi , side*side);
                }
            }
        }
        return maxi;
    }
};