// @desc: 2-SAT con SCC (Tarjan). Variable i: literal verdadero 2i, falso 2i+1
// @cx: O(n + m)
struct TwoSAT {
    int n, timer = 0, nc = 0;
    vector<vi> g; vi comp, tin, low, st; vector<bool> onst, val;
    TwoSAT(int n = 0) : n(n), g(2 * n), comp(2 * n, -1), tin(2 * n, -1), low(2 * n, 0), onst(2 * n, false) {}
    // (x_a == va) OR (x_b == vb)
    void add_or(int a, bool va, int b, bool vb) {
        g[2 * a + va].push_back(2 * b + !vb);
        g[2 * b + vb].push_back(2 * a + !va);
    }
    void add_imply(int a, bool va, int b, bool vb) { add_or(a, !va, b, vb); } // (x_a==va) => (x_b==vb)
    void set_val(int a, bool va) { add_or(a, va, a, va); }                    // forzar x_a == va
    void dfs(int u) {
        tin[u] = low[u] = timer++; st.push_back(u); onst[u] = true;
        for (int v : g[u]) {
            if (tin[v] == -1) { dfs(v); low[u] = min(low[u], low[v]); }
            else if (onst[v]) low[u] = min(low[u], tin[v]);
        }
        if (low[u] == tin[u]) {
            while (true) { int v = st.back(); st.pop_back(); onst[v] = false; comp[v] = nc; if (v == u) break; }
            nc++;
        }
    }
    bool solve() { // true si es satisfacible; asignacion en val
        for (int i = 0; i < 2 * n; i++) if (tin[i] == -1) dfs(i);
        val.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (comp[2 * i] == comp[2 * i + 1]) return false;
            val[i] = comp[2 * i] < comp[2 * i + 1];
        }
        return true;
    }
};
