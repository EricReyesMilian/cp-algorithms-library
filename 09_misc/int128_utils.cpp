// @desc: Utilidades __int128: impresion, lectura, multiplicacion segura con verificacion de overflow
// @cx: O(digitos)
string i128_to_string(__int128 x) { if (x == 0) return "0"; bool neg = x < 0; if (neg) x = -x; string s; while (x > 0) { s += char('0' + (int)(x % 10)); x /= 10; } if (neg) s += '-'; reverse(all(s)); return s; }
__int128 i128_from_string(const string& s) { __int128 r = 0; bool neg = false; for (char c : s) { if (c == '-') neg = true; else r = r * 10 + (c - '0'); } return neg ? -r : r; }
bool mul_overflow(ll a, ll b, ll& res) { return __builtin_mul_overflow(a, b, &res); }
bool add_overflow(ll a, ll b, ll& res) { return __builtin_add_overflow(a, b, &res); }
