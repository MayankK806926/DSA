class DisjointSet{
  vector<int> rank,parent,size;
public:
  DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1,0);
    size.resize(n+1,0);
    for(int i=0;i<=n;++i){
      parent[i]=i;
      size[i]=1;
    }
  }

  int findUParent(int node){
    if(node==parent[node]) return node;
    return parent[node]=findUParent(parent[node]);
  }

  void UnionByRank(int u,int v){
    int ulp_u=findUParent(u);
    int ulp_v=findUParent(v);
    if(ulp_u == ulp_v) return ;
    if(rank[ulp_v] < rank[ulp_u]){
      parent[ulp_v]=ulp_u;
    }else if(rank[ulp_u] < rank[ulp_v]){
      parent[ulp_u]=ulp_v;
    }else{
      parent[ulp_v]=ulp_u;
      rank[ulp_u]++;
    }
  }

  void unionBySize(int u,int v){
    int ulp_u=findUParent(u);
    int ulp_v=findUParent(v);
    if(ulp_u == ulp_v) return;
    if(size[ulp_u] < size[ulp_v]){
      parent[ulp_u]=ulp_v;
      size[ulp_v]+=size[ulp_u];
    }else{
      parent[ulp_v]=ulp_u;
      size[ulp_u]+=size[ulp_v];
    }
  }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int,pair<int,int>>> tup;
        for(auto &it:edges){
            tup.push_back({it[2],{it[0],it[1]}});
        }
        DisjointSet ds(V);
        sort(tup.begin(),tup.end());
        int mstsum=0;
        for(auto &it:tup){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUParent(u) != ds.findUParent(v)){
                mstsum+=wt;
                ds.unionBySize(u,v);
            }
        }
        
        return mstsum;
    }
};
