// @desc: Plantilla base: headers, typedefs, macros, rng, debug (-DLOCAL), main con multi-test
// @cx: -
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); i--)

const ll INF = (ll)4e18;
const int INFI = 1e9;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
template <class A, class B> ostream& operator<<(ostream& o, const pair<A, B>& p) { return o << "(" << p.first << ", " << p.second << ")"; }
template <class T, class = decltype(begin(declval<T>())), class = enable_if_t<!is_same<T, string>::value>>
ostream& operator<<(ostream& o, const T& c) { o << "{"; bool f = 0; for (auto& x : c) { if (f) o << ", "; f = 1; o << x; } return o << "}"; }
void dbg_out() { cerr << endl; }
template <class H, class... T> void dbg_out(H h, T... t) { cerr << " " << h; dbg_out(t...); }
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
