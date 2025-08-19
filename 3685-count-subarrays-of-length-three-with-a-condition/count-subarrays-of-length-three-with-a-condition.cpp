class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for(int i = 1 ;i<n-1 ; i++){
            if(arr[i] == 2*(arr[i-1] + arr[i+1])){
                res++;
            }
        }
        return res;
    }
};