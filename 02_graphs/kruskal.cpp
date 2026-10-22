// @desc: MST con Kruskal (DSU interno); aristas (w, u, v)
// @cx: O(E log E)
ll kruskal(int n, vector<array<ll, 3>> e, vector<array<ll, 3>>* used = nullptr) { // devuelve -1 si no es conexo
    sort(all(e)); vi p(n); iota(all(p), 0);
    function<int(int)> find = [&](int x) { return p[x] == x ? x : p[x] = find(p[x]); };
    ll total = 0; int cnt = 0;
    for (auto& ed : e) {
        int a = find(ed[1]), b = find(ed[2]);
        if (a == b) continue;
        p[a] = b; total += ed[0]; cnt++;
        if (used) used->push_back(ed);
    }
    return cnt == n - 1 ? total : -1;
}
