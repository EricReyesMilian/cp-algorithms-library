// @desc: SCC con Kosaraju iterativo (seguro para grafos profundos). comp[] en orden topologico
// @cx: O(V + E)
struct SCCK {
    int n, nc = 0; vector<vi> g, rg; vi comp, order;
    SCCK(int n = 0) : n(n), g(n), rg(n), comp(n, -1) {}
    void add_edge(int u, int v) { g[u].push_back(v); rg[v].push_back(u); }
    void run() {
        vector<bool> vis(n, false);
        for (int s = 0; s < n; s++) {
            if (vis[s]) continue;
            vector<pii> st = {{s, 0}}; vis[s] = true;
            while (!st.empty()) {
                int u = st.back().first, i = st.back().second;
                if (i < (int)g[u].size()) {
                    st.back().second++;
                    int v = g[u][i];
                    if (!vis[v]) { vis[v] = true; st.push_back({v, 0}); }
                } else { order.push_back(u); st.pop_back(); }
            }
        }
        for (int k = n - 1; k >= 0; k--) {
            int s = order[k]; if (comp[s] != -1) continue;
            vi st = {s}; comp[s] = nc;
            while (!st.empty()) {
                int u = st.back(); st.pop_back();
                for (int v : rg[u]) if (comp[v] == -1) { comp[v] = nc; st.push_back(v); }
            }
            nc++;
        }
    }
};
