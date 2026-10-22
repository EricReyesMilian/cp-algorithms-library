// @desc: Ventana deslizante min, next/prev menor-mayor (pila monotona), histograma maximo rectangulo
// @cx: O(n)
vector<int> sliding_min(const vector<int>& a, int k) { // min de cada ventana de tamano k
    deque<int> d; vector<int> res;
    for (int i = 0; i < (int)a.size(); i++) {
        while (!d.empty() && a[d.back()] >= a[i]) d.pop_back();
        d.push_back(i);
        if (d.front() <= i - k) d.pop_front();
        if (i >= k - 1) res.push_back(a[d.front()]);
    }
    return res;
}
// nxt[i] = primer j > i con a[j] > a[i] (o n); cambiar comparador para menor
vector<int> next_greater(const vector<int>& a) {
    int n = a.size(); vector<int> res(n, n), st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] < a[i]) { res[st.back()] = i; st.pop_back(); }
        st.push_back(i);
    }
    return res;
}
// area del mayor rectangulo en histograma
ll largest_rectangle(const vector<int>& h) {
    int n = h.size(); ll best = 0; vector<int> st;
    for (int i = 0; i <= n; i++) {
        int cur = i == n ? 0 : h[i];
        while (!st.empty() && h[st.back()] >= cur) {
            ll height = h[st.back()]; st.pop_back();
            int left = st.empty() ? -1 : st.back();
            best = max(best, height * (i - left - 1));
        }
        st.push_back(i);
    }
    return best;
}
