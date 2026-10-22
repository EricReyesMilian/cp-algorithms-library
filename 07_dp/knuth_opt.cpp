// @desc: Optimizacion de Knuth para DP de intervalos: dp[l][r] = min_k dp[l][k] + dp[k+1][r] + w(l, r)
// @cx: O(n^2)
// Requiere w cuadrangular y monotono. a = pesos; ejemplo con w(l, r) = suma de a[l..r] (fusion optima de piedras)
ll knuth_merge(const vll& a) {
    int n = a.size(); vll pre(n + 1, 0); for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    vector<vll> dp(n, vll(n, 0)); vector<vi> opt(n, vi(n, 0));
    for (int i = 0; i < n; i++) opt[i][i] = i;
    for (int len = 2; len <= n; len++)
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1; dp[l][r] = INF;
            for (int k = opt[l][r - 1]; k <= min(r - 1, opt[l + 1][r]); k++) {
                ll v = dp[l][k] + dp[k + 1][r] + pre[r + 1] - pre[l];
                if (v < dp[l][r]) { dp[l][r] = v; opt[l][r] = k; }
            }
        }
    return dp[0][n - 1];
}
