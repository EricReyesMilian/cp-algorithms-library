// @desc: Factorizacion de Lyndon (Duval) y rotacion minima lexicografica
// @cx: O(n)
vector<string> duval(const string& s) {
    int n = s.size(), i = 0; vector<string> res;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) { if (s[k] < s[j]) k = i; else k++; j++; }
        while (i <= k) { res.push_back(s.substr(i, j - k)); i += j - k; }
    }
    return res;
}
int min_rotation(string s) { // indice de inicio de la menor rotacion
    int n = s.size(); s += s; int i = 0, ans = 0;
    while (i < n) {
        ans = i; int j = i + 1, k = i;
        while (j < 2 * n && s[k] <= s[j]) { if (s[k] < s[j]) k = i; else k++; j++; }
        while (i <= k) i += j - k;
    }
    return ans;
}
