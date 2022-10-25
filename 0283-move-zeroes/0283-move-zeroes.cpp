class Solution
{
    public:
        void moveZeroes(vector<int> &nums)
        {
            int cnt = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                {

                    for (int j = i + 1; j < n; j++)
                    {
                        if (nums[j] != 0)
                        {
                            swap(nums[i], nums[j]);
                            break; 
                        }
                    }
                    // for (auto it: nums) cout << it << "  ";
                    // cout << endl;
                }
            }
        }
};