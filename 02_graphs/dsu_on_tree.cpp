// @desc: Small-to-large / Sack (DSU on tree): responde sobre el multiconjunto del subarbol de cada nodo
// @cx: O(n log n)
struct Sack {
    int n, T = 0; vector<vi> g; vi sub, tin, tout, ver, col; ll cur = 0; vector<ll> ans; vi cnt;
    Sack(const vector<vi>& g, const vi& col) : n(g.size()), g(g), sub(n), tin(n), tout(n), ver(n), col(col), ans(n), cnt(n + 1, 0) {}
    void add(int u) { /* agregar col[u] y actualizar cur */ cnt[col[u]]++; }
    void rem(int u) { /* quitar col[u] y actualizar cur */ cnt[col[u]]--; }
    void dfs_sz(int u, int p) {
        tin[u] = T; ver[T++] = u; sub[u] = 1;
        for (int v : g[u]) if (v != p) { dfs_sz(v, u); sub[u] += sub[v]; }
        tout[u] = T;
    }
    void dfs(int u, int p, bool keep) {
        int big = -1;
        for (int v : g[u]) if (v != p && (big == -1 || sub[v] > sub[big])) big = v;
        for (int v : g[u]) if (v != p && v != big) dfs(v, u, false);
        if (big != -1) dfs(big, u, true);
        add(u);
        for (int v : g[u]) if (v != p && v != big) for (int i = tin[v]; i < tout[v]; i++) add(ver[i]);
        ans[u] = cur; // respuesta del subarbol de u
        if (!keep) for (int i = tin[u]; i < tout[u]; i++) rem(ver[i]);
    }
    void run(int root = 0) { dfs_sz(root, -1); dfs(root, -1, true); }
};
