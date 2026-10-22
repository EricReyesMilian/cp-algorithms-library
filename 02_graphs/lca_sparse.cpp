// @desc: LCA O(1) con sparse table sobre preorden (tin[] util para subarboles y arbol virtual)
// @cx: O(n log n) build, O(1) query
struct LCAFast {
    vector<vi> st; vi tin, tout, par;
    int mn(int a, int b) const { return tin[a] < tin[b] ? a : b; }
    LCAFast(const vector<vi>& g, int root = 0) {
        int n = g.size(); tin.assign(n, -1); tout.assign(n, 0); par.assign(n, root);
        vi ord, stk = {root}, it(n, 0); int T = 0;
        tin[root] = T++; ord.push_back(root);
        while (!stk.empty()) { // DFS iterativo en preorden
            int u = stk.back();
            if (it[u] < (int)g[u].size()) {
                int v = g[u][it[u]++];
                if (v == par[u] && u != root) continue;
                if (v == root) continue;
                par[v] = u; tin[v] = T++; ord.push_back(v); stk.push_back(v);
            } else { tout[u] = T; stk.pop_back(); }
        }
        int LG = __lg(max(n, 1)) + 1;
        st.assign(LG, vi(n));
        for (int i = 0; i < n; i++) st[0][i] = par[ord[i]];
        for (int k = 1; k < LG; k++) for (int i = 0; i + (1 << k) <= n; i++)
            st[k][i] = mn(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
    bool is_anc(int a, int b) const { return tin[a] <= tin[b] && tout[b] <= tout[a]; } // a ancestro de b
    int lca(int u, int v) const {
        if (u == v) return u;
        int l = tin[u], r = tin[v]; if (l > r) swap(l, r);
        l++; int k = __lg(r - l + 1);
        return mn(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
