class Solution
{
    public:
        void topdown(vector<int> &nums, set<vector< int >> &ans, int i, vector< int > &res)
        {
            if (i == nums.size())
            {
                
                ans.insert(res);
                return;
            }
            res.push_back(nums[i]);
            topdown(nums, ans, i + 1, res);
            res.pop_back();
            topdown(nums, ans, i + 1, res);
        }
    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        set<vector < int>> s;
        vector<int> res;
        sort(nums.begin(),nums.end());
        topdown(nums, s, 0, res);
        vector<vector < int>> ans;
        for (auto it: s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};