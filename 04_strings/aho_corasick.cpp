// @desc: Aho-Corasick (alfabeto a-z) con automata completo; cuenta ocurrencias de patrones en un texto
// @cx: O(suma de patrones * 26 + texto)
struct AhoCorasick {
    vector<array<int, 26>> nxt; vi link, cnt; // cnt[v]: # de patrones que son sufijo del estado v (tras build)
    AhoCorasick() { new_node(); }
    int new_node() { nxt.emplace_back(); nxt.back().fill(-1); cnt.push_back(0); link.push_back(0); return nxt.size() - 1; }
    int add(const string& s) { // devuelve el nodo terminal del patron
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (nxt[v][c] == -1) { int u = new_node(); nxt[v][c] = u; }
            v = nxt[v][c];
        }
        cnt[v]++;
        return v;
    }
    void build() {
        queue<int> q;
        for (int c = 0; c < 26; c++) {
            if (nxt[0][c] == -1) nxt[0][c] = 0;
            else { link[nxt[0][c]] = 0; q.push(nxt[0][c]); }
        }
        while (!q.empty()) {
            int v = q.front(); q.pop(); cnt[v] += cnt[link[v]];
            for (int c = 0; c < 26; c++) {
                int u = nxt[v][c];
                if (u == -1) nxt[v][c] = nxt[link[v]][c];
                else { link[u] = nxt[link[v]][c]; q.push(u); }
            }
        }
    }
    ll count_matches(const string& t) { // total de apariciones de todos los patrones en t
        ll total = 0; int v = 0;
        for (char ch : t) { v = nxt[v][ch - 'a']; total += cnt[v]; }
        return total;
    }
};
