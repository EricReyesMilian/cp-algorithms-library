// @desc: Orden topologico (Kahn); devuelve vacio si hay ciclo
// @cx: O(V + E)
vector<int> topo_sort(const vector<vector<int>>& g) {
    int n = g.size(); vector<int> in(n, 0), order;
    for (int u = 0; u < n; u++) for (int v : g[u]) in[v]++;
    queue<int> q; // para lexicograficamente menor: priority_queue con greater<>
    for (int i = 0; i < n; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop(); order.push_back(u);
        for (int v : g[u]) if (--in[v] == 0) q.push(v);
    }
    if ((int)order.size() != n) return {};
    return order;
}
