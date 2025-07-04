#include<bits/stdc++.h>
usinng namespace std;

class DisjointSet{
  vector<int> rank,parent;
public:
  DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1,0);
    for(int i=0;i<=n;++i){
      parent[i]=i;
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
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}
