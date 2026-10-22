// @desc: Raiz cuadrada modular (Tonelli-Shanks): x^2 = a (mod p), p primo; -1 si no existe
// @cx: O(log^2 p)
ll sqrt_mod(ll a, ll p) {
    a %= p; if (a < 0) a += p;
    if (a == 0) return 0;
    if (p == 2) return a;
    auto mul = [&](ll x, ll y) { return (ll)((__int128)x * y % p); };
    auto pw = [&](ll b, ll e) { ll r = 1; for (; e; e >>= 1, b = mul(b, b)) if (e & 1) r = mul(r, b); return r; };
    if (pw(a, (p - 1) / 2) != 1) return -1;
    if (p % 4 == 3) return pw(a, (p + 1) / 4);
    ll q = p - 1; int s = 0; while (q % 2 == 0) { q /= 2; s++; }
    ll z = 2; while (pw(z, (p - 1) / 2) != p - 1) z++;
    ll c = pw(z, q), x = pw(a, (q + 1) / 2), t = pw(a, q); int m = s;
    while (t != 1) {
        int i = 0; ll tt = t; while (tt != 1) { tt = mul(tt, tt); i++; }
        ll b = c; for (int j = 0; j < m - i - 1; j++) b = mul(b, b);
        x = mul(x, b); c = mul(b, b); t = mul(t, c); m = i;
    }
    return x;
}
