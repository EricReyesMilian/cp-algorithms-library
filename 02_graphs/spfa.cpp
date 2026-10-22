// @desc: SPFA (Bellman-Ford con cola); devuelve false si hay ciclo negativo alcanzable
// @cx: O(V * E) peor caso, rapido en practica
bool spfa(const vector<vector<pair<int, ll>>>& g, int s, vector<ll>& d) {
    int n = g.size(); d.assign(n, INF);
    vector<int> cnt(n, 0); vector<bool> inq(n, false); queue<int> q;
    d[s] = 0; q.push(s); inq[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (auto [v, w] : g[u])
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (!inq[v]) { q.push(v); inq[v] = true; if (++cnt[v] > n) return false; }
            }
    }
    return true;
}
