class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int mini = INT_MAX;
            int ans = 0 ;
            for (int i = 0; i < n - 2; i++)
            {

               	// int val = target - nums[i];
               	// cout<<val<<endl;
                int start = i + 1;
                int end = n - 1;
                while (start < end)
                {
                    int temp = nums[start] + nums[end] + nums[i];
                    // cout << temp << "  ";
                    if (target == temp)
                    {
                        return target;
                    }
                    else if (target > temp)
                    {
                        start++;
                    }
                    else
                        end--;
                    int ele = abs(target - (nums[i] + nums[start] + nums[end]));
                    // cout << ele << endl;
                    if( mini > ele )
                    {
                        mini = ele ;
                        ans  = temp ;
                    }
                    
                }
            }
            return ans;
        }
};