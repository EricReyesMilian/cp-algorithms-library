// @desc: Segment tree iterativo (bottom-up), operacion asociativa configurable
// @cx: O(log n) por query/update, O(n) build
struct SegTree {
    using T = ll;
    static T op(T a, T b) { return a + b; }  // CAMBIAR (min, max, gcd, ...)
    static constexpr T ID = 0;                // CAMBIAR (elemento neutro)
    int n; vector<T> t;
    SegTree(int n = 0) : n(n), t(2 * n, ID) {}
    SegTree(const vector<T>& a) : n(a.size()), t(2 * a.size(), ID) {
        copy(all(a), t.begin() + n);
        for (int i = n - 1; i > 0; i--) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
    void set(int i, T v) { for (t[i += n] = v; i >>= 1;) t[i] = op(t[2 * i], t[2 * i + 1]); }
    T get(int i) { return t[i + n]; }
    T query(int l, int r) { // [l, r)
        T rl = ID, rr = ID;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) rl = op(rl, t[l++]);
            if (r & 1) rr = op(t[--r], rr);
        }
        return op(rl, rr);
    }
};
