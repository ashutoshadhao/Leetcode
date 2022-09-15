class Solution
{
    public:
        vector<int> findOriginalArray(vector<int> &changed)
        {
            int n = changed.size();
            if (n % 2 == 1) return {};
            unordered_map<int, int> mp;
            for (auto it: changed) mp[it]++;
            sort(changed.begin(), changed.end());
            vector<int> ans;
            for (auto it: changed)
            {
                if (mp[it *2] > 0 and mp[it] > 0 )
                {
                    if (it == 0 and mp[it *2] < 2) break;
                    ans.push_back(it);
                    mp[it]--;
                    mp[it *2]--;
                   	// cout<< mp[it *2 ]<<end;
                }
            }
            for (auto it: changed)
            {
                if (mp[it] > 0)
                {
                    return {};
                }
            }

            return ans;
        }
};