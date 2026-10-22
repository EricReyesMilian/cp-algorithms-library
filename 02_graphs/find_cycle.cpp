// @desc: Encontrar un ciclo en grafo dirigido (DFS iterativo con colores); devuelve vertices del ciclo o vacio
// @cx: O(V + E)
vector<int> find_cycle_directed(const vector<vi>& g) {
    int n = g.size(); vi color(n, 0), par(n, -1), it(n, 0);
    for (int s = 0; s < n; s++) {
        if (color[s]) continue;
        vi st = {s}; color[s] = 1;
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < (int)g[u].size()) {
                int v = g[u][it[u]++];
                if (color[v] == 0) { color[v] = 1; par[v] = u; st.push_back(v); }
                else if (color[v] == 1) { // ciclo v -> ... -> u -> v
                    vi cyc = {v};
                    for (int x = u; x != v; x = par[x]) cyc.push_back(x);
                    reverse(cyc.begin() + 1, cyc.end());
                    return cyc;
                }
            } else { color[u] = 2; st.pop_back(); }
        }
    }
    return {};
}
