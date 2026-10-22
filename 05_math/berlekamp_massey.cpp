// @desc: Berlekamp-Massey (recurrencia lineal minima) y k-esimo termino de una recurrencia (mod MOD primo)
// @cx: O(n^2) BM, O(n^2 log k) k-esimo
// Devuelve C tal que s[i] = sum_{j} C[j] * s[i-j-1]
vll berlekamp_massey(vll s) {
    auto pw = [](ll b, ll e) { ll r = 1; b %= MOD; if (b < 0) b += MOD; for (; e; e >>= 1, b = b * b % MOD) if (e & 1) r = r * b % MOD; return r; };
    int n = s.size(), L = 0, m = 0; vll C(n), B(n), T;
    for (auto& x : s) x = ((x % MOD) + MOD) % MOD;
    C[0] = B[0] = 1; ll b = 1;
    for (int i = 0; i < n; i++) {
        ++m; ll d = s[i];
        for (int j = 1; j <= L; j++) d = (d + C[j] * s[i - j]) % MOD;
        if (!d) continue;
        T = C; ll coef = d * pw(b, MOD - 2) % MOD;
        for (int j = m; j < n; j++) C[j] = ((C[j] - coef * B[j - m]) % MOD + MOD) % MOD;
        if (2 * L > i) continue;
        L = i + 1 - L; B = T; b = d; m = 0;
    }
    C.resize(L + 1); C.erase(C.begin());
    for (ll& x : C) x = (MOD - x) % MOD;
    return C;
}
// S[0..n-1] terminos iniciales, tr = coeficientes de la recurrencia; devuelve S[k]
ll linear_rec(const vll& S, const vll& tr, ll k) {
    int n = tr.size(); if (n == 0) return 0;
    auto combine = [&](const vll& a, const vll& b) {
        vll res(n * 2 + 1, 0);
        for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) res[i + j] = (res[i + j] + a[i] * b[j]) % MOD;
        for (int i = 2 * n; i > n; --i) for (int j = 0; j < n; j++) res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % MOD;
        res.resize(n + 1); return res;
    };
    vll pol(n + 1, 0), e(n + 1, 0); pol[0] = e[1] = 1;
    for (++k; k; k /= 2) { if (k % 2) pol = combine(pol, e); e = combine(e, e); }
    ll res = 0;
    for (int i = 0; i < n; i++) res = (res + pol[i + 1] * S[i]) % MOD;
    return res;
}
