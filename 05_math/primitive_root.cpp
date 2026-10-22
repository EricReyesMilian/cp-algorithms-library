// @desc: Raiz primitiva modulo un primo p
// @cx: O(sqrt p + log^2 p)
ll primitive_root(ll p) {
    if (p == 2) return 1;
    auto pw = [&](ll b, ll e) { ll r = 1; b %= p; for (; e; e >>= 1, b = (__int128)b * b % p) if (e & 1) r = (__int128)r * b % p; return r; };
    vll fac; ll ph = p - 1, n = ph;
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) { fac.push_back(i); while (n % i == 0) n /= i; }
    if (n > 1) fac.push_back(n);
    for (ll g = 2; g < p; g++) {
        bool ok = true;
        for (ll f : fac) if (pw(g, ph / f) == 1) { ok = false; break; }
        if (ok) return g;
    }
    return -1;
}
