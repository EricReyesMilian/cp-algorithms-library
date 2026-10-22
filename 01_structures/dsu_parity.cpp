// @desc: DSU con paridad (detecta ciclos impares / grafo bipartito dinamico)
// @cx: O(log n) amortizado
struct ParityDSU {
    vector<int> p, par, s; bool bip = true;
    ParityDSU(int n = 0) : p(n), par(n, 0), s(n, 1) { iota(all(p), 0); }
    pair<int, int> find(int x) { // (raiz, paridad respecto a la raiz)
        if (p[x] == x) return {x, 0};
        auto [r, d] = find(p[x]);
        p[x] = r; par[x] ^= d;
        return {r, par[x]};
    }
    void unite(int a, int b) { // arista entre a y b (deben tener colores distintos)
        auto [ra, da] = find(a); auto [rb, db] = find(b);
        if (ra == rb) { if (da == db) bip = false; return; }
        if (s[ra] < s[rb]) swap(ra, rb);
        p[rb] = ra; par[rb] = da ^ db ^ 1; s[ra] += s[rb];
    }
};
