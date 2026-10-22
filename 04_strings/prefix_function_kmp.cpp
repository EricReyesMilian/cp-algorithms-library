// @desc: Funcion prefijo (KMP), busqueda de patron, periodo minimo y conteo de ocurrencias de prefijos
// @cx: O(n)
vector<int> prefix_function(const string& s) {
    int n = s.size(); vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
vector<int> kmp_find(const string& t, const string& p) { // posiciones de inicio de p en t
    string s = p + '\0' + t; auto pi = prefix_function(s); vector<int> res;
    for (int i = (int)p.size() + 1; i < (int)s.size(); i++)
        if (pi[i] == (int)p.size()) res.push_back(i - 2 * (int)p.size());
    return res;
}
int min_period(const string& s) { int n = s.size(); auto pi = prefix_function(s); int p = n - pi[n - 1]; return n % p == 0 ? p : n; }
