// @desc: Interpolacion de Lagrange en O(n): dado f(0..n) evalua f(x) mod MOD
// @cx: O(n)
ll lagrange_eval(const vll& y, ll x) { // y[i] = f(i), i = 0..n
    int n = y.size() - 1; x %= MOD; if (x < 0) x += MOD;
    if (x <= n) return y[x] % MOD;
    auto pw = [](ll b, ll e) { ll r = 1; b %= MOD; for (; e; e >>= 1, b = b * b % MOD) if (e & 1) r = r * b % MOD; return r; };
    vll pre(n + 2, 1), suf(n + 2, 1), fact(n + 1, 1);
    for (int i = 0; i <= n; i++) pre[i + 1] = pre[i] * ((x - i + MOD) % MOD) % MOD;
    for (int i = n; i >= 0; i--) suf[i] = suf[i + 1] * ((x - i + MOD) % MOD) % MOD;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    ll res = 0;
    for (int i = 0; i <= n; i++) {
        ll num = pre[i] * suf[i + 1] % MOD;
        ll den = fact[i] * fact[n - i] % MOD;
        ll term = y[i] % MOD * num % MOD * pw(den, MOD - 2) % MOD;
        if ((n - i) & 1) term = (MOD - term) % MOD;
        res = (res + term) % MOD;
    }
    return res;
}
