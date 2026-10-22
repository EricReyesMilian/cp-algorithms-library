# Biblioteca de algoritmos para concursos (Codeforces / ICPC)

~130 archivos `.cpp` independientes, organizados por tema, listos para usar como snippets de VSCode.

```
00_template/       plantilla, stress test (stress.sh, gen.cpp), tasks.json de VSCode
01_structures/     DSU, Fenwick (1D/2D/rango), segtrees (iterativo, lazy, afin, persistente), sparse tables,
                   Mo, treap, ordered_set, Li Chao, LineContainer, xor trie, merge sort tree, ...
02_graphs/         BFS 0-1, Dijkstra, Bellman-Ford, SPFA, Floyd, topo, SCC, puentes, block-cut, 2-SAT, Euler,
                   MST, LCA (2 versiones), HLD, centroides, rerooting, DSU on tree, hash de arboles, arbol virtual, ...
03_flow_matching/  Dinic, MCMF, Hopcroft-Karp (+Konig), Kuhn, Hungaro, Blossom, Stoer-Wagner, cobertura de caminos
04_strings/        KMP, Z, Manacher, hashing 2^61-1, suffix array + LCP, suffix automaton, Aho-Corasick, trie,
                   eertree, Lyndon/Duval, automata KMP
05_math/           criba, modint, nCr, Lucas, Miller-Rabin + Pollard, CRT, BSGS, raiz primitiva, Tonelli-Shanks,
                   floor_sum, matrices, Gauss (double/mod/xor), FFT, NTT, FWHT, Lagrange, Berlekamp-Massey, ...
06_geometry/       punto, envolvente convexa, poligonos, segmentos/rectas, par mas cercano, semiplanos, circulos,
                   circulo minimo, rotating calipers, Minkowski, orden polar, union de rectangulos
07_dp/             LIS, mochilas, SOS, digit DP, D&C opt, Knuth, TSP bitmask, LCS/edicion, Kadane, DP en arboles
08_bits/           trucos de bits, base XOR, utilidades de bitset
09_misc/           fast IO, busquedas binaria/ternaria, compresion, generadores aleatorios, __int128, Grundy,
                   inversiones, prefijos 2D, grillas, meet in the middle, dos punteros
```
Ver `INDEX.md` para la lista completa con descripcion y complejidad.

## Convencion
Cada archivo asume la plantilla `00_template/template.cpp` (`ll`, `vi`, `vll`, `pii`, `all`, `sz`, `INF`, `MOD`, `rng`, ...).
Todos los archivos son autocontenidos: no hay que pegar nada mas, salvo los marcados con `// @deps:` (geometria usa `point`),
cuyas dependencias se incluyen automaticamente en el snippet.
Si dos archivos definen el mismo nombre (por ejemplo `Line` en `line_container` y otros), renombra uno.

## Snippets de VSCode
```bash
python3 build_snippets.py --install      # genera e instala en la carpeta de snippets de usuario (Linux/macOS/Windows)
python3 build_snippets.py --workspace    # o solo para el proyecto actual (./.vscode/)
```
Tambien puedes copiar `cp.code-snippets` a mano:
- Linux: `~/.config/Code/User/snippets/`   macOS: `~/Library/Application Support/Code/User/snippets/`   Windows: `%APPDATA%\Code\User\snippets\`

Uso: escribe el nombre del archivo (`dsu`, `dinic`, `suffix_array`, `template`...) y pulsa Tab/Enter (o Ctrl+Espacio).
Si no sale la sugerencia, en `settings.json`: `"editor.tabCompletion": "on"` y `"editor.quickSuggestions": {"other": true, "strings": true}`.
Para archivos con dependencias, `nombre` incluye las dependencias y `nombre_nd` no (para evitar duplicados).
El prefijo de la plantilla es `template` (y `template_min`).

## Anadir tus propios algoritmos
Crea `carpeta/mi_algoritmo.cpp` con la cabecera
```cpp
// @desc: descripcion corta
// @cx: complejidad
// @deps: otro_archivo   (opcional)
```
y vuelve a ejecutar `build_snippets.py --install`.

## Verificacion
- `python3 check_compile.py` compila cada archivo (con plantilla y deps) con `g++ -std=c++17`.
- `tests/` contiene pruebas contra fuerza bruta (`python3 tests/run_test.py stem1,stem2 tests/t4.cpp`) de las estructuras,
  grafos, flujos, strings, matematica y geometria principales.
