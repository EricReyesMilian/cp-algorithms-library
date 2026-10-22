// @desc: Dijkstra con heap, reconstruccion de camino; g[u] = {(v, w)}
// @cx: O((V + E) log V)
vector<ll> dijkstra(const vector<vector<pair<int, ll>>>& g, int s, vector<int>* par = nullptr) {
    int n = g.size(); vector<ll> d(n, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    d[s] = 0; pq.push({0, s});
    if (par) par->assign(n, -1);
    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (du > d[u]) continue;
        for (auto [v, w] : g[u])
            if (du + w < d[v]) { d[v] = du + w; if (par) (*par)[v] = u; pq.push({d[v], v}); }
    }
    return d;
}
vector<int> get_path(const vector<int>& par, int t) { // camino s -> t (vacio si inalcanzable y t != s)
    vector<int> p;
    for (int v = t; v != -1; v = par[v]) p.push_back(v);
    reverse(all(p));
    return p;
}
