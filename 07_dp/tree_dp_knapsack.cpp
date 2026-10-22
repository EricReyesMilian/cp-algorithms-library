// @desc: DP en arbol tipo mochila (elegir k nodos con conexion a la raiz) mezclando por tamanos
// @cx: O(n^2) total (propiedad de mezcla por tamanos)
// Ejemplo: dp[u][k] = max valor eligiendo k nodos del subarbol de u que incluyen a u (conexos). val[u] = valor
vector<vll> tree_knap(const vector<vi>& g, const vll& val, int root = 0) {
    int n = g.size(); vector<vll> dp(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        dp[u] = {-INF, val[u]}; // dp[u][k], k = 0 invalido para conexos incluyendo u
        for (int v : g[u]) if (v != p) {
            dfs(v, u);
            vll nd(dp[u].size() + dp[v].size() - 1, -INF);
            for (int i = 1; i < (int)dp[u].size(); i++) {
                nd[i] = max(nd[i], dp[u][i]); // no tomar nada del hijo v
                for (int j = 1; j < (int)dp[v].size(); j++) if (dp[v][j] > -INF) nd[i + j] = max(nd[i + j], dp[u][i] + dp[v][j]);
            }
            dp[u] = nd;
            dp[v].clear(); dp[v].shrink_to_fit();
        }
    };
    dfs(root, -1); return dp;
}
