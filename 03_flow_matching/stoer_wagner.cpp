// @desc: Corte minimo global (Stoer-Wagner) en grafo no dirigido con pesos; devuelve (peso, nodos de un lado)
// @cx: O(V^3)
pair<ll, vi> stoer_wagner(vector<vll> mat) {
    const ll NEG = -(ll)4e18;
    pair<ll, vi> best = {INF, {}};
    int n = mat.size(); vector<vi> co(n);
    for (int i = 0; i < n; i++) co[i] = {i};
    for (int ph = 1; ph < n; ph++) {
        vll w = mat[0]; int s = 0, t = 0;
        for (int it = 0; it < n - ph; it++) {
            w[t] = NEG; s = t; t = max_element(all(w)) - w.begin();
            for (int i = 0; i < n; i++) w[i] += mat[t][i];
        }
        best = min(best, make_pair(w[t] - mat[t][t], co[t]));
        co[s].insert(co[s].end(), all(co[t]));
        for (int i = 0; i < n; i++) mat[s][i] += mat[t][i];
        for (int i = 0; i < n; i++) mat[i][s] = mat[s][i];
        mat[0][t] = NEG;
    }
    return best;
}
