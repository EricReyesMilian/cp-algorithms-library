// @desc: Teorema de Kirchhoff: numero de arboles generadores de un multigrafo (mod MOD primo)
// @cx: O(n^3)
ll count_spanning_trees(int n, const vector<pii>& edges) {
    auto pw = [](ll b, ll e) { ll r = 1; b %= MOD; for (; e; e >>= 1, b = b * b % MOD) if (e & 1) r = r * b % MOD; return r; };
    vector<vll> a(n, vll(n, 0));
    for (auto [u, v] : edges) if (u != v) { a[u][u]++; a[v][v]++; a[u][v]--; a[v][u]--; }
    int m = n - 1; // quitar fila y columna 0
    vector<vll> b(m, vll(m));
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) b[i][j] = ((a[i + 1][j + 1] % MOD) + MOD) % MOD;
    ll det = 1;
    for (int i = 0; i < m; i++) {
        int p = -1; for (int j = i; j < m; j++) if (b[j][i]) { p = j; break; }
        if (p < 0) return 0;
        if (p != i) { swap(b[p], b[i]); det = (MOD - det) % MOD; }
        det = det * b[i][i] % MOD; ll iv = pw(b[i][i], MOD - 2);
        for (int j = i + 1; j < m; j++) {
            ll f = b[j][i] * iv % MOD; if (!f) continue;
            for (int k = i; k < m; k++) b[j][k] = ((b[j][k] - f * b[i][k]) % MOD + MOD) % MOD;
        }
    }
    return det;
}
