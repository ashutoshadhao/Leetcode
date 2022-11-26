class Solution
{
    public:
        int BinarySearch(vector<vector < int>> &jobs, int i)
        {
            int low = 0;
            int high = i - 1;
            int ans = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if ( jobs[mid][0] <= jobs[i][1] )
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            return ans;
        }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector< int > &profit)
    {
        vector<vector < int>> jobs;
        for (int i = 0; i < startTime.size(); i++)
        {
            jobs.push_back({ endTime[i],
                startTime[i],
                profit[i] });
        }
        sort(jobs.begin(), jobs.end());
        int n = startTime.size();
        vector<int> dp(n, 0);
        dp[0] = jobs[0][2];
        int ans = jobs[0][2];
        for (int i = 1; i < n; i++)
        {
            dp[i] = jobs[i][2];
            int ed = BinarySearch(jobs, i);
            if (ed != -1)
                dp[i] = dp[i] + dp[ed];
            dp[i] = max(dp[i], dp[i - 1]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};