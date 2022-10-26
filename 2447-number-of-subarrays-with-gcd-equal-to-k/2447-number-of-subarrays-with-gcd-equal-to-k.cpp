class Solution
{
    public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        int n = nums.size(), cnt = 0;
        if (n == 1) return (k == nums[0]) ? 1 : 0;
        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];

            for (int j = i; j < n; j++)
            {
                temp = __gcd(temp, nums[j]);
                if (temp == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};