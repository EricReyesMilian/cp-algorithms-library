// @desc: Divisores de n, phi de Euler y numero/suma de divisores por factorizacion O(sqrt n)
// @cx: O(sqrt n)
vector<ll> divisors(ll n) {
    vector<ll> d;
    for (ll i = 1; i * i <= n; i++) if (n % i == 0) { d.push_back(i); if (i != n / i) d.push_back(n / i); }
    sort(all(d)); return d;
}
ll euler_phi(ll n) {
    ll r = n;
    for (ll p = 2; p * p <= n; p++) if (n % p == 0) { while (n % p == 0) n /= p; r -= r / p; }
    if (n > 1) r -= r / n;
    return r;
}
vector<pll> factor_trial(ll n) {
    vector<pll> f;
    for (ll p = 2; p * p <= n; p++) if (n % p == 0) { int c = 0; while (n % p == 0) n /= p, c++; f.push_back({p, c}); }
    if (n > 1) f.push_back({n, 1});
    return f;
}
