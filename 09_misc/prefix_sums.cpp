// @desc: Sumas de prefijos 1D/2D y arreglos de diferencias (update de rango offline) 1D/2D
// @cx: O(n) build, O(1) query
struct Prefix2D {
    int n, m; vector<vll> p;
    Prefix2D(const vector<vll>& a) : n(a.size()), m(a[0].size()), p(n + 1, vll(m + 1, 0)) {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) p[i + 1][j + 1] = a[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
    }
    ll query(int x1, int y1, int x2, int y2) const { return p[x2 + 1][y2 + 1] - p[x1][y2 + 1] - p[x2 + 1][y1] + p[x1][y1]; } // [x1,x2]x[y1,y2]
};
struct Diff2D { // sumar v a un rectangulo, luego build() para obtener la matriz final
    int n, m; vector<vll> d;
    Diff2D(int n, int m) : n(n), m(m), d(n + 2, vll(m + 2, 0)) {}
    void add(int x1, int y1, int x2, int y2, ll v) { d[x1][y1] += v; d[x1][y2 + 1] -= v; d[x2 + 1][y1] -= v; d[x2 + 1][y2 + 1] += v; }
    vector<vll> build() { vector<vll> a(n, vll(m)); for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) { if (i) d[i][j] += d[i - 1][j]; if (j) d[i][j] += d[i][j - 1]; if (i && j) d[i][j] -= d[i - 1][j - 1]; a[i][j] = d[i][j]; } return a; }
};
// 1D: pre[i+1] = pre[i] + a[i]; suma [l,r] = pre[r+1]-pre[l]. Diferencias: d[l]+=v, d[r+1]-=v, luego prefijo.
