// @desc: Meet in the middle: contar subconjuntos con suma <= T (n <= ~40)
// @cx: O(2^(n/2) * n)
ll count_subsets_le(const vll& a, ll T) {
    int n = a.size(), h = n / 2;
    auto gen = [&](int l, int r) { vll s = {0}; for (int i = l; i < r; i++) { int k = s.size(); for (int j = 0; j < k; j++) s.push_back(s[j] + a[i]); } sort(all(s)); return s; };
    vll A = gen(0, h), B = gen(h, n); ll res = 0;
    for (ll x : A) res += upper_bound(all(B), T - x) - B.begin();
    return res;
}
