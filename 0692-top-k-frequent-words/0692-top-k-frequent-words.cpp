class Solution
{
    public:
    static bool comp( pair<int,string> a , pair<int,string> b )
    {
        if( a.first == b.first )
            return a.second < b.second ;
        return a.first > b.first ;
    }
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            unordered_map<string, int> mp;
            for (auto it: words)
            {
                mp[it]++;
            }
            vector<pair<int, string>> vec;
            for (auto it: mp)
            {
                vec.push_back(make_pair(it.second, it.first));
            }
            sort(vec.begin(), vec.end(), comp);
            vector<string> ans;
            for (int i = 0; i < k; i++)
            {
                ans.push_back(vec[i].second);
            }
            
            return ans;
        }
};