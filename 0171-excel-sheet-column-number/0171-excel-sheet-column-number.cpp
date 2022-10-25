class Solution
{
    public:
        int titleToNumber(string columnTitle)
        {
            int n = columnTitle.size();
            int cnt = columnTitle[n - 1] - 'A' + 1;
            long long int level = 26 ;
            for (int i = n - 2; i >= 0; i--)
            {
                cnt += level *(columnTitle[i] - 'A' + 1);
                level *= 26 ;
            }
            return cnt;
        }
};