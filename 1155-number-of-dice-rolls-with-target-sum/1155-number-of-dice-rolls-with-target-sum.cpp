class Solution
{
    public:
        int MOD = 1e9 + 7;
    int topdown(int dice, int k, int target , vector<vector<int>>&dp)
    {
        if (dice == 0 and target == 0) return 1;
        if (dice == 0 or target <= 0) return 0;
        if(dp[dice][target] != -1 ) return dp[dice][target] ; 
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            sum = ((sum % MOD + topdown(dice - 1, k, target - i ,dp) % MOD)) % MOD;
        }
        return dp[dice][target] = sum ;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1)) ;
        return topdown(n, k, target , dp );
    }
};