// @desc: Fenwick con update de rango y query de rango (suma)
// @cx: O(log n)
template <class T> struct FenwickRange {
    int n; vector<T> a, b;
    FenwickRange(int n = 0) : n(n), a(n + 2, 0), b(n + 2, 0) {}
    void upd(vector<T>& t, int i, T v) { for (i++; i <= n; i += i & -i) t[i] += v; }
    T qry(vector<T>& t, int i) { T r = 0; for (i++; i > 0; i -= i & -i) r += t[i]; return r; }
    void add(int l, int r, T v) { // suma v a [l, r]
        upd(a, l, v); upd(a, r + 1, -v);
        upd(b, l, v * l); upd(b, r + 1, -v * (r + 1));
    }
    T prefix(int i) { return (T)(i + 1) * qry(a, i) - qry(b, i); } // suma [0, i]
    T query(int l, int r) { return prefix(r) - (l ? prefix(l - 1) : T(0)); }
};
