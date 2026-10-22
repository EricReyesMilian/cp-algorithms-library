// @desc: Utilidades enteras: isqrt, icbrt exactos, ceil_div, floor_div, gcd/lcm seguros, mulmod
// @cx: O(1) / O(log)
ll isqrt(ll n) { ll r = sqrtl((long double)n); while (r * r > n) r--; while ((r + 1) * (r + 1) <= n) r++; return r; }
ll icbrt(ll n) { ll r = cbrtl((long double)n); while (r * r * r > n) r--; while ((r + 1) * (r + 1) * (r + 1) <= n) r++; return r; }
ll floor_div(ll a, ll b) { return a / b - ((a % b != 0) && ((a < 0) != (b < 0))); }
ll ceil_div(ll a, ll b) { return floor_div(a + b - 1, b) ; } // b > 0
ll lcm_safe(ll a, ll b) { return a / __gcd(a, b) * b; }
ll mul_mod(ll a, ll b, ll m) { return (ll)((__int128)a * b % m); }
