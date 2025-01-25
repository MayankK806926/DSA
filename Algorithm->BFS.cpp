//Also called Level Wise Transveral
//TC->O(n)+O(2E) & SC-> O(3n)
// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    int n=adj.size();
    vector<int> vis(n,0);
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}
