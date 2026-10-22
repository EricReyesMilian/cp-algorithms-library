// @desc: Envolvente convexa (Andrew / monotone chain), sentido antihorario, sin puntos colineales
// @cx: O(n log n)
// @deps: point
vector<P> convex_hull(vector<P> pts) {
    if (pts.size() <= 1) return pts;
    sort(all(pts));
    vector<P> h(pts.size() + 1); int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p : pts) {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}
