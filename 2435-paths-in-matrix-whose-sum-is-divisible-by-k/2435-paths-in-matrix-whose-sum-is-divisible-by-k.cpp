class Solution
{
    public:
        int MOD = 1e9 + 7;
    int topdown(vector<vector < int>> &grid, int k, int n, int m, int sum, vector< vector< vector< int>>> &dp)
    {
        if (m == 0 and n == 0)
        {
            sum += grid[n][m];
            return (sum % k == 0);
        }
        if (dp[n][m][sum] != -1) return dp[n][m][sum];
        int up = 0, left = 0;
        if (n - 1 >= 0)
            up = topdown(grid, k, n - 1, m, (sum + grid[n][m]) % k, dp) % MOD;
        if (m - 1 >= 0)
            left = topdown(grid, k, n, m - 1, (sum + grid[n][m]) % k, dp) % MOD;
        return dp[n][m][sum] = (up + left) % MOD;
    }
    int numberOfPaths(vector<vector < int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector< int>>> dp(n, vector<vector < int>> (m, vector<int> (k + 1, -1)));
        return topdown(grid, k, n - 1, m - 1, 0, dp);
    }
};