// @desc: Gauss sobre GF(2) con bitset: sistema de ecuaciones XOR (bit m = termino independiente)
// @cx: O(n m min(n,m) / 64)
// a[i]: bits 0..m-1 coeficientes, bit m = rhs. Devuelve rango, o -1 si no hay solucion. ans = una solucion
template <int N> int gauss_xor(vector<bitset<N>> a, int m, bitset<N>& ans) {
    int n = a.size(), rk = 0; vi where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = -1; for (int i = row; i < n; i++) if (a[i][col]) { sel = i; break; }
        if (sel < 0) continue;
        swap(a[sel], a[row]); where[col] = row;
        for (int i = 0; i < n; i++) if (i != row && a[i][col]) a[i] ^= a[row];
        row++; rk++;
    }
    ans.reset();
    for (int c = 0; c < m; c++) if (where[c] != -1) ans[c] = a[where[c]][m];
    bitset<N> mask; for (int j = 0; j < m; j++) mask[j] = 1;
    for (int i = 0; i < n; i++) if ((a[i] & mask).none() && a[i][m]) return -1;
    return rk;
}
