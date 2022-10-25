class Solution
{
    public:
        void moveZeroes(vector<int> &nums)
        {
            int i = 0, j = 0;
            while (i < nums.size() and j < nums.size())
            {
                if (nums[j] != 0 and nums[i] == 0)
                {
                    swap(nums[i], nums[j]);
                    i++;
                }
                else if(nums[j] != 0 and nums[i] != 0 ) 
                {
                    i++ ;
                    j++ ;
                }
                else if(nums[i] != 0 ) i++ ;
                else if (nums[j] == 0) j++;
                
               
            }
        }
};