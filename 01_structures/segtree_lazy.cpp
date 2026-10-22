// @desc: Segment tree recursivo con lazy: suma en rango + update de rango (add)
// @cx: O(log n) por operacion
struct LazySeg {
    int n; vector<ll> sum, lz;
    LazySeg(int n = 0) : n(n), sum(4 * n + 4, 0), lz(4 * n + 4, 0) {}
    void build(const vector<ll>& a, int x, int l, int r) {
        if (r - l == 1) { sum[x] = a[l]; return; }
        int m = (l + r) / 2;
        build(a, 2 * x, l, m); build(a, 2 * x + 1, m, r);
        sum[x] = sum[2 * x] + sum[2 * x + 1];
    }
    void build(const vector<ll>& a) { build(a, 1, 0, n); }
    void apply(int x, int l, int r, ll v) { sum[x] += v * (r - l); lz[x] += v; }
    void push(int x, int l, int r) {
        if (lz[x]) { int m = (l + r) / 2; apply(2 * x, l, m, lz[x]); apply(2 * x + 1, m, r, lz[x]); lz[x] = 0; }
    }
    void update(int x, int l, int r, int ql, int qr, ll v) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) { apply(x, l, r, v); return; }
        push(x, l, r);
        int m = (l + r) / 2;
        update(2 * x, l, m, ql, qr, v); update(2 * x + 1, m, r, ql, qr, v);
        sum[x] = sum[2 * x] + sum[2 * x + 1];
    }
    ll query(int x, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) return 0;
        if (ql <= l && r <= qr) return sum[x];
        push(x, l, r);
        int m = (l + r) / 2;
        return query(2 * x, l, m, ql, qr) + query(2 * x + 1, m, r, ql, qr);
    }
    void update(int l, int r, ll v) { update(1, 0, n, l, r, v); } // [l, r)
    ll query(int l, int r) { return query(1, 0, n, l, r); }       // [l, r)
};
