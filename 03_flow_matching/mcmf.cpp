// @desc: Flujo de costo minimo (SPFA / Bellman-Ford con cola); devuelve (flujo, costo)
// @cx: O(F * V * E) peor caso
struct MCMF {
    struct E { int to; ll cap, cost; };
    int n; vector<E> e; vector<vi> g;
    MCMF(int n = 0) : n(n), g(n) {}
    int add_edge(int u, int v, ll cap, ll cost) {
        g[u].push_back(e.size()); e.push_back({v, cap, cost});
        g[v].push_back(e.size()); e.push_back({u, 0, -cost});
        return (int)e.size() - 2;
    }
    pair<ll, ll> run(int s, int t, ll maxf = INF) {
        ll flow = 0, cost = 0;
        while (flow < maxf) {
            vll d(n, INF); vi inq(n, 0), pe(n, -1); deque<int> q;
            d[s] = 0; q.push_back(s);
            while (!q.empty()) {
                int u = q.front(); q.pop_front(); inq[u] = 0;
                for (int id : g[u]) {
                    int v = e[id].to;
                    if (e[id].cap > 0 && d[u] + e[id].cost < d[v]) {
                        d[v] = d[u] + e[id].cost; pe[v] = id;
                        if (!inq[v]) { inq[v] = 1; q.push_back(v); }
                    }
                }
            }
            if (d[t] == INF) break;
            ll f = maxf - flow;
            for (int v = t; v != s; v = e[pe[v] ^ 1].to) f = min(f, e[pe[v]].cap);
            for (int v = t; v != s; v = e[pe[v] ^ 1].to) { e[pe[v]].cap -= f; e[pe[v] ^ 1].cap += f; }
            flow += f; cost += f * d[t];
        }
        return {flow, cost};
    }
};
