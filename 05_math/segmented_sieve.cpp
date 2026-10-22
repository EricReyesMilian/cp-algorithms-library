// @desc: Criba segmentada: primos en [L, R] con R hasta ~1e12 y R-L ~ 1e7
// @cx: O((R-L) log log R + sqrt R)
vector<ll> primes_in_range(ll L, ll R) {
    ll lim = sqrtl((long double)R) + 1; vector<bool> sm(lim + 1, true); vector<ll> ps;
    for (ll i = 2; i <= lim; i++) if (sm[i]) { ps.push_back(i); for (ll j = i * i; j <= lim; j += i) sm[j] = false; }
    vector<bool> isp(R - L + 1, true);
    for (ll p : ps) for (ll j = max(p * p, (L + p - 1) / p * p); j <= R; j += p) isp[j - L] = false;
    vector<ll> res;
    for (ll i = max(L, 2LL); i <= R; i++) if (isp[i - L]) res.push_back(i);
    return res;
}
