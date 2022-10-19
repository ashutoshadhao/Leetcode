class comp
{
    public:
        bool operator()(pair<int, int> &a, pair<int, int> b)
        {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
};
class Solution
{
    public:

        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, comp> minHeap;
            unordered_map<int, int> mp;
            for (auto it: nums) mp[it]++;
            for (auto it: mp)
            {
                minHeap.push(make_pair(it.second, it.first));
                if (minHeap.size() > k)
                {
                    minHeap.pop();
                }
            }
            vector<int> ans(k);
            int index = k - 1;
            while (!minHeap.empty())
            {
                auto top = minHeap.top();
                minHeap.pop();
                ans[index] = top.second;
                index--;
            }
            return ans;
        }
};