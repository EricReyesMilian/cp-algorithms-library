# Indice de la biblioteca


## 00_template

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `gen` | Generador de casos aleatorios para stress test (semilla en argv[1]) | - |
| `template` | Plantilla base: headers, typedefs, macros, rng, debug (-DLOCAL), main con multi-test | - |
| `template_min` | Plantilla minima (sin macros), para empezar rapido | - |

## 01_structures

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `disjoint_sparse_table` | Disjoint sparse table: query O(1) para operaciones asociativas NO idempotentes (suma, producto, ...) | O(n log n) build, O(1) query |
| `dsu` | DSU / Union-Find con compresion de caminos y union por tamano | O(alpha(n)) por operacion |
| `dsu_parity` | DSU con paridad (detecta ciclos impares / grafo bipartito dinamico) | O(log n) amortizado |
| `dsu_rollback` | DSU con rollback (sin compresion de caminos), util en divide&conquer offline | O(log n) por operacion |
| `fenwick` | Fenwick tree (BIT) punto-update, suma de prefijo, busqueda binaria sobre prefijos | O(log n) |
| `fenwick_2d` | Fenwick 2D: update puntual, suma de rectangulo | O(log n * log m) |
| `fenwick_range` | Fenwick con update de rango y query de rango (suma) | O(log n) |
| `hash_custom` | Hash anti-hack para unordered_map/unordered_set y gp_hash_table | O(1) esperado |
| `interval_set` | Conjunto de intervalos disjuntos [L,R): agregar y quitar intervalos (KACTL) | O(log n) amortizado |
| `li_chao` | Li Chao tree dinamico: minimo de funciones lineales en un punto x (rango [lo, hi]) | O(log C) por insercion/query |
| `line_container` | LineContainer (KACTL): maximo de rectas k*x+m, query en cualquier orden (para minimo negar k y m) | O(log n) amortizado |
| `merge_sort_tree` | Merge sort tree: cuantos elementos < k (o <= k) en el rango [l, r) | O(n log n) build, O(log^2 n) query |
| `mo` | Algoritmo de Mo (consultas offline de rango) con orden zig-zag | O((n + q) sqrt(n)) |
| `monotonic` | Ventana deslizante min, next/prev menor-mayor (pila monotona), histograma maximo rectangulo | O(n) |
| `ordered_set` | Ordered set / multiset con pb_ds: order_of_key y find_by_order | O(log n) |
| `segtree` | Segment tree iterativo (bottom-up), operacion asociativa configurable | O(log n) por query/update, O(n) build |
| `segtree_lazy` | Segment tree recursivo con lazy: suma en rango + update de rango (add) | O(log n) por operacion |
| `segtree_lazy_affine` | Seg tree lazy: aplicar x -> m*x+b a un rango, suma en rango (mod MOD) | O(log n) por operacion |
| `segtree_persistent` | Segment tree persistente (versiones) con suma y k-esimo entre dos versiones | O(log n) por update/query, O(n log n) memoria |
| `sparse_table` | Sparse table para RMQ (min) con query O(1); cambiar min por max/gcd | O(n log n) build, O(1) query |
| `sqrt_decomposition` | Descomposicion en bloques: add en rango y suma en rango (plantilla para problemas raros) | O(sqrt n) por operacion |
| `treap` | Treap implicito (secuencia): insertar, borrar, reverse de rango, suma de rango | O(log n) esperado por operacion |
| `xor_trie` | Trie binario: insertar/borrar numeros, maximo XOR con un valor, k-esimo | O(B) por operacion (B = bits) |

