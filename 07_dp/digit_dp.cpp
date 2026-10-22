// @desc: Plantilla de digit DP: contar x en [0, N] con una propiedad (ejemplo: suma de digitos == S)
// @cx: O(digitos * estado * 10)
// Cambiar el estado/transicion segun el problema. Cuenta numeros en [0, N] con suma de digitos S.
ll digit_count(ll N, int S) {
    string s = to_string(N); int n = s.size();
    // memo[pos][suma] solo para estados libres (tight = false); lead = ceros a la izquierda no importan aqui
    vector<vll> memo(n + 1, vll(S + 1, -1));
    function<ll(int, int, bool)> go = [&](int pos, int sum, bool tight) -> ll {
        if (sum > S) return 0;
        if (pos == n) return sum == S;
        if (!tight && memo[pos][sum] != -1) return memo[pos][sum];
        int lim = tight ? s[pos] - '0' : 9; ll res = 0;
        for (int d = 0; d <= lim; d++) res += go(pos + 1, sum + d, tight && d == lim);
        if (!tight) memo[pos][sum] = res;
        return res;
    };
    return go(0, 0, true);
}
