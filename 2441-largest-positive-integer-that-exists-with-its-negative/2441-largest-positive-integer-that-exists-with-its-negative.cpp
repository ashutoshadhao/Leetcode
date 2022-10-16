class Solution
{
    public:
        int findMaxK(vector<int> &nums)
        {
            unordered_map<int, int> mp;
            for (auto it: nums)
            {
                mp[it]++;
            }
            int ans = -1 ;
            for( int i = 0 ; i < nums.size() ; i++ )
            {
                if( mp[nums[i] * -1 ] and ans < nums[i] )
                {
                    ans = nums[i] ;
                }
            }
            return ans; 
        }
};