// @desc: Miller-Rabin determinista (64 bits) y factorizacion Pollard-Rho
// @cx: O(log n) por test, O(n^(1/4)) por factor
ull mulmod(ull a, ull b, ull m) { return (__uint128_t)a * b % m; }
ull powmod(ull a, ull e, ull m) { ull r = 1 % m; a %= m; for (; e; e >>= 1, a = mulmod(a, a, m)) if (e & 1) r = mulmod(r, a, m); return r; }
bool is_prime(ull n) {
    if (n < 2) return false;
    static const ull bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (ull p : bases) { if (n % p == 0) return n == p; }
    ull d = n - 1; int s = 0; while (!(d & 1)) { d >>= 1; s++; }
    for (ull a : bases) {
        ull x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int r = 1; r < s; r++) { x = mulmod(x, x, n); if (x == n - 1) { comp = false; break; } }
        if (comp) return false;
    }
    return true;
}
ull pollard_rho(ull n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    while (true) {
        ull x = rng() % n, c = rng() % (n - 1) + 1, y = x, d = 1;
        auto f = [&](ull v) { return (ull)(((__uint128_t)v * v + c) % n); };
        while (d == 1) { x = f(x); y = f(f(y)); d = __gcd(x > y ? x - y : y - x, n); }
        if (d != n) return d;
    }
}
void factor_rec(ull n, vector<ull>& r) {
    if (n == 1) return;
    if (is_prime(n)) { r.push_back(n); return; }
    ull d = pollard_rho(n); factor_rec(d, r); factor_rec(n / d, r);
}
vector<ull> factorize(ull n) { vector<ull> r; factor_rec(n, r); sort(all(r)); return r; } // primos con repeticion
