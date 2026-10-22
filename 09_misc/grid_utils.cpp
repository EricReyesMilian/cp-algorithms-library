// @desc: Utilidades de grilla: direcciones, limites, BFS de distancias, componentes conexas
// @cx: O(n m)
const int dx4[] = {1, -1, 0, 0}, dy4[] = {0, 0, 1, -1};
const int dx8[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy8[] = {1, 0, -1, 1, -1, 1, 0, -1};
vector<vi> grid_bfs(const vector<string>& g, int sx, int sy, char wall = '#') { // -1 = inalcanzable
    int n = g.size(), m = g[0].size(); vector<vi> d(n, vi(m, -1)); queue<pii> q;
    d[sx][sy] = 0; q.push({sx, sy});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx4[k], ny = y + dy4[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == wall || d[nx][ny] != -1) continue;
            d[nx][ny] = d[x][y] + 1; q.push({nx, ny});
        }
    }
    return d;
}
int grid_components(const vector<string>& g, char wall = '#') {
    int n = g.size(), m = g[0].size(), c = 0; vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!vis[i][j] && g[i][j] != wall) {
        c++; vector<pii> st = {{i, j}}; vis[i][j] = true;
        while (!st.empty()) {
            auto [x, y] = st.back(); st.pop_back();
            for (int k = 0; k < 4; k++) { int nx = x + dx4[k], ny = y + dy4[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && g[nx][ny] != wall) { vis[nx][ny] = true; st.push_back({nx, ny}); } }
        }
    }
    return c;
}