## 02_graphs

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `bellman_ford` | Bellman-Ford: caminos minimos con pesos negativos; marca nodos afectados por ciclo negativo | O(V * E) |
| `bfs_01` | BFS 0-1 (pesos 0 o 1) con deque; g[u] = {(v, w)} | O(V + E) |
| `bipartite` | Chequeo de grafo bipartito (2-coloreo con BFS); color[] = 0/1, devuelve false si hay ciclo impar | O(V + E) |
| `block_cut_tree` | Block-cut tree (componentes biconexas por vertices). Nodos >= n son bloques | O(V + E) |
| `bridges_cut` | Puentes, puntos de articulacion y componentes 2-aristo-conexas (maneja multiaristas) | O(V + E) |
| `centroid_decomp` | Centroid decomposition (iterativo para hallar centroides); par[] = padre en el arbol de centroides | O(n log n) |
| `dijkstra` | Dijkstra con heap, reconstruccion de camino; g[u] = {(v, w)} | O((V + E) log V) |
| `dsu_on_tree` | Small-to-large / Sack (DSU on tree): responde sobre el multiconjunto del subarbol de cada nodo | O(n log n) |
| `euler_path` | Camino/ciclo euleriano (Hierholzer iterativo), dirigido o no dirigido | O(V + E) |
| `find_cycle` | Encontrar un ciclo en grafo dirigido (DFS iterativo con colores); devuelve vertices del ciclo o vacio | O(V + E) |
| `floyd_warshall` | Floyd-Warshall todos contra todos, deteccion de ciclos negativos y reconstruccion de camino | O(V^3) |
| `hld` | Heavy-Light Decomposition: consultas de camino/subarbol sobre un segment tree (pos[] = indice) | O(log^2 n) por consulta de camino |
| `kruskal` | MST con Kruskal (DSU interno); aristas (w, u, v) | O(E log E) |
| `lca_binary_lifting` | LCA con binary lifting, k-esimo ancestro y distancia (BFS iterativo) | O(n log n) build, O(log n) query |
| `lca_sparse` | LCA O(1) con sparse table sobre preorden (tin[] util para subarboles y arbol virtual) | O(n log n) build, O(1) query |
| `manhattan_mst` | MST con distancia Manhattan entre puntos (KACTL): genera O(n) aristas candidatas y corre Kruskal | O(n log n) |
| `matrix_tree` | Teorema de Kirchhoff: numero de arboles generadores de un multigrafo (mod MOD primo) | O(n^3) |
| `prim` | MST con Prim (heap); g[u] = {(v, w)}; devuelve -1 si no es conexo | O(E log V) |
| `prufer` | Codigo de Prufer: arbol (aristas) <-> secuencia de n-2 elementos | O(n log n) |
| `rerooting` | Rerooting generico de DP en arboles (por defecto: excentricidad = distancia maxima a otro nodo) | O(n) |
| `scc_kosaraju` | SCC con Kosaraju iterativo (seguro para grafos profundos). comp[] en orden topologico | O(V + E) |
| `scc_tarjan` | Componentes fuertemente conexas (Tarjan, recursivo). comp[] en orden topologico inverso | O(V + E) |
| `spfa` | SPFA (Bellman-Ford con cola); devuelve false si hay ciclo negativo alcanzable | O(V * E) peor caso, rapido en practica |
| `topo_sort` | Orden topologico (Kahn); devuelve vacio si hay ciclo | O(V + E) |
| `tree_diameter` | Diametro de un arbol ponderado (dos recorridos); devuelve (largo, extremo u, extremo v) | O(n) |
| `tree_hash` | Isomorfismo de arboles (AHU con ids canonicos compartidos); enraizado y sin raiz (por centros) | O(n log n) |
| `two_sat` | 2-SAT con SCC (Tarjan). Variable i: literal verdadero 2i, falso 2i+1 | O(n + m) |
| `virtual_tree` | Arbol virtual (auxiliar): comprime un arbol a los nodos dados + sus LCAs. Devuelve aristas (padre, hijo) | O(k log k) |

## 03_flow_matching

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `bipartite_min_path_cover` | Cobertura minima de caminos disjuntos en un DAG (= n - matching) y antichain maximo (Dilworth) via Kuhn | O(V * E) |
| `blossom` | Matching maximo en grafo general (Edmonds / Blossom) | O(V^3) |
| `dinic` | Flujo maximo Dinic (capacidades ll), corte minimo y flujo por arista | O(V^2 E) general, O(E sqrt V) en grafos unitarios/bipartitos |
| `hopcroft_karp` | Matching maximo bipartito (Hopcroft-Karp) + cobertura minima de vertices (Konig) | O(E sqrt V) |
| `hungarian` | Algoritmo hungaro: asignacion de costo minimo (n filas <= m columnas), indices desde 1 | O(n^2 m) |
| `kuhn` | Matching bipartito simple (Kuhn / aumentantes), facil de escribir para n pequenos | O(V * E) |
| `mcmf` | Flujo de costo minimo (SPFA / Bellman-Ford con cola); devuelve (flujo, costo) | O(F * V * E) peor caso |
| `stoer_wagner` | Corte minimo global (Stoer-Wagner) en grafo no dirigido con pesos; devuelve (peso, nodos de un lado) | O(V^3) |

