// @desc: Hash polinomial de substrings modulo 2^61-1 con base aleatoria (resistente a hacks)
// @cx: O(n) build, O(1) query
struct StrHash {
    static constexpr ull M = (1ULL << 61) - 1;
    ull B; vector<ull> h, pw;
    static ull mul(ull a, ull b) {
        __uint128_t t = (__uint128_t)a * b;
        ull r = (ull)(t & M) + (ull)(t >> 61);
        return r >= M ? r - M : r;
    }
    StrHash(const string& s = "") {
        B = rng() % (M - 1000) + 500; int n = s.size();
        h.assign(n + 1, 0); pw.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = mul(h[i], B) + (ull)(unsigned char)s[i] + 1;
            if (h[i + 1] >= M) h[i + 1] -= M;
            pw[i + 1] = mul(pw[i], B);
        }
    }
    ull get(int l, int r) const { // hash de s[l, r)
        ull x = h[r] + M - mul(h[l], pw[r - l]);
        return x >= M ? x - M : x;
    }
};
// Para comparar hashes de strings distintos usar la MISMA base B (copiar B al otro objeto)
