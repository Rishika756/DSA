class Solution {
    int mod = 1e9+7;
    vector<int> PrevSmallIndex(vector<int>& arr){
        int n = arr.size();
        vector<int> prev(n);
        stack<pair<int,int>> s;  
        for(int i = 0; i < n; i++){
            int count = 1;
            while(!s.empty() && s.top().first > arr[i]){
                count += s.top().second;
                s.pop();
            }
            prev[i] = count;
            s.push({arr[i], count});
        }
        return prev;
    }

    vector<int> NextSmallIndex(vector<int>& arr){
        int n = arr.size();
        vector<int> next(n);
        stack<pair<int,int>> s; 
        for(int i = n-1; i >=0; i--){
            int count = 1;
            while(!s.empty() && s.top().first >= arr[i]){
                count += s.top().second;
                s.pop();
            }
            next[i] = count;
            s.push({arr[i], count});
        }
        return next;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = PrevSmallIndex(arr);
        vector<int> right = NextSmallIndex(arr);

        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long contrib = (1LL * arr[i] * left[i] * right[i]) % mod;
            ans = (ans + contrib) % mod;
        }

        return ans;
    }
};