## 04_strings

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `aho_corasick` | Aho-Corasick (alfabeto a-z) con automata completo; cuenta ocurrencias de patrones en un texto | O(suma de patrones * 26 + texto) |
| `kmp_automaton` | Automata KMP (transiciones precomputadas): util para DP sobre strings (alfabeto a-z) | O(n * 26) |
| `lyndon_minrot` | Factorizacion de Lyndon (Duval) y rotacion minima lexicografica | O(n) |
| `manacher` | Manacher: palindromos impares (d1) y pares (d2) por centro | O(n) |
| `palindromic_tree` | Eertree / arbol de palindromos: palindromos distintos y ocurrencias de cada uno | O(n * alfabeto) |
| `prefix_function_kmp` | Funcion prefijo (KMP), busqueda de patron, periodo minimo y conteo de ocurrencias de prefijos | O(n) |
| `string_hash` | Hash polinomial de substrings modulo 2^61-1 con base aleatoria (resistente a hacks) | O(n) build, O(1) query |
| `string_utils` | Utilidades: split, join, trim, to lower/upper, es palindromo, conteo de frecuencias, comparar substrings por hash-less | O(n) |
| `suffix_array` | Suffix array (doubling con counting sort) + LCP (Kasai) + LCP de dos sufijos con sparse table | O(n log n) |
| `suffix_automaton` | Automata de sufijos (alfabeto a-z): substrings distintos, ocurrencias por estado | O(n * alfabeto) |
| `trie` | Trie de strings (a-z): insertar, buscar, contar prefijos | O(|s|) por operacion |
| `z_function` | Z-function: z[i] = LCP de s y s[i..] | O(n) |

## 05_math

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `berlekamp_massey` | Berlekamp-Massey (recurrencia lineal minima) y k-esimo termino de una recurrencia (mod MOD primo) | O(n^2) BM, O(n^2 log k) k-esimo |
| `comb` | Factoriales, nCr, nPr, catalan, inverso de i, estrellas y barras (mod MOD primo) | O(n) precomputo, O(1) consulta |
| `crt` | Teorema chino del resto general (modulos no coprimos): x = a1 (m1), x = a2 (m2) | O(log) |
| `discrete_log` | Logaritmo discreto (BSGS extendido): menor x >= 0 con a^x = b (mod m), m cualquiera | O(sqrt m) |
| `divisors_phi` | Divisores de n, phi de Euler y numero/suma de divisores por factorizacion O(sqrt n) | O(sqrt n) |
| `fft` | FFT compleja (KACTL): convolucion de doubles y convolucion modulo M arbitrario | O(n log n) |
| `floor_sum` | floor_sum: sum_{i=0}^{n-1} floor((a*i + b) / m) (AtCoder Library) | O(log m) |
| `fwht` | Walsh-Hadamard: convolucion XOR / OR / AND de arreglos de tamano 2^k | O(n log n) |
| `gauss_double` | Eliminacion gaussiana con doubles: A x = b (sistema n x m). 0 = sin solucion, 1 = unica, 2 = infinitas | O(n m min(n,m)) |
| `gauss_mod` | Gauss modulo primo MOD: resolver A x = b (0/1/2 soluciones) y determinante | O(n^3) |
| `gauss_xor` | Gauss sobre GF(2) con bitset: sistema de ecuaciones XOR (bit m = termino independiente) | O(n m min(n,m) / 64) |
| `integer_math` | Utilidades enteras: isqrt, icbrt exactos, ceil_div, floor_div, gcd/lcm seguros, mulmod | O(1) / O(log) |
| `lagrange` | Interpolacion de Lagrange en O(n): dado f(0..n) evalua f(x) mod MOD | O(n) |
| `lucas` | Teorema de Lucas: C(n, k) mod p con p primo pequeno (p ~ 1e6) y n, k grandes | O(p) precomputo, O(log_p n) consulta |
| `matrix` | Matriz cuadrada modulo MOD con multiplicacion y exponenciacion (recurrencias lineales) | O(n^3 log e) |
| `miller_rabin_pollard` | Miller-Rabin determinista (64 bits) y factorizacion Pollard-Rho | O(log n) por test, O(n^(1/4)) por factor |
| `modint` | Struct Mint<M> con aritmetica modular (+ - * / pow inv), lectura y escritura | O(1) por operacion (inv O(log)) |
| `modpow_inverse` | Potencia modular, inverso modular (Fermat y euclides extendido), gcd extendido | O(log) |
| `ntt` | NTT modulo 998244353: multiplicacion de polinomios | O(n log n) |
| `primitive_root` | Raiz primitiva modulo un primo p | O(sqrt p + log^2 p) |
| `segmented_sieve` | Criba segmentada: primos en [L, R] con R hasta ~1e12 y R-L ~ 1e7 | O((R-L) log log R + sqrt R) |
| `sieve` | Criba lineal: menor factor primo, primos, phi de Euler, Mobius, factorizacion rapida | O(n) |
| `sqrt_mod` | Raiz cuadrada modular (Tonelli-Shanks): x^2 = a (mod p), p primo; -1 si no existe | O(log^2 p) |

