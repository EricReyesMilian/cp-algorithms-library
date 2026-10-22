// @desc: Diametro de un arbol ponderado (dos recorridos); devuelve (largo, extremo u, extremo v)
// @cx: O(n)
vector<ll> tree_dist(const vector<vector<pair<int, ll>>>& g, int s) {
    vector<ll> d(g.size(), -1); d[s] = 0; vi st = {s};
    while (!st.empty()) {
        int u = st.back(); st.pop_back();
        for (auto [v, w] : g[u]) if (d[v] < 0) { d[v] = d[u] + w; st.push_back(v); }
    }
    return d;
}
array<ll, 3> tree_diameter(const vector<vector<pair<int, ll>>>& g) {
    auto d0 = tree_dist(g, 0);
    int a = max_element(all(d0)) - d0.begin();
    auto da = tree_dist(g, a);
    int b = max_element(all(da)) - da.begin();
    return {da[b], a, b};
}
