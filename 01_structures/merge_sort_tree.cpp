// @desc: Merge sort tree: cuantos elementos < k (o <= k) en el rango [l, r)
// @cx: O(n log n) build, O(log^2 n) query
struct MergeSortTree {
    int n; vector<vector<int>> t;
    MergeSortTree(const vector<int>& a = {}) : n(a.size()), t(2 * a.size()) {
        for (int i = 0; i < n; i++) t[n + i] = {a[i]};
        for (int i = n - 1; i > 0; i--) {
            t[i].resize(t[2 * i].size() + t[2 * i + 1].size());
            merge(all(t[2 * i]), all(t[2 * i + 1]), t[i].begin());
        }
    }
    int count_less(int l, int r, int k) { // # de elementos < k en [l, r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { res += lower_bound(all(t[l]), k) - t[l].begin(); l++; }
            if (r & 1) { --r; res += lower_bound(all(t[r]), k) - t[r].begin(); }
        }
        return res;
    }
};
