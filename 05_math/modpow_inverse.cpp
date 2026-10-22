// @desc: Potencia modular, inverso modular (Fermat y euclides extendido), gcd extendido
// @cx: O(log)
ll power(ll b, ll e, ll m = MOD) { ll r = 1 % m; b %= m; if (b < 0) b += m; for (; e > 0; e >>= 1, b = b * b % m) if (e & 1) r = r * b % m; return r; }
ll ext_gcd(ll a, ll b, ll& x, ll& y) { if (!b) { x = 1; y = 0; return a; } ll x1, y1; ll g = ext_gcd(b, a % b, x1, y1); x = y1; y = x1 - y1 * (a / b); return g; }
ll inv_mod(ll a, ll m) { ll x, y; ll g = ext_gcd(((a % m) + m) % m, m, x, y); if (g != 1) return -1; return (x % m + m) % m; } // m cualquiera, gcd(a,m)=1
