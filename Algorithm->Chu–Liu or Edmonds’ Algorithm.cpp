#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

// Edge structure
struct Edge {
    int from, to, weight;
};

// Function to find the Minimum Cost Arborescence
int directedMST(int root, int n, vector<Edge>& edges) {
    int res = 0;
    while (true) {
        vector<int> in(n, INF);
        vector<int> pre(n, -1);

        // Step 1: Select minimum incoming edge for each node
        for (auto& e : edges) {
            if (e.from != e.to && e.weight < in[e.to]) {
                in[e.to] = e.weight;
                pre[e.to] = e.from;
            }
        }

        in[root] = 0;  // root has no incoming edge
        for (int i = 0; i < n; ++i) {
            if (in[i] == INF) return -1;  // Not all nodes are reachable
        }

        // Step 2: Detect cycles
        int cnt = 0;
        vector<int> id(n, -1), vis(n, -1);
        for (int i = 0; i < n; ++i) {
            int v = i;
            while (vis[v] != i && id[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];
            }
            if (v != root && id[v] == -1) {
                for (int u = pre[v]; u != v; u = pre[u])
                    id[u] = cnt;
                id[v] = cnt++;
            }
        }

        if (cnt == 0) break; // No cycles

        for (int i = 0; i < n; ++i) {
            if (id[i] == -1) id[i] = cnt++;
        }

        // Step 3: Contract cycles and adjust edge weights
        vector<Edge> newEdges;
        for (auto& e : edges) {
            int u = id[e.from];
            int v = id[e.to];
            if (u != v) {
                newEdges.push_back({u, v, e.weight - in[e.to]});
            }
        }

        res += accumulate(in.begin(), in.end(), 0);
        n = cnt;
        root = id[root];
        edges = newEdges;
    }

    res += accumulate(edges.begin(), edges.end(), 0,
                      [&](int acc, Edge& e) { return acc + (e.to == root ? 0 : e.weight); });

    return res;
}

int main() {
    int n = 4;  // number of nodes (0-indexed)
    int root = 0;
    vector<Edge> edges = {
        {0, 1, 1},{0, 2, 5},{1, 2, 2},
        {1, 3, 4},{2, 3, 1},{3, 0, 3}
    };
    int mstCost = directedMST(root, n, edges);
    if (mstCost == -1)
        cout << "Arborescence not possible (some nodes unreachable)." << endl;
    else
        cout << "Minimum Spanning Arborescence Cost: " << mstCost << endl;
    return 0;
}
