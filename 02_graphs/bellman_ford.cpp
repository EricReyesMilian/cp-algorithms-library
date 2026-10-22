// @desc: Bellman-Ford: caminos minimos con pesos negativos; marca nodos afectados por ciclo negativo
// @cx: O(V * E)
struct BFEdge { int u, v; ll w; };
// d[v] == INF: inalcanzable; d[v] == -INF: afectado por ciclo negativo
vector<ll> bellman_ford(int n, const vector<BFEdge>& e, int s) {
    vector<ll> d(n, INF); d[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        bool ch = false;
        for (auto& [u, v, w] : e) if (d[u] < INF && d[u] + w < d[v]) { d[v] = d[u] + w; ch = true; }
        if (!ch) break;
    }
    for (int i = 0; i < n; i++)
        for (auto& [u, v, w] : e) if (d[u] < INF && d[u] + w < d[v]) d[v] = -INF;
    return d;
}
