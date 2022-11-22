class Solution
{
    public:
        int topdown(int n ,vector<int>&dp)
        {
            if (n == 0)
                return 0;
            if(dp[n] != -1 ) return dp[n];
            int ans = INT_MAX;
            for (int i = 1; i * i <= n; i++)
            {
                ans = min(ans, topdown(n - (i *i) ,dp ) + 1 );
            }
            return dp[n] =  ans;
        }
    int numSquares(int n)
    {
        vector<int> dp(n+1,-1);
        return topdown(n,dp);
    }
};