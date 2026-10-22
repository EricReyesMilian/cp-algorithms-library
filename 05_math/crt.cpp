// @desc: Teorema chino del resto general (modulos no coprimos): x = a1 (m1), x = a2 (m2)
// @cx: O(log)
ll crt_egcd(ll a, ll b, ll& x, ll& y) { if (!b) { x = 1; y = 0; return a; } ll x1, y1; ll g = crt_egcd(b, a % b, x1, y1); x = y1; y = x1 - y1 * (a / b); return g; }
// devuelve {x, lcm} con 0 <= x < lcm, o {-1, -1} si no hay solucion
pair<ll, ll> crt(ll a1, ll m1, ll a2, ll m2) {
    a1 = ((a1 % m1) + m1) % m1; a2 = ((a2 % m2) + m2) % m2;
    ll x, y, g = crt_egcd(m1, m2, x, y);
    if ((a2 - a1) % g) return {-1, -1};
    ll m2g = m2 / g, l = m1 / g * m2;
    __int128 k = (__int128)((((a2 - a1) / g) % m2g + m2g) % m2g) * (((x % m2g) + m2g) % m2g) % m2g;
    ll r = (ll)(((__int128)m1 * k + a1) % l); if (r < 0) r += l;
    return {r, l};
}
