class Solution
{
    public:
        int topdown(int n, vector<vector < int>> &dp, int eggs)
        {
            if (dp[n][eggs] != -1) return dp[n][eggs];
            if (n <= 1) return n;
            if (eggs == 1) return n;
            int mini = INT_MAX;

            for (int i = 1; i < n; i++)
            {
                int ele = max(topdown(i - 1, dp, eggs - 1), topdown(n - i, dp, eggs) )+ 1;
                mini = min(ele, mini);
            }
            return dp[n][eggs] = mini;
        }
    int twoEggDrop(int n)
    {
        vector<vector < int>> dp(n + 1, vector<int> (3, -1));
        return topdown(n, dp, 2);
    }
};