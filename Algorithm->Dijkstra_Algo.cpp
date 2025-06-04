//Shortest Path in Weighted undirected graph
//TC->O(E log V) && SC-> (E + V) where E is number of edges and V is number ofnodes
class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[1] = 0;
        pq.emplace(0, 1);
        while (!pq.empty()) {
            auto d = pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for (auto& it : adj[u]) {
                int v=it.first;
                int w=it.second;
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    parent[v] = u;
                    pq.emplace(dist[v], v);
                }
            }
        }
        if (dist[n] == 1e9)
            return {-1};
        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);
        return path;
    }
};
