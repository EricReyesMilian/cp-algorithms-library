// @desc: Flujo maximo Dinic (capacidades ll), corte minimo y flujo por arista
// @cx: O(V^2 E) general, O(E sqrt V) en grafos unitarios/bipartitos
struct Dinic {
    struct E { int to; ll cap; };
    int n; vector<E> e; vector<vi> g; vi level, it;
    Dinic(int n = 0) : n(n), g(n), level(n), it(n) {}
    int add_edge(int u, int v, ll c, ll rc = 0) { // devuelve id de la arista
        g[u].push_back(e.size()); e.push_back({v, c});
        g[v].push_back(e.size()); e.push_back({u, rc});
        return (int)e.size() - 2;
    }
    bool bfs(int s, int t) {
        fill(all(level), -1); level[s] = 0; queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int id : g[u]) if (e[id].cap > 0 && level[e[id].to] < 0) { level[e[id].to] = level[u] + 1; q.push(e[id].to); }
        }
        return level[t] >= 0;
    }
    ll dfs(int u, int t, ll f) {
        if (u == t || !f) return f;
        ll pushed = 0;
        for (int& i = it[u]; i < (int)g[u].size(); i++) {
            int id = g[u][i], v = e[id].to;
            if (e[id].cap > 0 && level[v] == level[u] + 1) {
                ll r = dfs(v, t, min(f - pushed, e[id].cap));
                if (r) { e[id].cap -= r; e[id ^ 1].cap += r; pushed += r; if (pushed == f) return pushed; }
            }
        }
        return pushed;
    }
    ll maxflow(int s, int t) {
        ll flow = 0;
        while (bfs(s, t)) { fill(all(it), 0); flow += dfs(s, t, INF); }
        return flow;
    }
    ll flow_on(int id) { return e[id ^ 1].cap; }          // flujo en la arista id (si se creo con rc = 0)
    vector<bool> min_cut_side(int s) {                    // true = lado de s (llamar tras maxflow)
        vector<bool> vis(n, false); vi st = {s}; vis[s] = true;
        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            for (int id : g[u]) if (e[id].cap > 0 && !vis[e[id].to]) { vis[e[id].to] = true; st.push_back(e[id].to); }
        }
        return vis;
    }
};
