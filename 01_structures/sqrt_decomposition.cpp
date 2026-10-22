// @desc: Descomposicion en bloques: add en rango y suma en rango (plantilla para problemas raros)
// @cx: O(sqrt n) por operacion
struct SqrtDecomp {
    int n, B, nb; vector<ll> a, blk_sum, blk_add;
    SqrtDecomp(const vector<ll>& v) : n(v.size()), a(v) {
        B = max(1, (int)sqrt((double)n)); nb = (n + B - 1) / B;
        blk_sum.assign(nb, 0); blk_add.assign(nb, 0);
        for (int i = 0; i < n; i++) blk_sum[i / B] += a[i];
    }
    void add(int l, int r, ll v) { // [l, r)
        for (int i = l; i < r;) {
            if (i % B == 0 && i + B <= r) { blk_add[i / B] += v; i += B; }
            else { a[i] += v; blk_sum[i / B] += v; i++; }
        }
    }
    ll query(int l, int r) { // [l, r)
        ll res = 0;
        for (int i = l; i < r;) {
            if (i % B == 0 && i + B <= r) { res += blk_sum[i / B] + blk_add[i / B] * B; i += B; }
            else { res += a[i] + blk_add[i / B]; i++; }
        }
        return res;
    }
};
