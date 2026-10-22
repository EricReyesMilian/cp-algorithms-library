// @desc: Sprague-Grundy: mex, grundy por DP para juegos con movimientos dados; Nim
// @cx: O(n * movimientos)
int mex(const vector<int>& v) { vector<bool> s(v.size() + 2, false); for (int x : v) if (x < (int)s.size()) s[x] = true; int m = 0; while (s[m]) m++; return m; }
// grundy[i] = mex{ grundy[i - mv] : mv en moves, i - mv >= 0 }  (juego de una pila de tamano i)
vector<int> grundy_table(int n, const vector<int>& moves) {
    vector<int> g(n + 1, 0);
    for (int i = 1; i <= n; i++) { vector<int> nx; for (int m : moves) if (i >= m) nx.push_back(g[i - m]); g[i] = mex(nx); }
    return g;
}
// Suma de juegos: XOR de grundy. Nim: gana el primero si XOR de pilas != 0.
// Misere Nim: igual salvo que si todas las pilas <= 1 gana el primero si la cantidad de pilas es par.
