// @desc: Codigo de Prufer: arbol (aristas) <-> secuencia de n-2 elementos
// @cx: O(n log n)
vector<int> prufer_encode(int n, const vector<pii>& edges) {
    vector<set<int>> g(n);
    for (auto [u, v] : edges) { g[u].insert(v); g[v].insert(u); }
    set<int> leaves; for (int i = 0; i < n; i++) if (g[i].size() == 1) leaves.insert(i);
    vi code;
    for (int i = 0; i < n - 2; i++) {
        int leaf = *leaves.begin(); leaves.erase(leaves.begin());
        int nb = *g[leaf].begin(); code.push_back(nb);
        g[nb].erase(leaf); if (g[nb].size() == 1) leaves.insert(nb);
    }
    return code;
}
vector<pii> prufer_decode(const vi& code) {
    int n = code.size() + 2; vi deg(n, 1); for (int x : code) deg[x]++;
    set<int> leaves; for (int i = 0; i < n; i++) if (deg[i] == 1) leaves.insert(i);
    vector<pii> edges;
    for (int x : code) {
        int leaf = *leaves.begin(); leaves.erase(leaves.begin());
        edges.push_back({leaf, x});
        if (--deg[x] == 1) leaves.insert(x);
    }
    int a = *leaves.begin(), b = *leaves.rbegin(); edges.push_back({a, b});
    return edges;
}
