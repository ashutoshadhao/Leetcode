class Solution
{
    public:
        bool safe(int n, int row, int col, vector< string> &board )
        {
           	// Column Check karega
            for (int i = row - 1; i >= 0; i--)
            {
                if (board[i][col] =='Q')
                    return false;
            }
            
           	// Left Diagonal
            for (int i = row - 1, j = col - 1 ; i >= 0 and j >= 0 ; i--, j--)
            {
                if (board[i][j] == 'Q')
                    return false;
            }
            
           	// Right  Diagonal
            for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
            {
                if (board[i][j] == 'Q')
                    return false;
            }
            
            return true;
        }
 
    void NQueen(int n, vector< string> &board, int row, vector< vector< string>> &ans)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (safe(n, row, i, board))
            {
                board[row][i] = 'Q';
                NQueen(n, board, row + 1, ans);
                board[row][i] = '.';
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