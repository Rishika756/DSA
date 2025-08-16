class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int t) {
        int n = arr.size();
        vector<int>ans(2 , -1);
        int low = 0 ; 
        int high = n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(arr[mid]>=t){
                high = mid -1;
            }else{
                low = mid+1;
            }
            if(arr[mid] == t){
                ans[0] = mid;
            }
        }
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= t) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            if (arr[mid] == t) ans[1] = mid;
        }
        return ans;

    }
};