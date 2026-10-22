// @desc: Utilidades: split, join, trim, to lower/upper, es palindromo, conteo de frecuencias, comparar substrings por hash-less
// @cx: O(n)
vector<string> split(const string& s, char d = ' ') {
    vector<string> r; string cur;
    for (char c : s) { if (c == d) { r.push_back(cur); cur.clear(); } else cur += c; }
    r.push_back(cur); return r;
}
string join(const vector<string>& v, const string& sep) {
    string r; for (size_t i = 0; i < v.size(); i++) { if (i) r += sep; r += v[i]; } return r;
}
string trim(const string& s) {
    size_t a = s.find_first_not_of(" \t\r\n"); if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n"); return s.substr(a, b - a + 1);
}
string to_lower(string s) { for (auto& c : s) c = tolower(c); return s; }
string to_upper(string s) { for (auto& c : s) c = toupper(c); return s; }
bool is_palindrome(const string& s) { return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()); }
