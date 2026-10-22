// @desc: Camino/ciclo euleriano (Hierholzer iterativo), dirigido o no dirigido
// @cx: O(V + E)
// Devuelve los vertices del recorrido que usa todas las aristas (vacio si no existe)
vector<int> euler_path(int n, const vector<pii>& edges, bool directed) {
    int m = edges.size();
    vector<vector<pii>> g(n); vi in(n, 0), out(n, 0);
    for (int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        g[u].push_back({v, i}); out[u]++;
        if (directed) in[v]++; else { g[v].push_back({u, i}); out[v]++; }
    }
    int start = -1;
    if (directed) {
        int s = 0, t = 0;
        for (int i = 0; i < n; i++) {
            if (out[i] - in[i] == 1) { s++; start = i; }
            else if (in[i] - out[i] == 1) t++;
            else if (in[i] != out[i]) return {};
        }
        if (!((s == 0 && t == 0) || (s == 1 && t == 1))) return {};
    } else {
        int odd = 0;
        for (int i = 0; i < n; i++) if (out[i] % 2) { odd++; start = i; }
        if (odd != 0 && odd != 2) return {};
    }
    if (start == -1) for (int i = 0; i < n; i++) if (out[i] > 0) { start = i; break; }
    if (start == -1) return n ? vector<int>{0} : vector<int>{};
    vector<bool> used(m, false); vi ptr(n, 0), res, st = {start};
    while (!st.empty()) {
        int u = st.back();
        while (ptr[u] < (int)g[u].size() && used[g[u][ptr[u]].second]) ptr[u]++;
        if (ptr[u] == (int)g[u].size()) { res.push_back(u); st.pop_back(); }
        else { auto [v, id] = g[u][ptr[u]++]; used[id] = true; st.push_back(v); }
    }
    if ((int)res.size() != m + 1) return {};
    reverse(all(res));
    return res;
}
