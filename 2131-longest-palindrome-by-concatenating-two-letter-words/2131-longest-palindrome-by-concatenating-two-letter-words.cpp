class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {
            map<string, int> mp;
            for (auto it: words)
            {
                mp[it]++;
            }
            int len = 0;
            bool flag = true;
            for (auto it: mp)
            {
                string temp;
                temp.push_back(it.first[1]);
                temp.push_back(it.first[0]);
                if (temp == it.first)
                {
                    len += it.second / 2;
                    if (it.second % 2) flag = false;
                }
                else if (mp.count(temp) )
                {
                    len += min(it.second,mp[temp]);
                    mp.erase(temp); 
                }
            }
            len = len * 4 ;
            if(flag == false ) len+=2 ;
            return len;
        }
};