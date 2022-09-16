class Solution
{
    public:
        int topdown(vector<int> &nums, vector<int> &multipliers, int start, int i, vector< vector< int>> &dp)
        {
            if (i == multipliers.size()) return 0;
            
            if (dp[i][start] != INT_MIN) return dp[i][start];
            int end = nums.size() - (i - start) - 1;
            int left = (multipliers[i] *nums[start]) + topdown(nums, multipliers, start + 1, i + 1, dp);
            int right = (multipliers[i] *nums[end]) + topdown(nums, multipliers, start, i + 1, dp);
            return dp[i][start] = max(left, right);
        }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int m = multipliers.size(), n = nums.size();
        vector<vector < int>> dp(m, vector<int> (m, INT_MIN));
        return topdown(nums, multipliers, 0, 0, dp);
    }
};