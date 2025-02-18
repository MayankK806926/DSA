//TC-> O(n+E) & SC->O(2*n)
vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n=adj.size();
    vector<int> indegree(n);
    for(int i=0;i<n;++i){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;++i){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> topo_sort;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo_sort.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return topo_sort;
}
