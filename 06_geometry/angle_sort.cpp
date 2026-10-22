// @desc: Orden polar exacto por angulo (enteros) alrededor del origen, mitad inferior primero
// @cx: O(n log n)
// @deps: point
int half_of(P p) { return p.y < 0 || (p.y == 0 && p.x < 0); } // 0: angulo en [0, pi), 1: [pi, 2pi)
bool angle_cmp(const P& a, const P& b) {
    if (half_of(a) != half_of(b)) return half_of(a) < half_of(b);
    return a.cross(b) > 0;
}
// sort(v.begin(), v.end(), angle_cmp);
