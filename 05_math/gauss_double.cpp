// @desc: Eliminacion gaussiana con doubles: A x = b (sistema n x m). 0 = sin solucion, 1 = unica, 2 = infinitas
// @cx: O(n m min(n,m))
// a: n filas, m+1 columnas (la ultima es b). ans recibe una solucion
int gauss_double(vector<vector<double>> a, vector<double>& ans) {
    int n = a.size(), m = a[0].size() - 1; vi where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = row;
        for (int i = row; i < n; i++) if (fabs(a[i][col]) > fabs(a[sel][col])) sel = i;
        if (fabs(a[sel][col]) < 1e-9) continue;
        swap(a[sel], a[row]); where[col] = row;
        for (int i = 0; i < n; i++) if (i != row) {
            double c = a[i][col] / a[row][col];
            for (int j = col; j <= m; j++) a[i][j] -= a[row][j] * c;
        }
        row++;
    }
    ans.assign(m, 0);
    for (int i = 0; i < m; i++) if (where[i] != -1) ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; i++) {
        double s = 0; for (int j = 0; j < m; j++) s += ans[j] * a[i][j];
        if (fabs(s - a[i][m]) > 1e-6) return 0;
    }
    for (int i = 0; i < m; i++) if (where[i] == -1) return 2;
    return 1;
}
