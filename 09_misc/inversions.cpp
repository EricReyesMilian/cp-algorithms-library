// @desc: Contar inversiones (merge sort) y k-esima permutacion (sistema factoradico)
// @cx: O(n log n)
ll count_inversions(vector<int> a) {
    int n = a.size(); vector<int> tmp(n);
    function<ll(int, int)> go = [&](int l, int r) -> ll {
        if (r - l <= 1) return 0;
        int m = (l + r) / 2; ll res = go(l, m) + go(m, r);
        int i = l, j = m, k = l;
        while (i < m && j < r) { if (a[i] <= a[j]) tmp[k++] = a[i++]; else { tmp[k++] = a[j++]; res += m - i; } }
        while (i < m) tmp[k++] = a[i++];
        while (j < r) tmp[k++] = a[j++];
        copy(tmp.begin() + l, tmp.begin() + r, a.begin() + l);
        return res;
    };
    return go(0, n);
}
vector<int> kth_permutation(int n, ll k) { // k desde 0, permutacion de 0..n-1 (n <= 20 si k cabe en ll)
    vector<ll> f(n + 1, 1); for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i;
    vector<int> pool(n), res; iota(all(pool), 0);
    for (int i = n - 1; i >= 0; i--) { ll q = k / f[i]; k %= f[i]; res.push_back(pool[q]); pool.erase(pool.begin() + q); }
    return res;
}
