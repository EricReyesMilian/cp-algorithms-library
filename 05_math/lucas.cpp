// @desc: Teorema de Lucas: C(n, k) mod p con p primo pequeno (p ~ 1e6) y n, k grandes
// @cx: O(p) precomputo, O(log_p n) consulta
struct Lucas {
    ll p; vll f, inv_f;
    static ll pw(ll b, ll e, ll m) { ll r = 1; b %= m; for (; e > 0; e >>= 1, b = b * b % m) if (e & 1) r = r * b % m; return r; }
    Lucas(ll p) : p(p), f(p), inv_f(p) {
        f[0] = 1; for (ll i = 1; i < p; i++) f[i] = f[i - 1] * i % p;
        inv_f[p - 1] = pw(f[p - 1], p - 2, p); for (ll i = p - 1; i > 0; i--) inv_f[i - 1] = inv_f[i] * i % p;
    }
    ll small(ll n, ll k) { return k > n ? 0 : f[n] * inv_f[k] % p * inv_f[n - k] % p; }
    ll C(ll n, ll k) { ll r = 1; while (n || k) { r = r * small(n % p, k % p) % p; if (!r) return 0; n /= p; k /= p; } return r; }
};
