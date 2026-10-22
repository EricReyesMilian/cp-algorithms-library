// @desc: floor_sum: sum_{i=0}^{n-1} floor((a*i + b) / m) (AtCoder Library)
// @cx: O(log m)
ull floor_sum_unsigned(ull n, ull m, ull a, ull b) {
    ull ans = 0;
    while (true) {
        if (a >= m) { ans += n * (n - 1) / 2 * (a / m); a %= m; }
        if (b >= m) { ans += n * (b / m); b %= m; }
        ull y_max = a * n + b;
        if (y_max < m) break;
        n = (ull)(y_max / m); b = (ull)(y_max % m);
        swap(m, a);
    }
    return ans;
}
ll floor_sum(ll n, ll m, ll a, ll b) { // m > 0, n >= 0
    ull ans = 0;
    if (a < 0) { ll a2 = ((a % m) + m) % m; ans -= (ull)n * (n - 1) / 2 * (ull)((a2 - a) / m); a = a2; }
    if (b < 0) { ll b2 = ((b % m) + m) % m; ans -= (ull)n * (ull)((b2 - b) / m); b = b2; }
    return (ll)(ans + floor_sum_unsigned(n, m, a, b));
}
