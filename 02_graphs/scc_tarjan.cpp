// @desc: Componentes fuertemente conexas (Tarjan, recursivo). comp[] en orden topologico inverso
// @cx: O(V + E)
struct SCC {
    int n, timer = 0, ncomp = 0;
    vector<vector<int>> g; vector<int> low, tin, comp, st; vector<bool> onst;
    SCC(int n = 0) : n(n), g(n), low(n), tin(n, -1), comp(n, -1), onst(n, false) {}
    void add_edge(int u, int v) { g[u].push_back(v); }
    void dfs(int u) {
        tin[u] = low[u] = timer++; st.push_back(u); onst[u] = true;
        for (int v : g[u]) {
            if (tin[v] == -1) { dfs(v); low[u] = min(low[u], low[v]); }
            else if (onst[v]) low[u] = min(low[u], tin[v]);
        }
        if (low[u] == tin[u]) {
            while (true) {
                int v = st.back(); st.pop_back(); onst[v] = false; comp[v] = ncomp;
                if (v == u) break;
            }
            ncomp++;
        }
    }
    void run() { for (int i = 0; i < n; i++) if (tin[i] == -1) dfs(i); }
    // arista u->v entre componentes distintas cumple comp[u] > comp[v]
    vector<vector<int>> condensation() {
        vector<vector<int>> dag(ncomp);
        for (int u = 0; u < n; u++) for (int v : g[u]) if (comp[u] != comp[v]) dag[comp[u]].push_back(comp[v]);
        for (auto& x : dag) { sort(all(x)); x.erase(unique(all(x)), x.end()); }
        return dag;
    }
};
