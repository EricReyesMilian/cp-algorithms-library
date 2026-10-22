// @desc: Mochila 0/1, ilimitada, acotada (division binaria) y subset-sum con bitset
// @cx: O(n W) / O(n W / 64)
ll knap01(const vi& w, const vll& v, int W) {
    vll dp(W + 1, 0);
    for (int i = 0; i < (int)w.size(); i++) for (int c = W; c >= w[i]; c--) dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
    return dp[W];
}
ll knap_unbounded(const vi& w, const vll& v, int W) {
    vll dp(W + 1, 0);
    for (int i = 0; i < (int)w.size(); i++) for (int c = w[i]; c <= W; c++) dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
    return dp[W];
}
ll knap_bounded(const vi& w, const vll& v, const vi& cnt, int W) { // cnt[i] copias del item i
    vll dp(W + 1, 0);
    for (int i = 0; i < (int)w.size(); i++) {
        int k = cnt[i];
        for (int p = 1; k > 0; p <<= 1) {
            int t = min(p, k); k -= t; ll ww = (ll)w[i] * t, vv = v[i] * t;
            for (ll c = W; c >= ww; c--) dp[c] = max(dp[c], dp[c - ww] + vv);
        }
    }
    return dp[W];
}
template <int N> bitset<N> subset_sums(const vi& a) { bitset<N> b; b[0] = 1; for (int x : a) b |= b << x; return b; } // N > suma total
