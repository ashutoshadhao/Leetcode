class Solution
{
    public:
        string reorganizeString(string s)
        {
            priority_queue<pair<int, char>> maxHeap;
            string temp = "";
            vector<int> mp(26, 0);
            for (int i = 0; i < s.size(); i++)
            {
                mp[s[i] - 'a']++;
            }
            for (auto it: s)
            {
                if (mp[it - 'a'] != 0)
                {
                    maxHeap.push({ mp[it - 'a'],
                        it });
                    mp[it - 'a'] = 0;
                }
            }
            while (maxHeap.size() > 1)
            {
                auto top1 = maxHeap.top();
                maxHeap.pop();
                auto top2 = maxHeap.top();
                maxHeap.pop();

                temp += top1.second;
                temp += top2.second;

                top1.first--;
                top2.first--;

                if (top1.first > 0) maxHeap.push(top1);
                if (top2.first > 0) maxHeap.push(top2);
            }
            if (maxHeap.size() == 1)
            {
                if (maxHeap.top().first > 1)
                {
                    return "";
                }
                else
                    temp += maxHeap.top().second;
            }
            return temp;
        }
};