class Solution
{
    public:
        void topdown(vector<int> &candidates, int i, int target, vector<vector< int >> &ans, vector< int > &res)
        {

            if (target == 0)
            {
                ans.push_back(res);
                return;
            }
            for (int ind = i; ind < candidates.size(); ind++)
            {
                if (ind != i and candidates[ind - 1] == candidates[ind]) continue;
                if (target >= candidates[ind])
                {
                    res.push_back(candidates[ind]);
                    topdown(candidates, ind + 1, target - candidates[ind], ans, res);
                    res.pop_back();
                }
            }
        }
    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector < int>> ans;
        vector<int> res;
        topdown(candidates, 0, target, ans, res);
        return ans;
    }
};