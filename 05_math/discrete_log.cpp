// @desc: Logaritmo discreto (BSGS extendido): menor x >= 0 con a^x = b (mod m), m cualquiera
// @cx: O(sqrt m)
ll discrete_log(ll a, ll b, ll m) {
    a %= m; b %= m; if (m == 1) return 0;
    ll k = 1 % m, add = 0, g;
    while ((g = __gcd(a, m)) > 1) {
        if (b == k) return add;
        if (b % g) return -1;
        b /= g; m /= g; add++;
        k = (__int128)k * (a / g) % m;
    }
    ll n = sqrtl((long double)m) + 1, an = 1 % m;
    for (ll i = 0; i < n; i++) an = (__int128)an * a % m;
    unordered_map<ll, ll> vals; ll cur = b;
    for (ll q = 0; q <= n; q++) { vals[cur] = q; cur = (__int128)cur * a % m; }
    cur = k;
    for (ll p = 1; p <= n; p++) {
        cur = (__int128)cur * an % m;
        auto it = vals.find(cur);
        if (it != vals.end()) return n * p - it->second + add;
    }
    return -1;
}
