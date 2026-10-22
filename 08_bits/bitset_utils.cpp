// @desc: Utilidades de bitset: iterar bits encendidos, primer/siguiente bit, shift-or tipicos
// @cx: O(N / 64) por operacion
// for (int i = b._Find_first(); i < (int)b.size(); i = b._Find_next(i)) { ... }   // itera bits en 1
// b |= b << x;            // subset sum / alcanzabilidad
// (a & b).count();        // tamano de interseccion
// bitset<N> mask = (bitset<N>(1) << k) - 1;  // k bits bajos encendidos
template <size_t N> vector<int> bits_on(const bitset<N>& b) {
    vector<int> r; for (int i = b._Find_first(); i < (int)N; i = b._Find_next(i)) r.push_back(i); return r;
}
