// @desc: Matching bipartito simple (Kuhn / aumentantes), facil de escribir para n pequenos
// @cx: O(V * E)
struct Kuhn {
    int nl, nr; vector<vi> g; vi mr, vis; int stamp = 0;
    Kuhn(int nl = 0, int nr = 0) : nl(nl), nr(nr), g(nl), mr(nr, -1), vis(nl, 0) {}
    void add_edge(int l, int r) { g[l].push_back(r); }
    bool dfs(int u) {
        if (vis[u] == stamp) return false;
        vis[u] = stamp;
        for (int v : g[u]) if (mr[v] < 0 || dfs(mr[v])) { mr[v] = u; return true; }
        return false;
    }
    int run() { int res = 0; for (int l = 0; l < nl; l++) { stamp++; if (dfs(l)) res++; } return res; }
};
