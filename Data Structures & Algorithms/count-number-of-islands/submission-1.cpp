class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void bfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < grid.size() &&
                    nc >= 0 && nc < grid[0].size() &&
                    grid[nr][nc] == '1' &&
                    !vis[nr][nc]) {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    bfs(i, j, vis, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};