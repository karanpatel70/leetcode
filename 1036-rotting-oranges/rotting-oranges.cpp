class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        // Put all rotten oranges into queue
        // and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // BFS
        while (!q.empty() && fresh > 0) {

            int size = q.size();

            // Process all oranges that are rotten
            // at the beginning of this minute
            for (int i = 0; i < size; i++) {

                auto [x, y] = q.front();
                q.pop();

                // Check 4 directions
                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Check boundary
                    if (nx >= 0 && nx < m &&
                        ny >= 0 && ny < n &&
                        grid[nx][ny] == 1) {

                        // Fresh orange becomes rotten
                        grid[nx][ny] = 2;

                        fresh--;

                        q.push({nx, ny});
                    }
                }
            }

            // One complete BFS level = one minute
            minutes++;
        }

        // If fresh oranges are still remaining
        if (fresh > 0)
            return -1;

        return minutes;
    }
};