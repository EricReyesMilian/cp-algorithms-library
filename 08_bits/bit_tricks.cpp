// @desc: Trucos de bits: lowbit, popcount, log2, potencias de 2, Gray, inversion de bits, XOR 0..n, subconjuntos, Gosper
// @cx: O(1)
inline int popcnt(ll x) { return __builtin_popcountll(x); }
inline int ctz_(ll x) { return __builtin_ctzll(x); }               // x != 0
inline int log2_floor(ll x) { return 63 - __builtin_clzll(x); }    // x > 0
inline ll lowbit(ll x) { return x & -x; }
inline bool is_pow2(ll x) { return x > 0 && !(x & (x - 1)); }
inline ll next_pow2(ll x) { return x <= 1 ? 1 : 1LL << (64 - __builtin_clzll(x - 1)); }
inline ll gray(ll x) { return x ^ (x >> 1); }
inline ll gray_inv(ll g) { ll x = 0; for (; g; g >>= 1) x ^= g; return x; }
inline unsigned rev_bits32(unsigned x) { x = ((x >> 1) & 0x55555555u) | ((x & 0x55555555u) << 1); x = ((x >> 2) & 0x33333333u) | ((x & 0x33333333u) << 2); x = ((x >> 4) & 0x0F0F0F0Fu) | ((x & 0x0F0F0F0Fu) << 4); x = ((x >> 8) & 0x00FF00FFu) | ((x & 0x00FF00FFu) << 8); return (x >> 16) | (x << 16); }
ll xor_upto(ll n) { switch (n & 3) { case 0: return n; case 1: return 1; case 2: return n + 1; default: return 0; } } // 0 ^ 1 ^ ... ^ n
ll count_bit_upto(ll n, int b) { // cuantos x en [0, n] tienen el bit b encendido
    ll full = (n + 1) >> (b + 1) << b, rem = (n + 1) & ((1LL << (b + 1)) - 1);
    return full + max(0LL, rem - (1LL << b));
}
// subconjuntos de una mascara m (incluye 0):   for (int s = m; ; s = (s - 1) & m) { ...; if (!s) break; }
// mascaras de n bits con k bits (Gosper):      for (int x = (1 << k) - 1; x < (1 << n); ) { ...; int c = x & -x, r = x + c; x = (((r ^ x) >> 2) / c) | r; }
// todos los submasks de todas las mascaras: O(3^n)
