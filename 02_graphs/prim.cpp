// @desc: MST con Prim (heap); g[u] = {(v, w)}; devuelve -1 si no es conexo
// @cx: O(E log V)
ll prim(const vector<vector<pair<int, ll>>>& g) {
    int n = g.size(); vector<bool> in(n, false); ll total = 0; int cnt = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (in[u]) continue;
        in[u] = true; total += w; cnt++;
        for (auto [v, c] : g[u]) if (!in[v]) pq.push({c, v});
    }
    return cnt == n ? total : -1;
}
