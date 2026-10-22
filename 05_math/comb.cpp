// @desc: Factoriales, nCr, nPr, catalan, inverso de i, estrellas y barras (mod MOD primo)
// @cx: O(n) precomputo, O(1) consulta
struct Comb {
    vll f, inv_f;
    static ll pw(ll b, ll e) { ll r = 1; b %= MOD; for (; e > 0; e >>= 1, b = b * b % MOD) if (e & 1) r = r * b % MOD; return r; }
    Comb(int n = 0) {
        f.assign(n + 1, 1); for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % MOD;
        inv_f.assign(n + 1, 1); inv_f[n] = pw(f[n], MOD - 2);
        for (int i = n; i > 0; i--) inv_f[i - 1] = inv_f[i] * i % MOD;
    }
    ll C(int n, int k) { if (k < 0 || n < 0 || k > n) return 0; return f[n] * inv_f[k] % MOD * inv_f[n - k] % MOD; }
    ll P(int n, int k) { if (k < 0 || n < 0 || k > n) return 0; return f[n] * inv_f[n - k] % MOD; }
    ll inv(int x) { return inv_f[x] * f[x - 1] % MOD; }                  // x >= 1
    ll catalan(int n) { return C(2 * n, n) * inv(n + 1) % MOD; }
    ll stars_bars(int n, int k) { return C(n + k - 1, k - 1); }           // n objetos en k cajas (>= 0)
};
