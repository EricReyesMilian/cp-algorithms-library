// @desc: LCS con reconstruccion, distancia de edicion (Levenshtein), LCS de permutaciones via LIS
// @cx: O(n m)
string lcs(const string& a, const string& b) {
    int n = a.size(), m = b.size(); vector<vi> dp(n + 1, vi(m + 1, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    string res; int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) { res += a[i - 1]; i--; j--; }
        else if (dp[i - 1][j] >= dp[i][j - 1]) i--; else j--;
    }
    reverse(all(res)); return res;
}
int edit_distance(const string& a, const string& b) {
    int n = a.size(), m = b.size(); vector<vi> dp(n + 1, vi(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
    return dp[n][m];
}
