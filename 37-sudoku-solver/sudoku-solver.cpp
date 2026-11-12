class Solution {
public:

    bool isValid(vector<vector<char>>& board,
                 int row, int col, char num) {

        for (int i = 0; i < 9; i++) {

            // Check row
            if (board[row][i] == num)
                return false;

            // Check column
            if (board[i][col] == num)
                return false;

            // Check 3 x 3 box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;

            if (board[boxRow][boxCol] == num)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    for (char num = '1'; num <= '9'; num++) {

                        if (isValid(board, row, col, num)) {

                            // Choose
                            board[row][col] = num;

                            // Explore
                            if (solve(board))
                                return true;

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

