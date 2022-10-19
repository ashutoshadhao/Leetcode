class comp
{
    public : 
  bool operator()( pair<int,string> &a , pair<int,string> &b ){
      if( a.first == b.first )
            return a.second < b.second ;
      return a.first > b.first ;
  }  
};
class Solution
{
    public:

        vector<string> topKFrequent(vector<string> &words, int k)
        {
            unordered_map<string, int> mp;
            for (auto it: words)
            {
                mp[it]++;
            }
            priority_queue<pair<int, string>, vector< pair<int, string>>, comp> minHeap ;
            for (auto it: mp)
            {
                minHeap.push({ it.second, it.first });
                if (minHeap.size() > k)
                {
                    minHeap.pop();
                }
            }
            vector<string> ans(k);
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