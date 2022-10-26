class Solution
{
    public:
        long long minCost(vector<int> &nums, vector<int> &cost)
        {
            long long total =0, sum = 0, n = nums.size();
            vector<pair<int, int>> vec;
            for (int i = 0; i < n; i++)
            {
                vec.push_back({ nums[i],cost[i] });
            }
            sort(vec.begin(), vec.end());
            for (int i = 0; i < n; i++)
                sum = sum + (1ll *vec[i].second);
            long long median, i = 0;
            while (total < (sum + 1) / 2 and i < n)
            {
                total = total + (1ll *vec[i].second); 
                median = vec[i].first; i++;
                }
                long long ans = 0;
                for (int i = 0; i < nums.size(); i++)
                {
                    ans = ans + abs(1ll *nums[i] - median) *(1ll *cost[i]);
                }
                return ans;
            }
        };