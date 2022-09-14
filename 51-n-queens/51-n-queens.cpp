class Solution
{
    public:
    bool safe(int n, int row, int col, vector<vector < bool>> &grid)
    {
        // Column Check karega

        for (int i = row - 1; i >= 0; i--)
        {
            if (grid[i][col])
                return false;
        }

        // Left Diagonal

        for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
        {
            if (grid[i][j])
                return false;
        }

        // Right  Diagonal

        for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
        {
            if (grid[i][j])
                return false;
        }
        return true;
    }
    void display(vector<vector < string>> &ans , vector<vector < bool>> &grid, int n )
    {
        vector<string> temp ;
        for(int i = 0 ; i < n ; i++)
        {
            string s ; 
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] )
                    s.push_back('Q');
                else 
                    s.push_back('.');
            }
             temp.push_back(s);
        }
        ans.push_back(temp);
    }
    void NQueen(int n, vector<vector < bool>> &grid, int row , vector<vector < string>> &ans )
    {
        if (row == n)
        {
            display(ans,grid,n);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (safe(n, row, i, grid))
            {
                grid[row][i] = true;
                NQueen(n, grid, row + 1,ans);
                grid[row][i] = false;
            }
        }
    }
    vector<vector < string>> solveNQueens(int n)
    {
        vector<vector < string>> ans;
        vector<vector < bool>> grid(n, vector<bool> (n, false));
        NQueen(n, grid, 0 ,ans );
        return ans;
    }
};