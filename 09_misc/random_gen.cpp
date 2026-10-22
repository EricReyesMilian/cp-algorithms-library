// @desc: Generadores aleatorios para stress tests: enteros, permutaciones, arboles, grafos, strings
// @cx: O(n)
ll rnd(ll a, ll b) { return a + (ll)(rng() % (unsigned long long)(b - a + 1)); }
vector<int> rnd_perm(int n) { vector<int> p(n); iota(all(p), 1); shuffle(all(p), rng); return p; }
vector<pii> rnd_tree(int n) { vector<pii> e; for (int i = 2; i <= n; i++) e.push_back({(int)rnd(1, i - 1), i}); return e; } // nodos 1..n
vector<pii> rnd_graph(int n, int m) { // simple, sin lazos (m <= n(n-1)/2)
    set<pii> s; vector<pii> e;
    while ((int)e.size() < m) { int u = rnd(1, n), v = rnd(1, n); if (u == v) continue; if (u > v) swap(u, v); if (s.insert({u, v}).second) e.push_back({u, v}); }
    return e;
}
string rnd_string(int n, int alpha = 26, char base = 'a') { string s(n, base); for (auto& c : s) c = base + rnd(0, alpha - 1); return s; }
