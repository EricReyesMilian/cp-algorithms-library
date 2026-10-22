// @desc: Walsh-Hadamard: convolucion XOR / OR / AND de arreglos de tamano 2^k
// @cx: O(n log n)
void fwht(vll& a, int type, bool inv) { // type: 0 = xor, 1 = or, 2 = and
    int n = a.size();
    for (int len = 1; len < n; len <<= 1)
        for (int i = 0; i < n; i += 2 * len) for (int j = i; j < i + len; j++) {
            ll u = a[j], v = a[j + len];
            if (type == 0) { a[j] = u + v; a[j + len] = u - v; }
            else if (type == 1) { a[j + len] = inv ? v - u : v + u; }
            else { a[j] = inv ? u - v : u + v; }
        }
    if (type == 0 && inv) for (auto& x : a) x /= n;
}
vll bit_convolution(vll a, vll b, int type) { // tamanos potencia de 2 iguales
    fwht(a, type, false); fwht(b, type, false);
    for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];
    fwht(a, type, true); return a;
}
