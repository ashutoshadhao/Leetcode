class Solution
{
    public:
        void topdown(vector<int> &nums, vector<vector< int >> &ans, int i, vector< int > &res)
        {
            ans.push_back(res);
            for (int ind = i; ind < nums.size(); ind++)
            {
                if (i != ind and nums[ind] == nums[ind - 1]) continue;
                res.push_back(nums[ind]);
                topdown(nums, ans, ind + 1, res);
                res.pop_back();
            }
        }
    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector < int>> ans;
        vector<int> res;
        sort(nums.begin(), nums.end());
        topdown(nums, ans, 0, res);

        return ans;
    }
};