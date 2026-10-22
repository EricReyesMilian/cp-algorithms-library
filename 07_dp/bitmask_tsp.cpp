// @desc: TSP con DP sobre mascaras (ciclo hamiltoniano de costo minimo) y conteo de caminos hamiltonianos
// @cx: O(2^n n^2)
ll tsp(const vector<vll>& d) { // d[i][j] = costo; devuelve costo del mejor ciclo que parte de 0
    int n = d.size(); vector<vll> dp(1 << n, vll(n, INF)); dp[1][0] = 0;
    for (int m = 1; m < (1 << n); m++) for (int u = 0; u < n; u++) if (dp[m][u] < INF && (m >> u & 1))
        for (int v = 0; v < n; v++) if (!(m >> v & 1) && d[u][v] < INF)
            dp[m | 1 << v][v] = min(dp[m | 1 << v][v], dp[m][u] + d[u][v]);
    ll best = INF;
    for (int u = 1; u < n; u++) if (dp[(1 << n) - 1][u] < INF && d[u][0] < INF) best = min(best, dp[(1 << n) - 1][u] + d[u][0]);
    return n == 1 ? 0 : best;
}
ll count_hamiltonian_paths(const vector<vi>& adj) { // adj[u][v] = 1 si hay arista u->v
    int n = adj.size(); vector<vll> dp(1 << n, vll(n, 0));
    for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
    for (int m = 1; m < (1 << n); m++) for (int u = 0; u < n; u++) if (dp[m][u])
        for (int v = 0; v < n; v++) if (adj[u][v] && !(m >> v & 1)) dp[m | 1 << v][v] += dp[m][u];
    ll tot = 0; for (int u = 0; u < n; u++) tot += dp[(1 << n) - 1][u];
    return tot;
}
