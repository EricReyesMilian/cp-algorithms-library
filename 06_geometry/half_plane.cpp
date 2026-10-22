// @desc: Interseccion de semiplanos (ordenar por angulo + deque); agregar caja grande si puede ser no acotada
// @cx: O(n log n)
// @deps: point
using PD = Pt<ld>;
struct HLine { // semiplano a la izquierda de p -> p + d
    PD p, d;
    bool left(PD q) const { return d.cross(q - p) > EPS; }
    ld ang() const { return atan2l(d.y, d.x); }
};
PD hl_inter(const HLine& a, const HLine& b) { PD u = a.p - b.p; ld t = b.d.cross(u) / a.d.cross(b.d); return a.p + a.d * t; }
vector<PD> half_plane_inter(vector<HLine> L) { // poligono resultante (vacio si no hay area)
    sort(all(L), [](const HLine& a, const HLine& b) { return a.ang() < b.ang(); });
    int n = L.size(), fi_ = 0, la = 0; vector<HLine> q(n); vector<PD> p(n);
    q[0] = L[0];
    for (int i = 1; i < n; i++) {
        while (fi_ < la && !L[i].left(p[la - 1])) la--;
        while (fi_ < la && !L[i].left(p[fi_])) fi_++;
        q[++la] = L[i];
        if (fabsl(q[la].d.cross(q[la - 1].d)) < EPS) {
            la--;
            if (q[la].left(L[i].p)) q[la] = L[i];
        }
        if (fi_ < la) p[la - 1] = hl_inter(q[la - 1], q[la]);
    }
    while (fi_ < la && !q[fi_].left(p[la - 1])) la--;
    if (la - fi_ <= 1) return {};
    p[la] = hl_inter(q[la], q[fi_]);
    return vector<PD>(p.begin() + fi_, p.begin() + la + 1);
}
