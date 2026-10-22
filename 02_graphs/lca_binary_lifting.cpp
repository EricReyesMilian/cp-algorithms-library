// @desc: LCA con binary lifting, k-esimo ancestro y distancia (BFS iterativo)
// @cx: O(n log n) build, O(log n) query
struct LCA {
    int n, LOG; vector<vi> up; vi dep;
    LCA(const vector<vi>& g, int root = 0) : n(g.size()) {
        LOG = 1; while ((1 << LOG) < n) LOG++;
        up.assign(LOG + 1, vi(n, root)); dep.assign(n, 0);
        vi q = {root}; vector<bool> vis(n, false); vis[root] = true;
        for (int i = 0; i < (int)q.size(); i++) {
            int u = q[i];
            for (int v : g[u]) if (!vis[v]) { vis[v] = true; dep[v] = dep[u] + 1; up[0][v] = u; q.push_back(v); }
        }
        for (int k = 1; k <= LOG; k++) for (int v = 0; v < n; v++) up[k][v] = up[k - 1][up[k - 1][v]];
    }
    int kth(int v, int k) { for (int i = 0; i <= LOG; i++) if (k >> i & 1) v = up[i][v]; return v; } // k-esimo ancestro
    int lca(int a, int b) {
        if (dep[a] < dep[b]) swap(a, b);
        a = kth(a, dep[a] - dep[b]);
        if (a == b) return a;
        for (int i = LOG; i >= 0; i--) if (up[i][a] != up[i][b]) { a = up[i][a]; b = up[i][b]; }
        return up[0][a];
    }
    int dist(int a, int b) { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }
};
