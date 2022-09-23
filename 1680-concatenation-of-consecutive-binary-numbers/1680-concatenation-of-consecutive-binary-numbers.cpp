class Solution
{
    public:

        int concatenatedBinary(int n)
        {
            long long int ans = 0;
            int MOD = 1e9 + 7;
            for (int i = 1; i <= n; i++)
            {
                int len = (int(log2(i)) + 1) % MOD;
                ans = ((ans << len) + i) % MOD;
            }

            return ans;
        }
};