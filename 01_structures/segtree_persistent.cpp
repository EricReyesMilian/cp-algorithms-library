// @desc: Segment tree persistente (versiones) con suma y k-esimo entre dos versiones
// @cx: O(log n) por update/query, O(n log n) memoria
struct PersistentSeg {
    struct Node { int l = 0, r = 0; ll v = 0; };
    vector<Node> t; int n;
    // nodo 0 = nulo (todo ceros). Raiz inicial = 0.
    PersistentSeg(int n = 0, int reserve = 0) : n(n) { t.reserve(reserve + 1); t.emplace_back(); }
    int upd(int prev, int l, int r, int pos, ll val) {
        int cur = t.size(); t.push_back(t[prev]);
        if (r - l == 1) { t[cur].v += val; return cur; }
        int m = (l + r) / 2;
        if (pos < m) { int c = upd(t[prev].l, l, m, pos, val); t[cur].l = c; }
        else { int c = upd(t[prev].r, m, r, pos, val); t[cur].r = c; }
        t[cur].v = t[t[cur].l].v + t[t[cur].r].v;
        return cur;
    }
    int update(int root, int pos, ll val) { return upd(root, 0, n, pos, val); } // nueva raiz
    ll qry(int x, int l, int r, int ql, int qr) {
        if (!x || qr <= l || r <= ql) return 0;
        if (ql <= l && r <= qr) return t[x].v;
        int m = (l + r) / 2;
        return qry(t[x].l, l, m, ql, qr) + qry(t[x].r, m, r, ql, qr);
    }
    ll query(int root, int l, int r) { return qry(root, 0, n, l, r); } // [l, r)
    // k-esimo menor (k desde 1) en multiconjunto = version rv menos version ru (conteos)
    int kth(int ru, int rv, int k) {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2; ll c = t[t[rv].l].v - t[t[ru].l].v;
            if (k <= c) { ru = t[ru].l; rv = t[rv].l; r = m; }
            else { k -= c; ru = t[ru].r; rv = t[rv].r; l = m; }
        }
        return l;
    }
};
