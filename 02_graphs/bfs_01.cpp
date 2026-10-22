// @desc: BFS 0-1 (pesos 0 o 1) con deque; g[u] = {(v, w)}
// @cx: O(V + E)
vector<int> bfs01(const vector<vector<pair<int, int>>>& g, int s) {
    int n = g.size(); vector<int> d(n, INT_MAX); deque<int> q;
    d[s] = 0; q.push_back(s);
    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto [v, w] : g[u])
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (w == 0) q.push_front(v); else q.push_back(v);
            }
    }
    return d;
}
