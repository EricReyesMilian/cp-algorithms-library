// @desc: Seg tree lazy: aplicar x -> m*x+b a un rango, suma en rango (mod MOD)
// @cx: O(log n) por operacion
struct AffineSeg {
    int n; vll sum, ma, ad;
    AffineSeg(int n = 0) : n(n), sum(4 * n + 4, 0), ma(4 * n + 4, 1), ad(4 * n + 4, 0) {}
    void build(const vll& a, int x, int l, int r) {
        if (r - l == 1) { sum[x] = a[l] % MOD; return; }
        int m = (l + r) / 2;
        build(a, 2 * x, l, m); build(a, 2 * x + 1, m, r);
        sum[x] = (sum[2 * x] + sum[2 * x + 1]) % MOD;
    }
    void build(const vll& a) { build(a, 1, 0, n); }
    void apply(int x, int l, int r, ll m, ll b) {
        sum[x] = (sum[x] * m + b * (r - l)) % MOD;
        ma[x] = ma[x] * m % MOD;
        ad[x] = (ad[x] * m + b) % MOD;
    }
    void push(int x, int l, int r) {
        if (ma[x] != 1 || ad[x] != 0) {
            int m = (l + r) / 2;
            apply(2 * x, l, m, ma[x], ad[x]); apply(2 * x + 1, m, r, ma[x], ad[x]);
            ma[x] = 1; ad[x] = 0;
        }
    }
    void update(int x, int l, int r, int ql, int qr, ll m, ll b) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) { apply(x, l, r, m, b); return; }
        push(x, l, r);
        int mid = (l + r) / 2;
        update(2 * x, l, mid, ql, qr, m, b); update(2 * x + 1, mid, r, ql, qr, m, b);
        sum[x] = (sum[2 * x] + sum[2 * x + 1]) % MOD;
    }
    ll query(int x, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) return 0;
        if (ql <= l && r <= qr) return sum[x];
        push(x, l, r);
        int m = (l + r) / 2;
        return (query(2 * x, l, m, ql, qr) + query(2 * x + 1, m, r, ql, qr)) % MOD;
    }
    void update(int l, int r, ll m, ll b) { update(1, 0, n, l, r, m, b); } // [l, r): x -> m*x+b
    ll query(int l, int r) { return query(1, 0, n, l, r); }
};
