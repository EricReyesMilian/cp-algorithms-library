// @desc: Conjunto de intervalos disjuntos [L,R): agregar y quitar intervalos (KACTL)
// @cx: O(log n) amortizado
set<pii>::iterator add_interval(set<pii>& is, int L, int R) {
    if (L == R) return is.end();
    auto it = is.lower_bound({L, R}), before = it;
    while (it != is.end() && it->first <= R) {
        R = max(R, it->second);
        before = it = is.erase(it);
    }
    if (it != is.begin() && (--it)->second >= L) {
        L = min(L, it->first);
        R = max(R, it->second);
        is.erase(it);
    }
    return is.insert(before, {L, R});
}
void remove_interval(set<pii>& is, int L, int R) {
    if (L == R) return;
    auto it = add_interval(is, L, R);
    int r2 = it->second;
    if (it->first == L) is.erase(it);
    else (int&)it->second = L;
    if (R != r2) is.emplace(R, r2);
}
