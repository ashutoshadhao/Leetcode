class Solution
{
    public:

        void NQueen(int n, vector<string> &board, int row, vector<vector< string >> &ans, vector< int > &leftRow, vector< int > &upperDiagonal, vector< int > &lowerDiagonal)
        {
            if (row == n)
            {
                ans.push_back(board);
                return;
            }
            for (int col = 0; col < n; col++)
            {
                if (leftRow[col] == 0 and lowerDiagonal[row + col] == 0 and upperDiagonal[n - 1 + row - col] == 0)
                {
                    board[row][col] = 'Q';
                    
                    leftRow[col] = 1;
                    lowerDiagonal[col + row] = 1;
                    upperDiagonal[n - 1 + row - col] = 1;
                    
                    NQueen(n, board, row + 1, ans, leftRow, upperDiagonal, lowerDiagonal);
                    
                    board[row][col] = '.';
                    
                    leftRow[col] = 0;
                    lowerDiagonal[col + row] = 0;
                    upperDiagonal[n - 1 + row - col] = 0;
                }
            }
        }
    vector<vector < string>> solveNQueens(int n)
    {
        vector<vector < string>> ans;
        string s(n, '.');
        vector<string> board(n);
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> leftRow(n, 0), upperDiagonal(2 *n - 1, 0), lowerDiagonal(2 *n - 1, 0);
        NQueen(n, board, 0, ans, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};