// @desc: Algoritmo de Mo (consultas offline de rango) con orden zig-zag
// @cx: O((n + q) sqrt(n))
struct MoQ { int l, r, id; }; // [l, r] inclusivo
ll cur_ans = 0;
void mo_add(int i) { /* agregar a[i] y actualizar cur_ans */ }
void mo_del(int i) { /* quitar a[i] y actualizar cur_ans */ }
vector<ll> mo(vector<MoQ> qs, int n) {
    int B = max(1, (int)(n / sqrt((double)max<size_t>(1, qs.size()))));
    sort(all(qs), [&](const MoQ& a, const MoQ& b) {
        int x = a.l / B, y = b.l / B;
        if (x != y) return x < y;
        return (x & 1) ? a.r > b.r : a.r < b.r;
    });
    vector<ll> ans(qs.size());
    int L = 0, R = -1;
    for (auto& q : qs) {
        while (L > q.l) mo_add(--L);
        while (R < q.r) mo_add(++R);
        while (L < q.l) mo_del(L++);
        while (R > q.r) mo_del(R--);
        ans[q.id] = cur_ans;
    }
    return ans;
}
