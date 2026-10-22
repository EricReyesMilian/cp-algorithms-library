// @desc: Trie de strings (a-z): insertar, buscar, contar prefijos
// @cx: O(|s|) por operacion
struct Trie {
    vector<array<int, 26>> ch; vi pref, endc;
    Trie() { new_node(); }
    int new_node() { ch.emplace_back(); ch.back().fill(-1); pref.push_back(0); endc.push_back(0); return ch.size() - 1; }
    void insert(const string& s) {
        int v = 0;
        for (char c : s) {
            int x = c - 'a';
            if (ch[v][x] == -1) { int u = new_node(); ch[v][x] = u; }
            v = ch[v][x]; pref[v]++;
        }
        endc[v]++;
    }
    int count_prefix(const string& s) { // # de strings insertados con prefijo s
        int v = 0;
        for (char c : s) { v = ch[v][c - 'a']; if (v == -1) return 0; }
        return pref[v];
    }
    int count_word(const string& s) {
        int v = 0;
        for (char c : s) { v = ch[v][c - 'a']; if (v == -1) return 0; }
        return endc[v];
    }
};
