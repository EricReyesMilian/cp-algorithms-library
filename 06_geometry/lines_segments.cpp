// @desc: Interseccion de rectas y segmentos, distancia punto-segmento / punto-recta
// @cx: O(1)
// @deps: point
// {1, p}: un punto, {0, -}: paralelas distintas, {-1, -}: la misma recta (requiere P con reales para punto exacto)
pair<int, P> line_inter(P s1, P e1, P s2, P e2) {
    auto d = (e1 - s1).cross(e2 - s2);
    if (sgn(d) == 0) return {-(sgn(s1.cross(e1, s2)) == 0), P(0, 0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}
vector<P> seg_inter(P a, P b, P c, P d) { // 0, 1 o 2 puntos (segmentos colineales solapados)
    auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) return {(a * ob - b * oa) / (ob - oa)};
    set<P> s;
    auto on = [&](P s0, P e0, P p) { return sgn(p.cross(s0, e0)) == 0 && sgn((s0 - p).dot(e0 - p)) <= 0; };
    if (on(c, d, a)) s.insert(a);
    if (on(c, d, b)) s.insert(b);
    if (on(a, b, c)) s.insert(c);
    if (on(a, b, d)) s.insert(d);
    return {s.begin(), s.end()};
}
double seg_dist(P s, P e, P p) {
    if (s == e) return (p - s).dist();
    double d = (double)(e - s).dist2(), t = min(d, max(0.0, (double)(p - s).dot(e - s)));
    double cx = (double)(p.x - s.x) * d - (double)(e.x - s.x) * t, cy = (double)(p.y - s.y) * d - (double)(e.y - s.y) * t;
    return hypot(cx, cy) / d;
}
double line_dist(P a, P b, P p) { return fabs((double)a.cross(b, p)) / (b - a).dist(); }
