// @desc: Circulo minimo que encierra todos los puntos (Welzl iterativo aleatorizado)
// @cx: O(n) esperado
// @deps: point
using PD = Pt<ld>;
pair<PD, ld> min_enclosing_circle(vector<PD> ps) {
    shuffle(all(ps), rng);
    auto cc = [](PD A, PD B, PD C) { PD b = C - A, c = B - A; return A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2; };
    PD o = ps[0]; ld r = 0, K = 1 + 1e-8;
    for (int i = 0; i < (int)ps.size(); i++) if ((o - ps[i]).dist() > r * K) {
        o = ps[i]; r = 0;
        for (int j = 0; j < i; j++) if ((o - ps[j]).dist() > r * K) {
            o = (ps[i] + ps[j]) / 2; r = (o - ps[i]).dist();
            for (int k = 0; k < j; k++) if ((o - ps[k]).dist() > r * K) { o = cc(ps[i], ps[j], ps[k]); r = (o - ps[i]).dist(); }
        }
    }
    return {o, r};
}
