// @desc: Subarreglo de suma maxima (Kadane) con indices, y version circular
// @cx: O(n)
tuple<ll, int, int> kadane(const vll& a) { // (suma, l, r) subarreglo no vacio
    ll best = a[0], cur = 0; int bl = 0, br = 0, l = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (cur <= 0) { cur = 0; l = i; }
        cur += a[i];
        if (cur > best) { best = cur; bl = l; br = i; }
    }
    return {best, bl, br};
}
ll max_circular_subarray(const vll& a) {
    ll tot = accumulate(all(a), 0LL), mx = get<0>(kadane(a));
    vll b(a); for (auto& x : b) x = -x;
    ll mn = -get<0>(kadane(b));
    return (tot == mn) ? mx : max(mx, tot - mn);
}
