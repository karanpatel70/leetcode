class Solution {
public:
    int li = 0, lj = 0;

    void solve(vector<vector<char>>& grid,
               vector<vector<bool>>& visited,
               int i, int j, int n, int m) {

        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        if (visited[i][j])
            return;

        visited[i][j] = true;
        li = i;
        lj = j;

        if (grid[i][j] == 'R')
            solve(grid, visited, i, j + 1, n, m);
        else if (grid[i][j] == 'L')
            solve(grid, visited, i, j - 1, n, m);
        else if (grid[i][j] == 'U')
            solve(grid, visited, i - 1, j, n, m);
        else
            solve(grid, visited, i + 1, j, n, m);
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        li = 0;
        lj = 0;

        solve(grid, visited, 0, 0, n, m);

        return {li, lj};
    }
};