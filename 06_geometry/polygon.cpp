// @desc: Poligono: area*2 con signo, centroide, punto dentro (0 fuera/1 borde/2 dentro), punto en convexo O(log n)
// @cx: O(n) / O(log n)
// @deps: point
coord_t polygon_area2(const vector<P>& v) { // 2 * area, positivo si es CCW
    coord_t a = v.back().cross(v[0]);
    for (int i = 0; i + 1 < (int)v.size(); i++) a += v[i].cross(v[i + 1]);
    return a;
}
Pt<ld> polygon_centroid(const vector<P>& v) {
    Pt<ld> res(0, 0); ld A = 0;
    for (int i = 0, n = v.size(); i < n; i++) {
        P a = v[i], b = v[(i + 1) % n]; ld c = (ld)a.cross(b);
        res.x += (ld)(a.x + b.x) * c; res.y += (ld)(a.y + b.y) * c; A += c;
    }
    return {res.x / (3 * A), res.y / (3 * A)};
}
bool on_segment(P s, P e, P p) { return sgn(p.cross(s, e)) == 0 && sgn((s - p).dot(e - p)) <= 0; }
int in_polygon(const vector<P>& p, P a) { // 0 = fuera, 1 = en el borde, 2 = dentro
    int cnt = 0, n = p.size();
    for (int i = 0; i < n; i++) {
        P q = p[(i + 1) % n];
        if (on_segment(p[i], q, a)) return 1;
        cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
    }
    return cnt ? 2 : 0;
}
bool in_convex(const vector<P>& p, P q) { // poligono convexo CCW sin colineales, borde inclusive
    int n = p.size();
    if (n < 3) return false;
    if (sgn(p[0].cross(p[1], q)) < 0 || sgn(p[0].cross(p[n - 1], q)) > 0) return false;
    int l = 1, r = n - 1;
    while (r - l > 1) { int m = (l + r) / 2; if (sgn(p[0].cross(p[m], q)) >= 0) l = m; else r = m; }
    return sgn(p[l].cross(p[l + 1], q)) >= 0;
}
