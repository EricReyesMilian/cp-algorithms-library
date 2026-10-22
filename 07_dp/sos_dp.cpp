// @desc: SOS DP: suma sobre subconjuntos / superconjuntos de mascaras y su inversa (Mobius)
// @cx: O(n 2^n)
void sos_subsets(vll& f, int n) { for (int i = 0; i < n; i++) for (int m = 0; m < (1 << n); m++) if (m >> i & 1) f[m] += f[m ^ (1 << i)]; }   // f[m] = suma de f[s], s subconjunto de m
void sos_supersets(vll& f, int n) { for (int i = 0; i < n; i++) for (int m = 0; m < (1 << n); m++) if (!(m >> i & 1)) f[m] += f[m | (1 << i)]; } // f[m] = suma de f[s], s superconjunto de m
void inv_sos_subsets(vll& f, int n) { for (int i = 0; i < n; i++) for (int m = 0; m < (1 << n); m++) if (m >> i & 1) f[m] -= f[m ^ (1 << i)]; }
void inv_sos_supersets(vll& f, int n) { for (int i = 0; i < n; i++) for (int m = 0; m < (1 << n); m++) if (!(m >> i & 1)) f[m] -= f[m | (1 << i)]; }
