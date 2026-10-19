class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> cell(n * n + 1);
        int label = 1;
        bool leftToRight = true;

        // Map boustrophedon square labels to board values.
        for (int r = n - 1; r >= 0; --r) {
            if (leftToRight) {
                for (int c = 0; c < n; ++c)
                    cell[label++] = board[r][c];
            } else {
                for (int c = n - 1; c >= 0; --c)
                    cell[label++] = board[r][c];
            }
            leftToRight = !leftToRight;
        }

        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int s = q.front();
            q.pop();

            if (s == n * n) return dist[s];

            for (int roll = 1; roll <= 6 && s + roll <= n * n; ++roll) {
                int next = s + roll;
                if (cell[next] != -1)
                    next = cell[next];

                if (dist[next] == -1) {
                    dist[next] = dist[s] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};