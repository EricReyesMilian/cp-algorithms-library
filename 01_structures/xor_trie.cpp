// @desc: Trie binario: insertar/borrar numeros, maximo XOR con un valor, k-esimo
// @cx: O(B) por operacion (B = bits)
struct XorTrie {
    static const int B = 30;
    vector<array<int, 2>> ch; vector<int> cnt;
    XorTrie() { ch.push_back({0, 0}); cnt.push_back(0); }
    void insert(int v) {
        int x = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = v >> i & 1, c = ch[x][b];
            if (!c) { c = ch.size(); ch.push_back({0, 0}); cnt.push_back(0); ch[x][b] = c; }
            x = c; cnt[x]++;
        }
    }
    void erase(int v) { // v debe existir
        int x = 0;
        for (int i = B - 1; i >= 0; i--) { x = ch[x][v >> i & 1]; cnt[x]--; }
    }
    int max_xor(int v) { // el conjunto no debe estar vacio
        int x = 0, res = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = (v >> i & 1) ^ 1, c = ch[x][b];
            if (c && cnt[c] > 0) { res |= 1 << i; x = c; } else x = ch[x][b ^ 1];
        }
        return res;
    }
};
