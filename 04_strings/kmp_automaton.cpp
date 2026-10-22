// @desc: Automata KMP (transiciones precomputadas): util para DP sobre strings (alfabeto a-z)
// @cx: O(n * 26)
struct KMPAut {
    int n; vector<array<int, 26>> go; // go[i][c]: nuevo estado desde i al leer c (estado n = match completo)
    KMPAut(const string& p) : n(p.size()), go(p.size() + 1) {
        vi pi(n, 0);
        for (int i = 1; i < n; i++) { int j = pi[i - 1]; while (j > 0 && p[i] != p[j]) j = pi[j - 1]; if (p[i] == p[j]) j++; pi[i] = j; }
        for (int i = 0; i <= n; i++) for (int c = 0; c < 26; c++) {
            if (i < n && p[i] - 'a' == c) go[i][c] = i + 1;
            else go[i][c] = i == 0 ? 0 : go[pi[i - 1]][c];
        }
    }
};
