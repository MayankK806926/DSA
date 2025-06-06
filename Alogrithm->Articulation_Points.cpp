class Solution {//TC->O(V+E) && SC->O(V)
    int cnt=0;
  public:
    void dfs(int node,int parent,vector<int>& vis,vector<int> adj[],vector<int>& tim,vector<int>& low,vector<int>& hsh){
        vis[node]=1;
        tim[node]=low[node]=cnt;
        cnt++;
        int child=0;
        for(auto& it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,tim,low,hsh);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tim[node] && parent!=-1){
                    hsh[node]=1;
                }
                child++;
            }else{
                low[node]=min(low[node],tim[it]);
            }
        }
        if(child > 1 && parent == -1) hsh[node]=1;
    }
  
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V),tim(V),low(V);
        vector<int> hsh(V);
        for(int i=0;i<V;++i){
            if(!vis[i]) dfs(i,-1,vis,adj,tim,low,hsh);
        }
        vector<int> ans;
        for(int i=0;i<V;++i) if(hsh[i]) ans.push_back(i);
        if(ans.size()==0) return {-1};
        return ans;
    }
};
