// @desc: Area de la union de rectangulos (barrido + segment tree de cobertura)
// @cx: O(n log n)
ll rect_union_area(const vector<array<ll, 4>>& r) { // {x1, y1, x2, y2} con x1 < x2, y1 < y2
    if (r.empty()) return 0;
    vll ys; for (auto& a : r) { ys.push_back(a[1]); ys.push_back(a[3]); }
    sort(all(ys)); ys.erase(unique(all(ys)), ys.end());
    int m = ys.size() - 1;
    vector<array<ll, 4>> ev;
    for (auto& a : r) { ev.push_back({a[0], 1, a[1], a[3]}); ev.push_back({a[2], -1, a[1], a[3]}); }
    sort(all(ev));
    vi cnt(4 * m + 4, 0); vll len(4 * m + 4, 0);
    function<void(int, int, int, int, int, int)> upd = [&](int x, int l, int rr, int ql, int qr, int v) {
        if (qr <= l || rr <= ql) return;
        if (ql <= l && rr <= qr) cnt[x] += v;
        else { int mid = (l + rr) / 2; upd(2 * x, l, mid, ql, qr, v); upd(2 * x + 1, mid, rr, ql, qr, v); }
        if (cnt[x] > 0) len[x] = ys[rr] - ys[l];
        else len[x] = (rr - l == 1) ? 0 : len[2 * x] + len[2 * x + 1];
    };
    ll area = 0;
    for (size_t i = 0; i < ev.size(); i++) {
        if (i) area += len[1] * (ev[i][0] - ev[i - 1][0]);
        int l = lower_bound(all(ys), ev[i][2]) - ys.begin(), rr = lower_bound(all(ys), ev[i][3]) - ys.begin();
        upd(1, 0, m, l, rr, (int)ev[i][1]);
    }
    return area;
}
