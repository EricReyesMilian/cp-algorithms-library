// @desc: Matriz cuadrada modulo MOD con multiplicacion y exponenciacion (recurrencias lineales)
// @cx: O(n^3 log e)
struct Matrix {
    int n; vector<vll> a;
    Matrix(int n = 0, bool id = false) : n(n), a(n, vll(n, 0)) { if (id) for (int i = 0; i < n; i++) a[i][i] = 1; }
    Matrix operator*(const Matrix& o) const {
        Matrix r(n);
        for (int i = 0; i < n; i++) for (int k = 0; k < n; k++) if (a[i][k])
            for (int j = 0; j < n; j++) r.a[i][j] = (r.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
        return r;
    }
    Matrix pow(ll e) const { Matrix r(n, true), b = *this; for (; e > 0; e >>= 1, b = b * b) if (e & 1) r = r * b; return r; }
};
