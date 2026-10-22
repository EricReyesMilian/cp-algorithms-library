// @desc: Matching maximo bipartito (Hopcroft-Karp) + cobertura minima de vertices (Konig)
// @cx: O(E sqrt V)
struct HopcroftKarp {
    int nl, nr; vector<vi> g; vi ml, mr, dist, it;
    HopcroftKarp(int nl = 0, int nr = 0) : nl(nl), nr(nr), g(nl), ml(nl, -1), mr(nr, -1), dist(nl), it(nl) {}
    void add_edge(int l, int r) { g[l].push_back(r); }
    bool bfs() {
        queue<int> q;
        for (int l = 0; l < nl; l++) { if (ml[l] < 0) { dist[l] = 0; q.push(l); } else dist[l] = -1; }
        bool found = false;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                int w = mr[v];
                if (w < 0) found = true;
                else if (dist[w] < 0) { dist[w] = dist[u] + 1; q.push(w); }
            }
        }
        return found;
    }
    bool dfs(int u) {
        for (int& i = it[u]; i < (int)g[u].size(); i++) {
            int v = g[u][i], w = mr[v];
            if (w < 0 || (dist[w] == dist[u] + 1 && dfs(w))) { ml[u] = v; mr[v] = u; return true; }
        }
        dist[u] = -1;
        return false;
    }
    int run() {
        int res = 0;
        while (bfs()) { fill(all(it), 0); for (int l = 0; l < nl; l++) if (ml[l] < 0 && dfs(l)) res++; }
        return res;
    }
    // cobertura minima de vertices: (izq[i], der[j]) true = en la cobertura. Llamar tras run()
    pair<vector<bool>, vector<bool>> vertex_cover() {
        vector<bool> visL(nl, false), visR(nr, false); vi st;
        for (int l = 0; l < nl; l++) if (ml[l] < 0) { visL[l] = true; st.push_back(l); }
        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            for (int v : g[u]) if (!visR[v]) { visR[v] = true; int w = mr[v]; if (w >= 0 && !visL[w]) { visL[w] = true; st.push_back(w); } }
        }
        vector<bool> cl(nl); for (int i = 0; i < nl; i++) cl[i] = !visL[i];
        return {cl, visR};
    }
};
