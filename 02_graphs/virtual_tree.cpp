// @desc: Arbol virtual (auxiliar): comprime un arbol a los nodos dados + sus LCAs. Devuelve aristas (padre, hijo)
// @cx: O(k log k)
// tin/tout: tiempos de entrada/salida (preorden); lca(u, v): funcion LCA (por ejemplo LCAFast)
template <class L> vector<pii> virtual_tree(vi nodes, const vi& tin, const vi& tout, L lca) {
    auto cmp = [&](int a, int b) { return tin[a] < tin[b]; };
    sort(all(nodes), cmp);
    int k = nodes.size();
    for (int i = 0; i + 1 < k; i++) nodes.push_back(lca(nodes[i], nodes[i + 1]));
    sort(all(nodes), cmp); nodes.erase(unique(all(nodes)), nodes.end());
    vector<pii> edges; vi st;
    for (int v : nodes) {
        while (!st.empty() && !(tin[st.back()] <= tin[v] && tout[v] <= tout[st.back()])) st.pop_back();
        if (!st.empty()) edges.push_back({st.back(), v});
        st.push_back(v);
    }
    return edges;
}
