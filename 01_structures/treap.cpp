// @desc: Treap implicito (secuencia): insertar, borrar, reverse de rango, suma de rango
// @cx: O(log n) esperado por operacion
struct Treap {
    struct Node { int l = 0, r = 0, sz = 1; unsigned pri = 0; ll val = 0, sum = 0; bool rev = false; };
    vector<Node> t; int root = 0;
    Treap() { t.emplace_back(); t[0].sz = 0; }
    int new_node(ll v) { Node nd; nd.pri = rng(); nd.val = nd.sum = v; t.push_back(nd); return t.size() - 1; }
    void apply_rev(int x) { if (x) { swap(t[x].l, t[x].r); t[x].rev ^= 1; } }
    void push(int x) { if (t[x].rev) { apply_rev(t[x].l); apply_rev(t[x].r); t[x].rev = false; } }
    void pull(int x) {
        t[x].sz = 1 + t[t[x].l].sz + t[t[x].r].sz;
        t[x].sum = t[x].val + t[t[x].l].sum + t[t[x].r].sum;
    }
    void split(int x, int k, int& a, int& b) { // a = primeros k elementos
        if (!x) { a = b = 0; return; }
        push(x);
        if (t[t[x].l].sz >= k) { b = x; split(t[x].l, k, a, t[x].l); pull(x); }
        else { a = x; split(t[x].r, k - t[t[x].l].sz - 1, t[x].r, b); pull(x); }
    }
    int merge(int a, int b) {
        if (!a || !b) return a ? a : b;
        if (t[a].pri > t[b].pri) { push(a); int c = merge(t[a].r, b); t[a].r = c; pull(a); return a; }
        push(b); int c = merge(a, t[b].l); t[b].l = c; pull(b); return b;
    }
    void insert(int pos, ll v) { int a, b; split(root, pos, a, b); root = merge(merge(a, new_node(v)), b); }
    void erase(int pos) { int a, b, c; split(root, pos, a, b); split(b, 1, b, c); root = merge(a, c); }
    ll range_sum(int l, int r) { int a, b, c; split(root, l, a, b); split(b, r - l, b, c); ll s = t[b].sum; root = merge(a, merge(b, c)); return s; } // [l, r)
    void reverse_range(int l, int r) { int a, b, c; split(root, l, a, b); split(b, r - l, b, c); apply_rev(b); root = merge(a, merge(b, c)); } // [l, r)
    int size() { return t[root].sz; }
};
