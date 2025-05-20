class SGTree{
    vector<int> seg;
public:
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void buildSeg(int ind, int low, int high, vector<int>& arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        buildSeg(2*ind+1, low, mid, arr);
        buildSeg(2*ind+2, mid+1, high, arr);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }
    
    int query(int ind, int low, int high, int l, int r){
        //No Overlap -> (l,r) < (low,high) || (low,high) < (l,r)
        if(r < low || l > high) return 0;
    
        //Complete Overlap -> (l <= low && high <= r)
        if(l <= low && high <= r) return seg[ind];
    
        //Partial Overlap ->
        int mid = (low + high)/2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high,l, r);
        return max(left, right);
    }
    
    void update(int ind, int low, int high, int i, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }
        int mid = (low + high)/2;
        if(i <= mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }
};



class Solution {
    int res = 0;
    void find(int val, SGTree& seg, int n){
        int indx = -1;
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            int mx = seg.query(0, 0, n-1, 0 , mid);

            if(mx >= val){
                indx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(indx != -1){
            seg.update(0, 0, n-1,indx, 0);
        }
        else{
            res++;
        }
        return;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SGTree seg(n);
        seg.buildSeg(0, 0, n-1, baskets);
        for(int i = 0; i < n; i++){
            find(fruits[i], seg, n);
        }
        return res;
    }
};