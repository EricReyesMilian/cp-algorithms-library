// @desc: Centroid decomposition (iterativo para hallar centroides); par[] = padre en el arbol de centroides
// @cx: O(n log n)
struct Centroid {
    int n; vector<vi> g; vi par, lvl, sz_, pp, ord; vector<bool> removed;
    Centroid(const vector<vi>& g) : n(g.size()), g(g), par(n, -1), lvl(n, 0), sz_(n, 0), pp(n, -1), removed(n, false) { decompose(0, -1, 0); }
    int centroid(int s) {
        ord.assign(1, s); pp[s] = -1;
        for (int i = 0; i < (int)ord.size(); i++) {
            int u = ord[i]; sz_[u] = 1;
            for (int v : g[u]) if (v != pp[u] && !removed[v]) { pp[v] = u; ord.push_back(v); }
        }
        for (int i = (int)ord.size() - 1; i > 0; i--) sz_[pp[ord[i]]] += sz_[ord[i]];
        int tot = ord.size(), u = s;
        while (true) {
            bool moved = false;
            for (int v : g[u]) if (v != pp[u] && !removed[v] && sz_[v] * 2 > tot) { u = v; moved = true; break; }
            if (!moved) return u;
        }
    }
    void decompose(int s, int parent, int level) {
        int c = centroid(s); par[c] = parent; lvl[c] = level; removed[c] = true;
        // AQUI: procesar el componente de c (BFS desde c sobre nodos no removidos)
        for (int v : g[c]) if (!removed[v]) decompose(v, c, level + 1);
    }
};
