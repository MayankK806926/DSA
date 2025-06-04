class Solution {
  public://TC->O(V*E)
         //SC-> O(V)
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=1;i<V;++i){
            for(auto& i:edges){
                int u=i[0];
                int v=i[1];
                int wt=i[2];
                if(dist[u] != 1e8 && dist[u]+wt < dist[v]) dist[v]=dist[u]+wt;
            }
        }
        
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            if(dist[u]!=1e8 && dist[u]+wt < dist[v]) return {-1};
        }
        
        return dist;
    }
};
