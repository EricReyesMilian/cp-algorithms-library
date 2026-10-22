// @desc: Puentes, puntos de articulacion y componentes 2-aristo-conexas (maneja multiaristas)
// @cx: O(V + E)
struct Bridges {
    int n, m = 0, timer = 0, n2cc = 0;
    vector<vector<pii>> g; // (vecino, id de arista)
    vi tin, low, comp; vector<bool> is_bridge, is_cut;
    Bridges(int n = 0) : n(n), g(n), tin(n, -1), low(n, 0), comp(n, -1), is_cut(n, false) {}
    void add_edge(int u, int v) { g[u].push_back({v, m}); g[v].push_back({u, m}); m++; is_bridge.push_back(false); }
    void dfs(int u, int pe) {
        tin[u] = low[u] = timer++; int ch = 0;
        for (auto [v, id] : g[u]) {
            if (id == pe) continue;
            if (tin[v] != -1) low[u] = min(low[u], tin[v]);
            else {
                dfs(v, id); low[u] = min(low[u], low[v]); ch++;
                if (low[v] > tin[u]) is_bridge[id] = true;
                if (low[v] >= tin[u] && pe != -1) is_cut[u] = true;
            }
        }
        if (pe == -1 && ch > 1) is_cut[u] = true;
    }
    void run() {
        for (int i = 0; i < n; i++) if (tin[i] == -1) dfs(i, -1);
        for (int i = 0; i < n; i++) if (comp[i] == -1) { // componentes 2-aristo-conexas
            vi st = {i}; comp[i] = n2cc;
            while (!st.empty()) {
                int u = st.back(); st.pop_back();
                for (auto [v, id] : g[u]) if (!is_bridge[id] && comp[v] == -1) { comp[v] = n2cc; st.push_back(v); }
            }
            n2cc++;
        }
    }
};
