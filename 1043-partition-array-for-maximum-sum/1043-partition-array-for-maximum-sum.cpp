class Solution
{
    public:
        int topdown(vector<int> &arr, int k, int i, vector<int> &dp)
        {
            if (i == arr.size()) return 0;
            if (dp[i] != -1) return dp[i];

            int sum = 0, maxiSum = INT_MIN, maxiEle = INT_MIN;
            int n = arr.size();
            int len = 0;
            for (int j = i; j < min(i + k, n); j++)
            {
                len++;
                maxiEle = max(arr[j], maxiEle);
                sum = (maxiEle *len) + topdown(arr, k, j + 1, dp);
                maxiSum = max(sum, maxiSum);
            }
            return dp[i] = maxiSum;
        }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return topdown(arr, k, 0, dp);
    }
};