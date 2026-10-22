// @desc: Busqueda binaria sobre la respuesta (entera y real), busqueda ternaria entera y real
// @cx: O(log rango)
template <class F> ll bs_first_true(ll lo, ll hi, F ok) { // menor x en [lo, hi] con ok(x) (monotono F..FT..T); hi+1 si ninguno
    while (lo < hi) { ll m = lo + (hi - lo) / 2; if (ok(m)) hi = m; else lo = m + 1; }
    return ok(lo) ? lo : lo + 1;
}
template <class F> ll bs_last_true(ll lo, ll hi, F ok) { // mayor x en [lo, hi] con ok(x) (T..TF..F); lo-1 si ninguno
    while (lo < hi) { ll m = lo + (hi - lo + 1) / 2; if (ok(m)) lo = m; else hi = m - 1; }
    return ok(lo) ? lo : lo - 1;
}
template <class F> double bs_real(double lo, double hi, F ok, int it = 100) { for (int i = 0; i < it; i++) { double m = (lo + hi) / 2; if (ok(m)) hi = m; else lo = m; } return hi; }
template <class F> double ternary_max(double lo, double hi, F f, int it = 100) { for (int i = 0; i < it; i++) { double a = lo + (hi - lo) / 3, b = hi - (hi - lo) / 3; if (f(a) < f(b)) lo = a; else hi = b; } return (lo + hi) / 2; }
template <class F> ll ternary_int_min(ll lo, ll hi, F f) { // f estrictamente unimodal (valle)
    while (hi - lo > 2) { ll m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3; if (f(m1) < f(m2)) hi = m2; else lo = m1; }
    ll best = lo; for (ll x = lo + 1; x <= hi; x++) if (f(x) < f(best)) best = x; return best;
}
