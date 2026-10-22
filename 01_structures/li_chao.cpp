// @desc: Li Chao tree dinamico: minimo de funciones lineales en un punto x (rango [lo, hi])
// @cx: O(log C) por insercion/query
struct LiChao {
    static constexpr ll BIG = (ll)2e18;
    struct Line { ll m = 0, b = BIG; ll eval(ll x) const { return m * x + b; } };
    struct Node { Line ln; int l = -1, r = -1; };
    vector<Node> t; ll lo, hi;
    LiChao(ll lo, ll hi) : lo(lo), hi(hi) { t.emplace_back(); }
    void add(Line nw, int x, ll l, ll r) {
        ll m = (l + r) >> 1;
        bool lef = nw.eval(l) < t[x].ln.eval(l), mid = nw.eval(m) < t[x].ln.eval(m);
        if (mid) swap(t[x].ln, nw);
        if (l == r) return;
        if (lef != mid) {
            if (t[x].l < 0) { t[x].l = t.size(); t.emplace_back(); }
            add(nw, t[x].l, l, m);
        } else {
            if (t[x].r < 0) { t[x].r = t.size(); t.emplace_back(); }
            add(nw, t[x].r, m + 1, r);
        }
    }
    void insert_line(ll m, ll b) { add(Line{m, b}, 0, lo, hi); }
    ll query(ll xq) {
        int x = 0; ll l = lo, r = hi, res = LLONG_MAX;
        while (x >= 0) {
            res = min(res, t[x].ln.eval(xq));
            if (l == r) break;
            ll m = (l + r) >> 1;
            if (xq <= m) { x = t[x].l; r = m; } else { x = t[x].r; l = m + 1; }
        }
        return res;
    }
};
