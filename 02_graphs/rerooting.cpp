// @desc: Rerooting generico de DP en arboles (por defecto: excentricidad = distancia maxima a otro nodo)
// @cx: O(n)
struct Rerooting {
    using T = ll;
    static T id() { return 0; }                                    // neutro de merge
    static T merge(T a, T b) { return max(a, b); }                // combina aportes de hijos
    static T lift(T dp_child, int child, int parent) { return dp_child + 1; } // aporte del hijo al padre
    int n; vector<vi> g; vi par, ord; vector<T> down, upc, res;
    Rerooting(const vector<vi>& g) : n(g.size()), g(g), par(n, -1), down(n, id()), upc(n, id()), res(n) {}
    void run(int root = 0) { // res[v] = dp con raiz en v
        ord.assign(1, root);
        for (int i = 0; i < (int)ord.size(); i++) { int u = ord[i]; for (int v : g[u]) if (v != par[u]) { par[v] = u; ord.push_back(v); } }
        for (int i = n - 1; i >= 0; i--) {
            int u = ord[i]; T acc = id();
            for (int v : g[u]) if (v != par[u]) acc = merge(acc, lift(down[v], v, u));
            down[u] = acc;
        }
        for (int u : ord) {
            vi ch; for (int v : g[u]) if (v != par[u]) ch.push_back(v);
            int k = ch.size(); vector<T> pre(k + 1), suf(k + 1);
            pre[0] = upc[u]; suf[k] = id();
            for (int i = 0; i < k; i++) pre[i + 1] = merge(pre[i], lift(down[ch[i]], ch[i], u));
            for (int i = k - 1; i >= 0; i--) suf[i] = merge(lift(down[ch[i]], ch[i], u), suf[i + 1]);
            for (int i = 0; i < k; i++) upc[ch[i]] = lift(merge(pre[i], suf[i + 1]), u, ch[i]);
            res[u] = merge(down[u], upc[u]);
        }
    }
};
