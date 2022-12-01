class Solution
{
    public:
        int countVovel(string s)
        {
            int cnt = 0;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == 'o'
                    or s[i] == 'e'
                    or s[i] == 'i'
                    or s[i] == 'a'
                    or s[i] == 'u')
                    cnt++;
            }
            return cnt;
        }
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        // cout<<s.substr(0,n/2) <<"  "<<s.substr(n/2,n) ;
        int a = countVovel(s.substr(0,n / 2));
        int b = countVovel(s.substr(n / 2, n));
        return (a == b);
    }
};