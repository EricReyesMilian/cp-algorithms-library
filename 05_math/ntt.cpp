// @desc: NTT modulo 998244353: multiplicacion de polinomios
// @cx: O(n log n)
namespace NTT {
const int P = 998244353, G = 3;
int pw(int b, int e) { ll r = 1, x = b; for (; e; e >>= 1, x = x * x % P) if (e & 1) r = r * x % P; return r; }
void ntt(vector<int>& a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1; for (; j & bit; bit >>= 1) j ^= bit; j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int w = pw(G, (P - 1) / len); if (inv) w = pw(w, P - 2);
        vector<int> ws(len / 2); ws[0] = 1; for (int i = 1; i < len / 2; i++) ws[i] = (ll)ws[i - 1] * w % P;
        for (int i = 0; i < n; i += len) for (int j = 0; j < len / 2; j++) {
            int u = a[i + j], v = (ll)a[i + j + len / 2] * ws[j] % P;
            a[i + j] = u + v >= P ? u + v - P : u + v;
            a[i + j + len / 2] = u - v < 0 ? u - v + P : u - v;
        }
    }
    if (inv) { ll ni = pw(n, P - 2); for (int& x : a) x = x * ni % P; }
}
vector<int> multiply(vector<int> a, vector<int> b) { // coeficientes en [0, P)
    if (a.empty() || b.empty()) return {};
    int need = a.size() + b.size() - 1, n = 1; while (n < need) n <<= 1;
    a.resize(n); b.resize(n); ntt(a, false); ntt(b, false);
    for (int i = 0; i < n; i++) a[i] = (ll)a[i] * b[i] % P;
    ntt(a, true); a.resize(need); return a;
}
}
