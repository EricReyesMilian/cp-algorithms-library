// @desc: Cobertura minima de caminos disjuntos en un DAG (= n - matching) y antichain maximo (Dilworth) via Kuhn
// @cx: O(V * E)
// edges dirigidos u->v en un DAG de n nodos. Devuelve el minimo numero de caminos disjuntos en vertices
int min_path_cover(int n, const vector<pii>& edges) {
    vector<vi> g(n); for (auto [u, v] : edges) g[u].push_back(v);
    vi mr(n, -1), vis(n, 0); int stamp = 0, match = 0;
    function<bool(int)> dfs = [&](int u) {
        if (vis[u] == stamp) return false; vis[u] = stamp;
        for (int v : g[u]) if (mr[v] < 0 || dfs(mr[v])) { mr[v] = u; return true; }
        return false;
    };
    for (int u = 0; u < n; u++) { stamp++; if (dfs(u)) match++; }
    return n - match; // con clausura transitiva previa => cadenas (Dilworth) = antichain maximo
}
