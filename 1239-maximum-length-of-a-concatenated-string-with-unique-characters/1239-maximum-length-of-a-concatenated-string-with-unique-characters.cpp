class Solution
{
    public:
        int topdown(vector<string> &arr, string s, int i)
        {
            if (i < 0)
            {
                // cout<<"'"<<s<<"'"<<endl;
                return s.size();
            }
            bool flag = true;
            vector<int> mp(26,0);
            for (int j = 0; j < arr[i].size(); j++)
            {
                mp[arr[i][j] - 'a']++;
                if (mp[arr[i][j] - 'a'] == 2)
                {
                    flag = false;
                    break;
                }
            }
            for (int j = 0; j < s.size(); j++)
            {
                mp[s[j] - 'a']++;
                if (mp[s[j] - 'a'] == 2)
                {
                    flag = false;
                    break;
                }
            }
            int nonTake = INT_MIN;
            if (flag == false)
            {
               nonTake = topdown(arr, s, i - 1);
                return nonTake ;
            }
            int take = topdown(arr, s + arr[i] , i - 1);
            nonTake = topdown(arr, s, i - 1);
            
            
            return max(take,nonTake);
        }
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        return topdown(arr, "", n - 1);
    }
};