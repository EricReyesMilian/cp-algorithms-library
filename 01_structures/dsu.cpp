// @desc: DSU / Union-Find con compresion de caminos y union por tamano
// @cx: O(alpha(n)) por operacion
struct DSU {
    vector<int> p, s; int comps;
    DSU(int n = 0) { init(n); }
    void init(int n) { p.resize(n); iota(all(p), 0); s.assign(n, 1); comps = n; }
    int find(int x) { while (p[x] != x) x = p[x] = p[p[x]]; return x; }
    bool same(int a, int b) { return find(a) == find(b); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (s[a] < s[b]) swap(a, b);
        p[b] = a; s[a] += s[b]; comps--;
        return true;
    }
    int size(int x) { return s[find(x)]; }
};
