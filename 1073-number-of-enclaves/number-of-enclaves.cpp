class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Add all boundary land cells to queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // First row, last row, first column, last column
                if ((i == 0 || i == n - 1 ||
                     j == 0 || j == m - 1) &&
                    grid[i][j] == 1) {

                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        // 4 directions: up, down, right, left
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, 1, -1};

        // BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 &&
                    vis[nrow][ncol] == 0) {

                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        // Count land cells which were not reached from boundary
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};