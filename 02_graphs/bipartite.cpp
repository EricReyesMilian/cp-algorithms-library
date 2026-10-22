// @desc: Chequeo de grafo bipartito (2-coloreo con BFS); color[] = 0/1, devuelve false si hay ciclo impar
// @cx: O(V + E)
bool bipartite(const vector<vi>& g, vi& color) {
    int n = g.size(); color.assign(n, -1);
    for (int s = 0; s < n; s++) {
        if (color[s] != -1) continue;
        color[s] = 0; queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (color[v] == -1) { color[v] = color[u] ^ 1; q.push(v); }
                else if (color[v] == color[u]) return false;
            }
        }
    }
    return true;
}
