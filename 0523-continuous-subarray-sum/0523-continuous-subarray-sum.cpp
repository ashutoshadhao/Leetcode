class Solution
{
    public:
        bool checkSubarraySum(vector<int> &nums, int k)
        {
            unordered_map<int, int> mp;
            int prefix = 0;
            mp[0] = -1;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                prefix += nums[i];
                int reminder = prefix % k;
                if (mp.find(reminder) == mp.end() )
                    mp[reminder] = i ;
                else if(i - mp[reminder] > 1)
                {
                    return true;
                }
            }
            return false;
        }
};