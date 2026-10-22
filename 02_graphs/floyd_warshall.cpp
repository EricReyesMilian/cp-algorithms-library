// @desc: Floyd-Warshall todos contra todos, deteccion de ciclos negativos y reconstruccion de camino
// @cx: O(V^3)
struct Floyd {
    int n; vector<vll> d; vector<vi> nxt;
    Floyd(int n) : n(n), d(n, vll(n, INF)), nxt(n, vi(n, -1)) { for (int i = 0; i < n; i++) { d[i][i] = 0; nxt[i][i] = i; } }
    void add_edge(int u, int v, ll w) { if (w < d[u][v]) { d[u][v] = w; nxt[u][v] = v; } }
    void run() {
        for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) if (d[i][k] < INF)
            for (int j = 0; j < n; j++) if (d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) {
                d[i][j] = max(-INF, d[i][k] + d[k][j]); nxt[i][j] = nxt[i][k];
            }
    }
    bool neg_cycle() { for (int i = 0; i < n; i++) if (d[i][i] < 0) return true; return false; }
    vector<int> path(int u, int v) { // solo valido sin ciclos negativos
        if (nxt[u][v] == -1) return {};
        vector<int> p = {u};
        while (u != v) { u = nxt[u][v]; p.push_back(u); }
        return p;
    }
};
