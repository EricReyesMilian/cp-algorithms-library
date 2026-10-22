// @desc: Matching maximo en grafo general (Edmonds / Blossom)
// @cx: O(V^3)
struct Blossom {
    int n; vector<vi> g; vi match, p, base, q; vector<bool> used, blossom;
    Blossom(int n = 0) : n(n), g(n), match(n, -1), p(n), base(n) {}
    void add_edge(int u, int v) { g[u].push_back(v); g[v].push_back(u); }
    int lca(int a, int b) {
        vector<bool> seen(n, false);
        for (;;) { a = base[a]; seen[a] = true; if (match[a] == -1) break; a = p[match[a]]; }
        for (;;) { b = base[b]; if (seen[b]) return b; b = p[match[b]]; }
    }
    void mark_path(int v, int b, int children) {
        while (base[v] != b) {
            blossom[base[v]] = blossom[base[match[v]]] = true;
            p[v] = children; children = match[v]; v = p[match[v]];
        }
    }
    int find_path(int root) {
        used.assign(n, false); p.assign(n, -1);
        for (int i = 0; i < n; i++) base[i] = i;
        used[root] = true; q.assign(1, root);
        for (int qh = 0; qh < (int)q.size(); qh++) {
            int v = q[qh];
            for (int to : g[v]) {
                if (base[v] == base[to] || match[v] == to) continue;
                if (to == root || (match[to] != -1 && p[match[to]] != -1)) {
                    int cb = lca(v, to); blossom.assign(n, false);
                    mark_path(v, cb, to); mark_path(to, cb, v);
                    for (int i = 0; i < n; i++) if (blossom[base[i]]) {
                        base[i] = cb;
                        if (!used[i]) { used[i] = true; q.push_back(i); }
                    }
                } else if (p[to] == -1) {
                    p[to] = v;
                    if (match[to] == -1) return to;
                    to = match[to]; used[to] = true; q.push_back(to);
                }
            }
        }
        return -1;
    }
    int solve() { // tamano del matching maximo; pareja de v en match[v]
        fill(all(match), -1); int res = 0;
        for (int i = 0; i < n; i++) if (match[i] == -1) {
            int v = find_path(i);
            if (v != -1) {
                res++;
                while (v != -1) { int pv = p[v], ppv = match[pv]; match[v] = pv; match[pv] = v; v = ppv; }
            }
        }
        return res;
    }
};
