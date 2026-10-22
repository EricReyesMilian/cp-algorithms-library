// @desc: Plantilla de dos punteros: subarreglo mas largo con condicion monotona (ejemplo: suma <= K)
// @cx: O(n)
int longest_subarray_sum_le(const vll& a, ll K) { // elementos no negativos
    int best = 0; ll s = 0;
    for (int l = 0, r = 0; r < (int)a.size(); r++) {
        s += a[r];
        while (s > K) s -= a[l++];
        best = max(best, r - l + 1);
    }
    return best;
}
