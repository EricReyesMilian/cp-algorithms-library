// @desc: Diametro de poligono convexo (rotating calipers) y suma de Minkowski de dos poligonos convexos
// @cx: O(n) / O(n + m)
// @deps: point
array<P, 2> hull_diameter(vector<P> S) { // S = envolvente convexa CCW (ll)
    int n = S.size(), j = n < 2 ? 0 : 1;
    pair<ll, array<P, 2>> res({0, {S[0], S[0]}});
    for (int i = 0; i < j; i++)
        for (;; j = (j + 1) % n) {
            res = max(res, {(ll)(S[i] - S[j]).dist2(), {S[i], S[j]}});
            if ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0) break;
        }
    return res.second;
}
void reorder_poly(vector<P>& p) { rotate(p.begin(), min_element(all(p), [](const P& a, const P& b) { return make_pair(a.y, a.x) < make_pair(b.y, b.x); }), p.end()); }
vector<P> minkowski(vector<P> a, vector<P> b) { // ambos convexos CCW
    reorder_poly(a); reorder_poly(b);
    a.push_back(a[0]); a.push_back(a[1]); b.push_back(b[0]); b.push_back(b[1]);
    vector<P> res; size_t i = 0, j = 0;
    while (i < a.size() - 2 || j < b.size() - 2) {
        res.push_back(a[i] + b[j]);
        auto c = sgn((a[i + 1] - a[i]).cross(b[j + 1] - b[j]));
        if (c >= 0 && i < a.size() - 2) ++i;
        if (c <= 0 && j < b.size() - 2) ++j;
    }
    return res;
}
