// @desc: Compresion de coordenadas (ordenar + unique) con consulta por busqueda binaria
// @cx: O(n log n)
template <class T> struct Compress {
    vector<T> v;
    Compress(vector<T> a = {}) : v(a) { build(); }
    void add(T x) { v.push_back(x); }
    void build() { sort(all(v)); v.erase(unique(all(v)), v.end()); }
    int get(T x) const { return lower_bound(all(v), x) - v.begin(); }   // indice comprimido de x
    T value(int i) const { return v[i]; }
    int size() const { return v.size(); }
};
