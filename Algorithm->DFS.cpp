//TC->O(n*(2E))  & SC->O(n)(rec stack) + O(n) + O(n)
  // Function to return a list containing the DFS traversal of the graph.
void rec_dfs(int node,vector<vector<int>>& adj,vector<int>& dfs,vector<int>& vis){
    vis[node]=1;
    dfs.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]) rec_dfs(it,adj,dfs,vis);
    }
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    // Code here
    int n=adj.size();
    vector<int> vis(n,0),dfs;
    rec_dfs(0,adj,dfs,vis);
    return dfs;
}
