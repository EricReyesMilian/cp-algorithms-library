// @desc: Gauss modulo primo MOD: resolver A x = b (0/1/2 soluciones) y determinante
// @cx: O(n^3)
// a: n filas, m+1 columnas (ultima = b), valores en [0, MOD)
int gauss_mod(vector<vll> a, vll& ans) {
    auto pw = [](ll b, ll e) { ll r = 1; b %= MOD; for (; e; e >>= 1, b = b * b % MOD) if (e & 1) r = r * b % MOD; return r; };
    int n = a.size(), m = a[0].size() - 1; vi where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = -1; for (int i = row; i < n; i++) if (a[i][col]) { sel = i; break; }
        if (sel < 0) continue;
        swap(a[sel], a[row]); where[col] = row;
        ll iv = pw(a[row][col], MOD - 2);
        for (int j = col; j <= m; j++) a[row][j] = a[row][j] * iv % MOD;
        for (int i = 0; i < n; i++) if (i != row && a[i][col]) {
            ll c = a[i][col];
            for (int j = col; j <= m; j++) a[i][j] = ((a[i][j] - c * a[row][j]) % MOD + MOD) % MOD;
        }
        row++;
    }
    ans.assign(m, 0);
    for (int i = 0; i < m; i++) if (where[i] != -1) ans[i] = a[where[i]][m];
    for (int i = 0; i < n; i++) {
        ll s = 0; for (int j = 0; j < m; j++) s = (s + ans[j] * a[i][j]) % MOD;
        if (s != a[i][m]) return 0;
    }
    for (int i = 0; i < m; i++) if (where[i] == -1) return 2;
    return 1;
}
ll det_mod(vector<vll> a) { // matriz cuadrada, valores en [0, MOD)
    auto pw = [](ll b, ll e) { ll r = 1; b %= MOD; for (; e; e >>= 1, b = b * b % MOD) if (e & 1) r = r * b % MOD; return r; };
    int n = a.size(); ll det = 1;
    for (int i = 0; i < n; i++) {
        int p = -1; for (int j = i; j < n; j++) if (a[j][i]) { p = j; break; }
        if (p < 0) return 0;
        if (p != i) { swap(a[p], a[i]); det = (MOD - det) % MOD; }
        det = det * a[i][i] % MOD; ll iv = pw(a[i][i], MOD - 2);
        for (int j = i + 1; j < n; j++) {
            ll f = a[j][i] * iv % MOD; if (!f) continue;
            for (int k = i; k < n; k++) a[j][k] = ((a[j][k] - f * a[i][k]) % MOD + MOD) % MOD;
        }
    }
    return det;
}
