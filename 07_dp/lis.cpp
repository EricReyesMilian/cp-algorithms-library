// @desc: LIS (subsecuencia creciente mas larga) con reconstruccion; estricta o no estricta
// @cx: O(n log n)
vector<int> lis(const vector<int>& a, bool strict = true) { // devuelve los indices de una LIS
    int n = a.size(); vector<int> d, id, par(n, -1); // d[k] = menor cola de longitud k+1 (valores), id[k] = su indice
    for (int i = 0; i < n; i++) {
        int k = (strict ? lower_bound(all(d), a[i]) : upper_bound(all(d), a[i])) - d.begin();
        if (k == (int)d.size()) { d.push_back(a[i]); id.push_back(i); } else { d[k] = a[i]; id[k] = i; }
        par[i] = k ? id[k - 1] : -1;
    }
    vector<int> res;
    for (int i = id.empty() ? -1 : id.back(); i != -1; i = par[i]) res.push_back(i);
    reverse(all(res)); return res;
}
