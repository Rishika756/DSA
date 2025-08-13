class Solution {
public:
    int numTrees(int n) {
       vector<int>uniqtree(n+1 , 1);
       for(int nodes = 2 ; nodes<=n ; nodes++){
        int total = 0;
        for(int root = 1 ; root<= nodes ; root++){
            total += uniqtree[root - 1]*uniqtree[nodes - root];
        }
        uniqtree[nodes] = total;
       }
       return uniqtree[n];
    }
};