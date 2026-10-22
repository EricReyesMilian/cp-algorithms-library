// @desc: Generador de casos aleatorios para stress test (semilla en argv[1])
// @cx: -
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    mt19937_64 rng(atoi(argv[1]));
    auto rnd = [&](long long a, long long b) { return (long long)(rng() % (b - a + 1)) + a; };
    int n = rnd(1, 8);
    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf("%lld ", rnd(1, 10));
    printf("\n");
}
