class Solution {
public:
    void bfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        vis[i][j] = true;
        q.push({i, j});

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            if (r > 0 && grid[r - 1][c] == '1' && !vis[r - 1][c]) {
                vis[r - 1][c] = true;
                q.push({r - 1, c});
            }
            if (r < grid.size() - 1 && grid[r + 1][c] == '1' && !vis[r + 1][c]) {
                vis[r + 1][c] = true;
                q.push({r + 1, c});
            }
            if (c > 0 && grid[r][c - 1] == '1' && !vis[r][c - 1]) {
                vis[r][c - 1] = true;
                q.push({r, c - 1});
            }
            if (c < grid[0].size() - 1 && grid[r][c + 1] == '1' && !vis[r][c + 1]) {
                vis[r][c + 1] = true;
                q.push({r, c + 1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '0') {
                    vis[i][j] = true;
                }
                if (!vis[i][j]) {
                    bfs(i, j, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};