// @desc: Struct Mint<M> con aritmetica modular (+ - * / pow inv), lectura y escritura
// @cx: O(1) por operacion (inv O(log))
template <int M> struct Mint {
    int v = 0;
    Mint() {}
    Mint(ll x) { x %= M; if (x < 0) x += M; v = x; }
    Mint& operator+=(Mint o) { v += o.v; if (v >= M) v -= M; return *this; }
    Mint& operator-=(Mint o) { v -= o.v; if (v < 0) v += M; return *this; }
    Mint& operator*=(Mint o) { v = (ll)v * o.v % M; return *this; }
    Mint& operator/=(Mint o) { return *this *= o.inv(); }
    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
    friend Mint operator/(Mint a, Mint b) { return a /= b; }
    Mint operator-() const { Mint r; r.v = v ? M - v : 0; return r; }
    Mint pow(ll e) const { Mint r(1), b = *this; for (; e > 0; e >>= 1, b *= b) if (e & 1) r *= b; return r; }
    Mint inv() const { return pow(M - 2); } // M primo
    bool operator==(Mint o) const { return v == o.v; }
    bool operator!=(Mint o) const { return v != o.v; }
    friend ostream& operator<<(ostream& o, Mint a) { return o << a.v; }
    friend istream& operator>>(istream& i, Mint& a) { ll x; i >> x; a = Mint(x); return i; }
};
using mint = Mint<MOD>;
