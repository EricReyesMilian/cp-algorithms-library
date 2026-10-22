// @desc: Fenwick 2D: update puntual, suma de rectangulo
// @cx: O(log n * log m)
template <class T> struct Fenwick2D {
    int n, m; vector<vector<T>> t;
    Fenwick2D(int n = 0, int m = 0) : n(n), m(m), t(n + 1, vector<T>(m + 1, 0)) {}
    void add(int x, int y, T v) { for (int i = x + 1; i <= n; i += i & -i) for (int j = y + 1; j <= m; j += j & -j) t[i][j] += v; }
    T query(int x, int y) { T r = 0; for (int i = x + 1; i > 0; i -= i & -i) for (int j = y + 1; j > 0; j -= j & -j) r += t[i][j]; return r; } // [0..x]x[0..y]
    T query(int x1, int y1, int x2, int y2) { return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1); }
};
