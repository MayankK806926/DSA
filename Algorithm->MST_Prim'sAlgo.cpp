class Solution {//TC->O(E log E) && SC->O(E)
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> ans;
        int mstsum=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({0,{0,-1}});
        vector<int> vis(V);
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second.first;
            int par=pq.top().second.second;
            pq.pop();
            if(vis[node]) continue;
            else{
                ans.push_back({node,par});
                vis[node]=1;
                mstsum+=wt;
            }
            
            for(auto& it:adj[node]){
                if(!vis[it[0]]){
                    pq.push({it[1],{it[0],node}});
                }
            }
        }
        
        return mstsum;
    }
};
