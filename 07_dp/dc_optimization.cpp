// @desc: DP con optimizacion Divide & Conquer: dp[k][i] = min_j dp[k-1][j] + cost(j, i)  (opt monotono)
// @cx: O(K n log n)
// Definir cost(j, i): costo de un grupo (j, i]. Requiere opt[i] <= opt[i+1]
ll cost(int j, int i);  // <-- IMPLEMENTAR
vll dp_prev, dp_cur;
void dc_compute(int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l + r) / 2; pair<ll, int> best = {INF, -1};
    for (int j = optl; j <= min(mid - 1, optr); j++) {
        ll v = dp_prev[j] + cost(j, mid);
        if (v < best.first) best = {v, j};
    }
    dp_cur[mid] = best.first;
    dc_compute(l, mid - 1, optl, best.second); dc_compute(mid + 1, r, best.second, optr);
}
// uso: dp_prev[0]=0, resto INF; for k in 1..K: dp_cur.assign(n+1, INF); dc_compute(1, n, 0, n-1); swap(dp_prev, dp_cur);
