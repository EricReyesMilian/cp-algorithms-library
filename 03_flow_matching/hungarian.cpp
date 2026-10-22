// @desc: Algoritmo hungaro: asignacion de costo minimo (n filas <= m columnas), indices desde 1
// @cx: O(n^2 m)
// a[1..n][1..m]; asig[i] = columna asignada a la fila i. Devuelve costo minimo
ll hungarian(const vector<vll>& a, vi& asig) {
    int n = a.size() - 1, m = a[0].size() - 1;
    vll u(n + 1, 0), v(m + 1, 0); vi p(m + 1, 0), way(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        p[0] = i; int j0 = 0; vll minv(m + 1, INF); vector<bool> used(m + 1, false);
        do {
            used[j0] = true; int i0 = p[j0], j1 = 0; ll delta = INF;
            for (int j = 1; j <= m; j++) if (!used[j]) {
                ll cur = a[i0][j] - u[i0] - v[j];
                if (cur < minv[j]) { minv[j] = cur; way[j] = j0; }
                if (minv[j] < delta) { delta = minv[j]; j1 = j; }
            }
            for (int j = 0; j <= m; j++) { if (used[j]) { u[p[j]] += delta; v[j] -= delta; } else minv[j] -= delta; }
            j0 = j1;
        } while (p[j0] != 0);
        do { int j1 = way[j0]; p[j0] = p[j1]; j0 = j1; } while (j0);
    }
    asig.assign(n + 1, 0);
    for (int j = 1; j <= m; j++) if (p[j]) asig[p[j]] = j;
    return -v[0];
}
