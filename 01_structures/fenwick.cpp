// @desc: Fenwick tree (BIT) punto-update, suma de prefijo, busqueda binaria sobre prefijos
// @cx: O(log n)
template <class T> struct Fenwick {
    int n; vector<T> t;
    Fenwick(int n = 0) : n(n), t(n + 1, 0) {}
    void add(int i, T v) { for (i++; i <= n; i += i & -i) t[i] += v; }   // 0-indexed
    T query(int i) { T r = 0; for (i++; i > 0; i -= i & -i) r += t[i]; return r; } // suma [0, i]
    T query(int l, int r) { return query(r) - (l ? query(l - 1) : T(0)); }       // suma [l, r]
    int lower_bound(T v) { // menor idx con prefijo >= v (valores >= 0); n si no existe
        int pos = 0;
        for (int pw = 1 << __lg(max(n, 1)); pw; pw >>= 1)
            if (pos + pw <= n && t[pos + pw] < v) { pos += pw; v -= t[pos]; }
        return pos;
    }
};
