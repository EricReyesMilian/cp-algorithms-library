// @desc: Criba lineal: menor factor primo, primos, phi de Euler, Mobius, factorizacion rapida
// @cx: O(n)
struct Sieve {
    vi lp, primes, phi, mu;
    Sieve(int n = 1) : lp(n + 1, 0), phi(n + 1, 0), mu(n + 1, 0) {
        phi[1] = mu[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!lp[i]) { lp[i] = i; primes.push_back(i); phi[i] = i - 1; mu[i] = -1; }
            for (int p : primes) {
                if (p > lp[i] || (ll)i * p > n) break;
                lp[i * p] = p;
                phi[i * p] = (p == lp[i]) ? phi[i] * p : phi[i] * (p - 1);
                mu[i * p] = (p == lp[i]) ? 0 : -mu[i];
            }
        }
    }
    bool is_prime(int x) { return x >= 2 && lp[x] == x; }
    vector<pii> factor(int x) { vector<pii> r; while (x > 1) { int p = lp[x], c = 0; while (x % p == 0) x /= p, c++; r.push_back({p, c}); } return r; }
};
