// @desc: MST con distancia Manhattan entre puntos (KACTL): genera O(n) aristas candidatas y corre Kruskal
// @cx: O(n log n)
ll manhattan_mst(vector<pii> ps) {
    int n = ps.size(); vi id(n); iota(all(id), 0);
    vector<array<int, 3>> edges;
    for (int k = 0; k < 4; k++) {
        sort(all(id), [&](int i, int j) { return ps[i].first + ps[i].second < ps[j].first + ps[j].second; });
        map<int, int> sweep;
        for (int i : id) {
            for (auto it = sweep.lower_bound(-ps[i].second); it != sweep.end(); sweep.erase(it++)) {
                int j = it->second;
                int dx = ps[i].first - ps[j].first, dy = ps[i].second - ps[j].second;
                if (dy > dx) break;
                edges.push_back({dy + dx, i, j});
            }
            sweep[-ps[i].second] = i;
        }
        for (auto& p : ps) { if (k & 1) p.first = -p.first; else swap(p.first, p.second); }
    }
    sort(all(edges)); vi p(n); iota(all(p), 0);
    function<int(int)> find = [&](int x) { return p[x] == x ? x : p[x] = find(p[x]); };
    ll total = 0;
    for (auto& e : edges) { int a = find(e[1]), b = find(e[2]); if (a != b) { p[a] = b; total += e[0]; } }
    return total;
}
