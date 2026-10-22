// @desc: Block-cut tree (componentes biconexas por vertices). Nodos >= n son bloques
// @cx: O(V + E)
struct BlockCut {
    int n, timer = 0; vector<vi> g, tree; vi tin, low, st;
    BlockCut(int n = 0) : n(n), g(n), tree(n), tin(n, -1), low(n, 0) {}
    void add_edge(int u, int v) { g[u].push_back(v); g[v].push_back(u); }
    void dfs(int u, int p) {
        tin[u] = low[u] = timer++; st.push_back(u);
        for (int v : g[u]) {
            if (v == p) continue;
            if (tin[v] != -1) low[u] = min(low[u], tin[v]);
            else {
                dfs(v, u); low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    int id = tree.size(); tree.emplace_back();
                    while (true) {
                        int w = st.back(); st.pop_back();
                        tree[id].push_back(w); tree[w].push_back(id);
                        if (w == v) break;
                    }
                    tree[id].push_back(u); tree[u].push_back(id);
                }
            }
        }
    }
    void run() { for (int i = 0; i < n; i++) if (tin[i] == -1) dfs(i, -1); } // tree = bosque de bloques y puntos
};
