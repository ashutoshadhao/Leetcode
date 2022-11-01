class Solution
{
    public:
        int topdown(vector<vector < int>> &grid, int r, int c)
        {
            if (r == 0 && c == 0 && grid[0][0] == -1) return -1;
            if (r == 0 && c == grid[0].size() - 1 && grid[0][grid[0].size() - 1] == 1) return -1;
            if (r == grid.size() - 1)
            {
                if ( c - 1 >= 0 and grid[r][c] == -1 and grid[r][c - 1] == -1)
                {
                    return c - 1;
                }
                else if ( c + 1 < grid[0].size() and grid[r][c] == 1 and grid[r][c + 1] == 1)
                {
                    return c + 1;
                }
                return -1;
            }

            if (c - 1 >= 0 and grid[r][c] == -1 and grid[r][c - 1] == -1)
            {
                return topdown(grid, r + 1, c - 1);
            }
            else if (c + 1 < grid[0].size() and grid[r][c] == 1 and grid[r][c + 1] == 1)
            {
                return topdown(grid, r + 1, c + 1);
            }
            return -1;
        }
    vector<int> findBall(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m, -1);

        for (int i = 0; i < m; i++)
        {
            ans[i] = topdown(grid, 0, i);
        }
        return ans;
    }
};