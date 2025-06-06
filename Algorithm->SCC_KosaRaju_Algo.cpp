class Solution {
  public:
    void dfs(int node,vector<int> &vis,vector<vector<int>> &adj,stack<int>& st){
        vis[node]=1;
        for(auto& it:adj[node]){
            if(!vis[it]) dfs(it,vis,adj,st);
        }
        st.push(node);
    }
    
    void new_dfs(int node,vector<int>& vis,vector<vector<int>>& adj,vector<int>& v){
        vis[node]=1;
        v.push_back(node);
        for(auto& i:adj[node]){
            if(!vis[i]) new_dfs(i,vis,adj,v);
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        int n=adj.size();
        stack<int> st;
        vector<int> vis(n);
        for(int i=0;i<n;++i){
            if(!vis[i]) dfs(i,vis,adj,st);
        }
        
        vector<vector<int>> new_adj(n);
        for(int i=0;i<n;++i){
            for(auto& it:adj[i]){
                new_adj[it].push_back(i);
            }
        }
        
        fill(vis.begin(), vis.end(), 0);
        vector<vector<int>> ans;
        int scc_cnt=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            vector<int> v;
            if(!vis[node]){
                new_dfs(node,vis,new_adj,v);
                scc_cnt++;
            }
            ans.push_back(v);
        }
        
        return scc_cnt;
    }
};
