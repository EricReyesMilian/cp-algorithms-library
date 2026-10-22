// @desc: Eertree / arbol de palindromos: palindromos distintos y ocurrencias de cada uno
// @cx: O(n * alfabeto)
struct Eertree {
    struct Node { int len = 0, link = 0; ll cnt = 0; array<int, 26> nxt; Node() { nxt.fill(-1); } };
    vector<Node> t; string s; int last;
    Eertree() { t.emplace_back(); t[0].len = -1; t.emplace_back(); t[1].len = 0; last = 1; } // 0: raiz imaginaria, 1: raiz vacia
    void add(char ch) {
        s.push_back(ch); int c = ch - 'a', i = s.size() - 1, cur = last;
        while (true) { int l = t[cur].len; if (i - 1 - l >= 0 && s[i - 1 - l] == ch) break; cur = t[cur].link; }
        if (t[cur].nxt[c] != -1) { last = t[cur].nxt[c]; t[last].cnt++; return; }
        int nw = t.size(); t.emplace_back(); t[nw].len = t[cur].len + 2;
        if (t[nw].len == 1) t[nw].link = 1;
        else {
            int p = t[cur].link;
            while (true) { int l = t[p].len; if (i - 1 - l >= 0 && s[i - 1 - l] == ch) break; p = t[p].link; }
            t[nw].link = t[p].nxt[c];
        }
        t[cur].nxt[c] = nw; t[nw].cnt = 1; last = nw;
    }
    void finish() { for (int v = t.size() - 1; v >= 2; v--) t[t[v].link].cnt += t[v].cnt; } // cnt = # ocurrencias totales
    int distinct() { return t.size() - 2; } // palindromos distintos
};
