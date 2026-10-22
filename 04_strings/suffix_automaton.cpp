// @desc: Automata de sufijos (alfabeto a-z): substrings distintos, ocurrencias por estado
// @cx: O(n * alfabeto)
struct SAM {
    struct State { int len = 0, link = -1; bool clone = false; array<int, 26> nxt; State() { nxt.fill(-1); } };
    vector<State> st; int last = 0;
    SAM(int reserve = 0) { st.reserve(2 * reserve + 2); st.emplace_back(); }
    void extend(char ch) {
        int c = ch - 'a', cur = st.size(); st.emplace_back();
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && st[p].nxt[c] == -1) { st[p].nxt[c] = cur; p = st[p].link; }
        if (p == -1) st[cur].link = 0;
        else {
            int q = st[p].nxt[c];
            if (st[p].len + 1 == st[q].len) st[cur].link = q;
            else {
                int cl = st.size(); st.push_back(st[q]);
                st[cl].len = st[p].len + 1; st[cl].clone = true;
                while (p != -1 && st[p].nxt[c] == q) { st[p].nxt[c] = cl; p = st[p].link; }
                st[q].link = st[cur].link = cl;
            }
        }
        last = cur;
    }
    ll distinct_substrings() { ll r = 0; for (int i = 1; i < (int)st.size(); i++) r += st[i].len - st[st[i].link].len; return r; }
    vll occurrences() { // occ[v] = # de apariciones de las cadenas del estado v
        int m = st.size(); vll occ(m, 0); vi ord(m); iota(all(ord), 0);
        sort(all(ord), [&](int a, int b) { return st[a].len > st[b].len; });
        for (int v = 1; v < m; v++) if (!st[v].clone) occ[v] = 1;
        for (int v : ord) if (st[v].link > 0) occ[st[v].link] += occ[v];
        return occ;
    }
};
