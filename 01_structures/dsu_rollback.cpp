// @desc: DSU con rollback (sin compresion de caminos), util en divide&conquer offline
// @cx: O(log n) por operacion
struct RollbackDSU {
    vector<int> e; vector<array<int, 4>> st;
    RollbackDSU(int n = 0) : e(n, -1) {}
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    bool same(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int snapshot() { return st.size(); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a], b, e[b]});
        e[a] += e[b]; e[b] = a;
        return true;
    }
    void rollback(int t) {
        while ((int)st.size() > t) {
            auto& s = st.back();
            e[s[0]] = s[1]; e[s[2]] = s[3];
            st.pop_back();
        }
    }
};