## 06_geometry

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `angle_sort` | Orden polar exacto por angulo (enteros) alrededor del origen, mitad inferior primero | O(n log n) |
| `circles` | Circulos: interseccion circulo-circulo, circulo-recta, circuncentro y circunradio | O(1) |
| `closest_pair` | Par de puntos mas cercano (barrido con set), coordenadas enteras | O(n log n) |
| `convex_hull` | Envolvente convexa (Andrew / monotone chain), sentido antihorario, sin puntos colineales | O(n log n) |
| `half_plane` | Interseccion de semiplanos (ordenar por angulo + deque); agregar caja grande si puede ser no acotada | O(n log n) |
| `lines_segments` | Interseccion de rectas y segmentos, distancia punto-segmento / punto-recta | O(1) |
| `min_enclosing_circle` | Circulo minimo que encierra todos los puntos (Welzl iterativo aleatorizado) | O(n) esperado |
| `point` | Punto 2D generico Pt<T> (ll o ld) con producto punto/cruz, rotacion, sgn; P = tipo por defecto | O(1) |
| `polygon` | Poligono: area*2 con signo, centroide, punto dentro (0 fuera/1 borde/2 dentro), punto en convexo O(log n) | O(n) / O(log n) |
| `rect_union_area` | Area de la union de rectangulos (barrido + segment tree de cobertura) | O(n log n) |
| `rotating_calipers` | Diametro de poligono convexo (rotating calipers) y suma de Minkowski de dos poligonos convexos | O(n) / O(n + m) |

## 07_dp

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `bitmask_tsp` | TSP con DP sobre mascaras (ciclo hamiltoniano de costo minimo) y conteo de caminos hamiltonianos | O(2^n n^2) |
| `dc_optimization` | DP con optimizacion Divide & Conquer: dp[k][i] = min_j dp[k-1][j] + cost(j, i)  (opt monotono) | O(K n log n) |
| `digit_dp` | Plantilla de digit DP: contar x en [0, N] con una propiedad (ejemplo: suma de digitos == S) | O(digitos * estado * 10) |
| `kadane` | Subarreglo de suma maxima (Kadane) con indices, y version circular | O(n) |
| `knapsack` | Mochila 0/1, ilimitada, acotada (division binaria) y subset-sum con bitset | O(n W) / O(n W / 64) |
| `knuth_opt` | Optimizacion de Knuth para DP de intervalos: dp[l][r] = min_k dp[l][k] + dp[k+1][r] + w(l, r) | O(n^2) |
| `lcs_edit` | LCS con reconstruccion, distancia de edicion (Levenshtein), LCS de permutaciones via LIS | O(n m) |
| `lis` | LIS (subsecuencia creciente mas larga) con reconstruccion; estricta o no estricta | O(n log n) |
| `sos_dp` | SOS DP: suma sobre subconjuntos / superconjuntos de mascaras y su inversa (Mobius) | O(n 2^n) |
| `tree_dp_knapsack` | DP en arbol tipo mochila (elegir k nodos con conexion a la raiz) mezclando por tamanos | O(n^2) total (propiedad de mezcla por tamanos) |

## 08_bits

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `bit_tricks` | Trucos de bits: lowbit, popcount, log2, potencias de 2, Gray, inversion de bits, XOR 0..n, subconjuntos, Gosper | O(1) |
| `bitset_utils` | Utilidades de bitset: iterar bits encendidos, primer/siguiente bit, shift-or tipicos | O(N / 64) por operacion |
| `xor_basis` | Base lineal XOR (Gauss sobre bits): insertar, pertenece, maximo XOR, k-esimo menor XOR | O(B) por operacion |

## 09_misc

| Snippet | Descripcion | Complejidad |
|---|---|---|
| `binary_search` | Busqueda binaria sobre la respuesta (entera y real), busqueda ternaria entera y real | O(log rango) |
| `coord_compress` | Compresion de coordenadas (ordenar + unique) con consulta por busqueda binaria | O(n log n) |
| `fast_io` | Lectura/escritura rapida con fread/fwrite (ints, ll, strings) y impresion de __int128 | O(tamano de entrada) |
| `game_theory` | Sprague-Grundy: mex, grundy por DP para juegos con movimientos dados; Nim | O(n * movimientos) |
| `grid_utils` | Utilidades de grilla: direcciones, limites, BFS de distancias, componentes conexas | O(n m) |
| `int128_utils` | Utilidades __int128: impresion, lectura, multiplicacion segura con verificacion de overflow | O(digitos) |
| `inversions` | Contar inversiones (merge sort) y k-esima permutacion (sistema factoradico) | O(n log n) |
| `meet_in_the_middle` | Meet in the middle: contar subconjuntos con suma <= T (n <= ~40) | O(2^(n/2) * n) |
| `prefix_sums` | Sumas de prefijos 1D/2D y arreglos de diferencias (update de rango offline) 1D/2D | O(n) build, O(1) query |
| `random_gen` | Generadores aleatorios para stress tests: enteros, permutaciones, arboles, grafos, strings | O(n) |
| `two_pointers` | Plantilla de dos punteros: subarreglo mas largo con condicion monotona (ejemplo: suma <= K) | O(n) |
