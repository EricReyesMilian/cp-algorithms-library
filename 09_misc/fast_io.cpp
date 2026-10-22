// @desc: Lectura/escritura rapida con fread/fwrite (ints, ll, strings) y impresion de __int128
// @cx: O(tamano de entrada)
namespace FastIO {
static char ibuf[1 << 25]; size_t ipos = 0, ilen = 0;
inline int gc() { if (ipos == ilen) { ilen = fread(ibuf, 1, sizeof(ibuf), stdin); ipos = 0; if (!ilen) return -1; } return ibuf[ipos++]; }
template <class T> inline bool read(T& x) {
    int c = gc(); while (c != -1 && c != '-' && (c < '0' || c > '9')) c = gc();
    if (c == -1) return false;
    bool neg = false; if (c == '-') { neg = true; c = gc(); }
    x = 0; while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = gc(); }
    if (neg) x = -x; return true;
}
inline bool read(string& s) { int c = gc(); while (c != -1 && isspace(c)) c = gc(); if (c == -1) return false; s.clear(); while (c != -1 && !isspace(c)) { s += (char)c; c = gc(); } return true; }
}
ostream& operator<<(ostream& o, __int128 x) { if (x < 0) { o << '-'; x = -x; } if (x == 0) return o << 0; string s; while (x > 0) { s += char('0' + (int)(x % 10)); x /= 10; } reverse(all(s)); return o << s; }
// uso: FastIO::read(n); FastIO::read(a[i]);
