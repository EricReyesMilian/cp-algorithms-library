// @desc: Sparse table para RMQ (min) con query O(1); cambiar min por max/gcd
// @cx: O(n log n) build, O(1) query
template <class T> struct SparseTable {
    vector<vector<T>> t;
    SparseTable(const vector<T>& a = {}) {
        int n = a.size(); if (!n) return;
        int lg = __lg(n) + 1;
        t.assign(lg, vector<T>(n)); t[0] = a;
        for (int k = 1; k < lg; k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                t[k][i] = min(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
    }
    T query(int l, int r) { int k = __lg(r - l + 1); return min(t[k][l], t[k][r - (1 << k) + 1]); } // [l, r]
};
