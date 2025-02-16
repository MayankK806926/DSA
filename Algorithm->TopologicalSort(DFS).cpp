// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
class Solution {
  private://TC->o(n+E) & SC->O(3*n)
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,stack<int>& st){
        vis[node]++;
        for(int i=0;i<adj[node].size();++i){
            if(!vis[adj[node][i]]) dfs(adj[node][i],vis,adj,st);
        }
        st.push(node);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n=adj.size();
        stack<int> st;
        vector<int> vis(n,0);
        for(int i=0;i<n;++i){
            if(vis[i]==0)
                dfs(i,vis,adj,st);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
