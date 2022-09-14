class Solution
{
    public:
        bool safe(int n, int col, int row, vector<string> &board)
        {
            int duprow = row;
            int dupcol = col;

            while (row >= 0 && col >= 0)
            {
                if (board[row][col] == 'Q')
                    return false;
                row--;
                col--;
            }

            col = dupcol;
            row = duprow;
            while (col >= 0)
            {
                if (board[row][col] == 'Q')
                    return false;
                col--;
            }

            row = duprow;
            col = dupcol;
            while (row < n && col >= 0)
            {
                if (board[row][col] == 'Q')
                    return false;
                row++;
                col--;
            }
            return true;
        }
    void NQueen(int n, vector<string> &board, int col, vector<vector< string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (safe(n, col, row, board))
            {
                board[row][col] = 'Q';
                NQueen(n, board, col + 1, ans);
                board[row][col] = '.';
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
        NQueen(n, board, 0, ans);
        return ans;
    }
};