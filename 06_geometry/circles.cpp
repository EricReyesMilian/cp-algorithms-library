// @desc: Circulos: interseccion circulo-circulo, circulo-recta, circuncentro y circunradio
// @cx: O(1)
// @deps: point
using PD = Pt<ld>;
bool circle_inter(PD a, PD b, ld r1, ld r2, pair<PD, PD>* out) { // false si no se cortan
    if (a == b) return false;
    PD vec = b - a; ld d2 = vec.dist2(), sum = r1 + r2, dif = r1 - r2;
    ld p = (d2 + r1 * r1 - r2 * r2) / (d2 * 2), h2 = r1 * r1 - p * p * d2;
    if (sum * sum < d2 || dif * dif > d2) return false;
    PD mid = a + vec * p, per = vec.perp() * sqrtl(max((ld)0, h2) / d2);
    *out = {mid + per, mid - per};
    return true;
}
vector<PD> circle_line_inter(PD c, ld r, PD a, PD b) { // puntos de la recta ab con el circulo
    PD d = b - a, f = a - c;
    ld A = d.dot(d), B = 2 * f.dot(d), Cc = f.dot(f) - r * r, disc = B * B - 4 * A * Cc;
    if (disc < -EPS) return {};
    disc = sqrtl(max((ld)0, disc));
    vector<PD> res = {a + d * ((-B - disc) / (2 * A))};
    if (disc > EPS) res.push_back(a + d * ((-B + disc) / (2 * A)));
    return res;
}
PD circum_center(PD A, PD B, PD C) { PD b = C - A, c = B - A; return A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2; }
ld circum_radius(PD A, PD B, PD C) { return (ld)((B - A).dist() * (C - B).dist() * (A - C).dist()) / fabsl((B - A).cross(C - A)) / 2; }
