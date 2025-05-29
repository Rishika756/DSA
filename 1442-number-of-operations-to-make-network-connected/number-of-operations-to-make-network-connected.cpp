class Disjoint {
public:
    vector<int>par,sz;
    Disjoint(int n){
        par.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int findpar(int x){
        if(par[x]==x) return x;
        return par[x]=findpar(par[x]);
    }
    void UnionBySize(int x, int y){
        int xp=findpar(x),yp=findpar(y);
        if(xp==yp) return;
        if(sz[xp]>sz[yp]){
            sz[xp]+=sz[yp];
            par[yp]=xp;
        } else {
            sz[yp]+=sz[xp];
            par[xp]=yp;
        }
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        int useless=0;
        Disjoint ds(n);
        for(auto c:connections){
            int u=ds.findpar(c[0]),v=ds.findpar(c[1]);
            if(u==v){useless++; continue;}
            ds.UnionBySize(u,v);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(ds.par[i]==i) c++;
        }
        if(useless>=c-1) return c-1;
        return -1;
    }
};