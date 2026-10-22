// @desc: Suffix array (doubling con counting sort) + LCP (Kasai) + LCP de dos sufijos con sparse table
// @cx: O(n log n)
struct SuffixArray {
    int n; vi sa, rnk, lcp; vector<vi> st; // lcp[i] = LCP(sa[i], sa[i+1])
    static vi sort_cyclic(const string& s) {
        int n = s.size(), cls = 1;
        vi p(n), c(n), cnt(max(256, n), 0);
        for (char ch : s) cnt[(unsigned char)ch]++;
        for (int i = 1; i < 256; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++) p[--cnt[(unsigned char)s[i]]] = i;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) { if (s[p[i]] != s[p[i - 1]]) cls++; c[p[i]] = cls - 1; }
        vi pn(n), cn(n);
        for (int h = 0; (1 << h) < n; h++) {
            for (int i = 0; i < n; i++) { pn[i] = p[i] - (1 << h); if (pn[i] < 0) pn[i] += n; }
            fill(cnt.begin(), cnt.begin() + cls, 0);
            for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
            for (int i = 1; i < cls; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0; cls = 1;
            for (int i = 1; i < n; i++) {
                pii cur = {c[p[i]], c[(p[i] + (1 << h)) % n]}, prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
                if (cur != prev) cls++;
                cn[p[i]] = cls - 1;
            }
            c.swap(cn);
        }
        return p;
    }
    SuffixArray(string s = "") {
        n = s.size(); s += '\0';
        sa = sort_cyclic(s); sa.erase(sa.begin());
        rnk.assign(n, 0); for (int i = 0; i < n; i++) rnk[sa[i]] = i;
        lcp.assign(max(n - 1, 0), 0);
        for (int i = 0, k = 0; i < n; i++) {
            if (rnk[i] == n - 1) { k = 0; continue; }
            int j = sa[rnk[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            lcp[rnk[i]] = k; if (k) k--;
        }
    }
    void build_rmq() {
        int m = lcp.size(); if (!m) return;
        int LG = __lg(m) + 1; st.assign(LG, vi(m)); st[0] = lcp;
        for (int k = 1; k < LG; k++) for (int i = 0; i + (1 << k) <= m; i++) st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
    int lcp_suffix(int a, int b) { // LCP de los sufijos que empiezan en a y b (requiere build_rmq)
        if (a == b) return n - a;
        int l = min(rnk[a], rnk[b]), r = max(rnk[a], rnk[b]) - 1, k = __lg(r - l + 1);
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
    // substrings distintos = n(n+1)/2 - sum(lcp)
};
