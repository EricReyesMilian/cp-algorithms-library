// @desc: Base lineal XOR (Gauss sobre bits): insertar, pertenece, maximo XOR, k-esimo menor XOR
// @cx: O(B) por operacion
struct XorBasis {
    static const int B = 60; ll b[B] = {}; int rank_ = 0;
    bool insert(ll x) { // true si aumento el rango
        for (int i = B - 1; i >= 0; i--) if (x >> i & 1) {
            if (!b[i]) { b[i] = x; rank_++; return true; }
            x ^= b[i];
        }
        return false;
    }
    bool contains(ll x) { for (int i = B - 1; i >= 0; i--) if (x >> i & 1) { if (!b[i]) return false; x ^= b[i]; } return true; }
    ll max_xor(ll x = 0) { for (int i = B - 1; i >= 0; i--) if ((x ^ b[i]) > x) x ^= b[i]; return x; }
    ll kth_smallest(ll k) { // k desde 0 sobre los 2^rank valores distintos del span (0 es el menor)
        vll v; for (int i = 0; i < B; i++) if (b[i]) { for (int j = i - 1; j >= 0; j--) if (b[i] >> j & 1 && b[j]) b[i] ^= b[j]; }
        for (int i = 0; i < B; i++) if (b[i]) v.push_back(b[i]);
        ll r = 0; for (int i = 0; i < (int)v.size(); i++) if (k >> i & 1) r ^= v[i];
        return r;
    }
};
