// @desc: Disjoint sparse table: query O(1) para operaciones asociativas NO idempotentes (suma, producto, ...)
// @cx: O(n log n) build, O(1) query
struct DisjointSparse {
    using T = ll;
    static T op(T a, T b) { return a + b; } // CAMBIAR
    static constexpr T ID = 0;               // CAMBIAR
    int n, lg; vector<vector<T>> t;
    DisjointSparse(const vector<T>& a = {}) {
        n = 2; while (n < (int)a.size()) n <<= 1;
        lg = __lg(n);
        t.assign(lg + 1, vector<T>(n, ID));
        for (int i = 0; i < (int)a.size(); i++) t[0][i] = a[i];
        for (int h = 1; h <= lg; h++) {
            for (int s = 0; s < n; s += 1 << h) {
                int mid = s + (1 << (h - 1));
                t[h][mid - 1] = t[0][mid - 1];
                for (int i = mid - 2; i >= s; i--) t[h][i] = op(t[0][i], t[h][i + 1]);
                t[h][mid] = t[0][mid];
                for (int i = mid + 1; i < s + (1 << h); i++) t[h][i] = op(t[h][i - 1], t[0][i]);
            }
        }
    }
    T query(int l, int r) { // [l, r] inclusivo
        if (l == r) return t[0][l];
        int h = __lg(l ^ r) + 1;
        return op(t[h][l], t[h][r]);
    }
};
