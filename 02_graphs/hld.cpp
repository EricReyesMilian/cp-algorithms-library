// @desc: Heavy-Light Decomposition: consultas de camino/subarbol sobre un segment tree (pos[] = indice)
// @cx: O(log^2 n) por consulta de camino
struct HLD {
    int n; vector<vi> g; vi par, dep, heavy, head, pos, sub;
    HLD(int n = 0) : n(n), g(n), par(n, -1), dep(n, 0), heavy(n, -1), head(n, 0), pos(n, 0), sub(n, 1) {}
    void add_edge(int u, int v) { g[u].push_back(v); g[v].push_back(u); }
    void build(int root = 0) {
        vi ord = {root}; par[root] = -1;
        for (int i = 0; i < (int)ord.size(); i++) {
            int u = ord[i];
            for (int v : g[u]) if (v != par[u]) { par[v] = u; dep[v] = dep[u] + 1; ord.push_back(v); }
        }
        for (int i = n - 1; i > 0; i--) { int u = ord[i]; sub[par[u]] += sub[u]; }
        for (int u : ord) {
            heavy[u] = -1;
            for (int v : g[u]) if (v != par[u] && (heavy[u] == -1 || sub[v] > sub[heavy[u]])) heavy[u] = v;
        }
        int cur = 0; vi st = {root}; head[root] = root;
        while (!st.empty()) { // preorden con hijo pesado primero => cadenas y subarboles contiguos
            int u = st.back(); st.pop_back(); pos[u] = cur++;
            for (int v : g[u]) if (v != par[u] && v != heavy[u]) { head[v] = v; st.push_back(v); }
            if (heavy[u] != -1) { head[heavy[u]] = head[u]; st.push_back(heavy[u]); }
        }
    }
    int lca(int u, int v) {
        while (head[u] != head[v]) { if (dep[head[u]] > dep[head[v]]) swap(u, v); v = par[head[v]]; }
        return dep[u] < dep[v] ? u : v;
    }
    // f(l, r): rangos [l, r] de posiciones. Con edge=true los pesos viven en el hijo (aristas)
    template <class F> void path(int u, int v, F f, bool edge = false) {
        for (; head[u] != head[v]; v = par[head[v]]) {
            if (dep[head[u]] > dep[head[v]]) swap(u, v);
            f(pos[head[v]], pos[v]);
        }
        if (dep[u] > dep[v]) swap(u, v);
        if (pos[u] + edge <= pos[v]) f(pos[u] + edge, pos[v]);
    }
    pii subtree(int u) { return {pos[u], pos[u] + sub[u] - 1}; } // rango [l, r]
};
