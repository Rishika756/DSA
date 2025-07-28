class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();//per element 
        int m = matrix[0].size();//row
        for(int i = 0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        } 
        for(int i = 0 ; i<m ; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};