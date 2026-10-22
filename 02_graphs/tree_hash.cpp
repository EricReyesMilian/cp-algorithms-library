// @desc: Isomorfismo de arboles (AHU con ids canonicos compartidos); enraizado y sin raiz (por centros)
// @cx: O(n log n)
map<vi, int> canon_ids; // compartido entre todos los arboles que se comparan
int rooted_hash(const vector<vi>& g, int root) {
    int n = g.size(); vi par(n, -1), ord = {root}, id(n);
    for (int i = 0; i < (int)ord.size(); i++) { int u = ord[i]; for (int v : g[u]) if (v != par[u]) { par[v] = u; ord.push_back(v); } }
    for (int i = n - 1; i >= 0; i--) {
        int u = ord[i]; vi ch;
        for (int v : g[u]) if (v != par[u]) ch.push_back(id[v]);
        sort(all(ch));
        auto it = canon_ids.find(ch);
        if (it == canon_ids.end()) it = canon_ids.emplace(ch, canon_ids.size()).first;
        id[u] = it->second;
    }
    return id[root];
}
int unrooted_hash(const vector<vi>& g) { // dos arboles son isomorfos <=> mismo valor
    int n = g.size(); vi deg(n), leaves, centers;
    for (int i = 0; i < n; i++) { deg[i] = g[i].size(); if (deg[i] <= 1) leaves.push_back(i); }
    int rem = n;
    while (rem > 2) {
        vi nl; rem -= leaves.size();
        for (int u : leaves) for (int v : g[u]) if (--deg[v] == 1) nl.push_back(v);
        leaves = nl;
    }
    centers = leaves; int best = INT_MAX;
    for (int c : centers) best = min(best, rooted_hash(g, c));
    return best;
}
